/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#include "buffyboard.h"
#include "command_line.h"
#include "config.h"
#include "sq2lv_layouts.h"
#include "terminal.h"
#include "uinput_device.h"

#include "lvgl/lvgl.h"

#include "../shared/indev.h"
#include "../shared/log.h"
#include "../shared/theme.h"
#include "../shared/themes.h"
#include "../squeek2lvgl/sq2lv.h"

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/time.h>


/**
 * Static variables
 */

bb_cli_opts cli_opts;
bb_config_opts conf_opts;

static bool resize_terminals = false;
static lv_obj_t *keyboard = NULL;


/**
 * Static prototypes
 */

/**
 * Compute the denominator of the keyboard height factor. The keyboard height is calculated
 * by dividing the display height by the denominator.
 *
 * @param width display width
 * @param height display height
 * @return denominator
 */
static int keyboard_height_denominator(lv_coord_t width, lv_coord_t height);

/**
 * Handle termination signals sent to the process.
 *
 * @param signum the signal's number
 */
static void sigaction_handler(int signum);

/**
 * Callback for the terminal resizing timer.
 *
 * @param timer the timer object
 */
static void terminal_resize_timer_cb(lv_timer_t *timer);

/**
 * Handle LV_EVENT_VALUE_CHANGED events from the keyboard widget.
 * 
 * @param event the event object
 */
static void keyboard_value_changed_cb(lv_event_t *event);

/**
 * Emit key down and up events for a key.
 *
 * @param btn_id button index corresponding to the key
 * @param key_down true if a key down event should be emitted
 * @param key_up true if a key up event should be emitted
 */
static void emit_key_events(uint16_t btn_id, bool key_down, bool key_up);

/**
 * Release any previously pressed modifier keys.
 */
static void pop_checked_modifier_keys(void);


/**
 * Static functions
 */

static int keyboard_height_denominator(lv_coord_t width, lv_coord_t height) {
    return (height > width) ? 3 : 2;
}

static void sigaction_handler(int signum) {
    if (resize_terminals) {
        bb_terminal_reset_all();
    }
    exit(0);
}

static void terminal_resize_timer_cb(lv_timer_t *timer) {
    if (resize_terminals) {
        bb_terminal_shrink_current();
    }
}

static void keyboard_value_changed_cb(lv_event_t *event) {
    lv_obj_t *kb = lv_event_get_target(event);

    uint16_t btn_id = lv_buttonmatrix_get_selected_button(kb);
    if (btn_id == LV_BUTTONMATRIX_BUTTON_NONE) {
        return;
    }

    if (sq2lv_is_layer_switcher(kb, btn_id)) {
        pop_checked_modifier_keys();
        sq2lv_switch_layer(kb, btn_id);
        return;
    }

    /* Note that the LV_BUTTONMATRIX_CTRL_CHECKED logic is inverted because LV_KEYBOARD_CTRL_BTN_FLAGS already
     * contains LV_BUTTONMATRIX_CTRL_CHECKED. As a result, pressing e.g. CTRL will _un_check the key. To account
     * for this, we invert the meaning of "checked" here and elsewhere in the code. */

    bool is_modifier = sq2lv_is_modifier(keyboard, btn_id);
    bool is_checked = !lv_buttonmatrix_has_button_ctrl(keyboard, btn_id, LV_BUTTONMATRIX_CTRL_CHECKED);

    /* Emit key events. Suppress key up events for modifiers unless they were unchecked. For checked modifiers
     * the key up events are sent with the next non-modifier key press. */
    emit_key_events(btn_id, true, !is_modifier || !is_checked);

    /* Pop any previously checked modifiers when a non-modifier key was pressed */
    if (!is_modifier) {
        pop_checked_modifier_keys();
    }
}

static void emit_key_events(uint16_t btn_id, bool key_down, bool key_up) {
    int num_scancodes = 0;
    const int *scancodes = sq2lv_get_scancodes(keyboard, btn_id, &num_scancodes);

    if (key_down) {
        /* Emit key down events in forward order */
        for (int i = 0; i < num_scancodes; ++i) {
            bb_uinput_device_emit_key_down(scancodes[i]);
        }
    }

    if (key_up) {
        /* Emit key up events in backward order */
        for (int i = num_scancodes - 1; i >= 0; --i) {
            bb_uinput_device_emit_key_up(scancodes[i]);
        }
    }
}

static void pop_checked_modifier_keys(void) {
    int num_modifiers = 0;
    const int *modifier_idxs = sq2lv_get_modifier_indexes(keyboard, &num_modifiers);

    for (int i = 0; i < num_modifiers; ++i) {
        if (!lv_buttonmatrix_has_button_ctrl(keyboard, modifier_idxs[i], LV_BUTTONMATRIX_CTRL_CHECKED)) {
            emit_key_events(modifier_idxs[i], false, true);
            lv_buttonmatrix_set_button_ctrl(keyboard, modifier_idxs[i], LV_BUTTONMATRIX_CTRL_CHECKED);
        }
    }
}


/**
 * Main
 */

int main(int argc, char *argv[]) {
    /* Parse command line options */
    bb_cli_parse_opts(argc, argv, &cli_opts);

    /* Set up log level */
    if (cli_opts.verbose) {
        bbx_log_set_level(BBX_LOG_LEVEL_VERBOSE);
    }

    /* Parse config files */
    bb_config_init_opts(&conf_opts);
    bb_config_parse_file("/usr/share/buffyboard/buffyboard.conf", &conf_opts);
    bb_config_parse_directory("/usr/share/buffyboard/buffyboard.conf.d", &conf_opts);
    bb_config_parse_file("/etc/buffyboard.conf", &conf_opts);
    bb_config_parse_directory("/etc/buffyboard.conf.d", &conf_opts);
    bb_config_parse_files(cli_opts.config_files, cli_opts.num_config_files, &conf_opts);

    /* Prepare for terminal resizing and reset */
    resize_terminals = bb_terminal_init(2.0f / 3.0f);
    if (resize_terminals) {
        /* Clean up on termination */
        struct sigaction action;
        lv_memset(&action, 0, sizeof(action));
        action.sa_handler = sigaction_handler;
        sigaction(SIGINT, &action, NULL);
        sigaction(SIGTERM, &action, NULL);

        /* Resize current terminal */
        bb_terminal_shrink_current();
    }

    /* Set up uinput device */
    if (!bb_uinput_device_init(sq2lv_unique_scancodes, sq2lv_num_unique_scancodes)) {
        return 1;
    }

    /* Initialise LVGL and set up logging callback */
    lv_init();
    lv_log_register_print_cb(bbx_log_print_cb);

    /* Initialise display */
    lv_display_t *disp = lv_linux_fbdev_create();
    lv_linux_fbdev_set_file(disp, "/dev/fb0");
    if (conf_opts.quirks.fbdev_force_refresh) {
        lv_linux_fbdev_set_force_refresh(disp, true);
    }

    /* Override display properties with command line options if necessary */
    lv_display_set_offset(disp, cli_opts.x_offset, cli_opts.y_offset);
    if (cli_opts.hor_res > 0 || cli_opts.ver_res > 0) {
        lv_display_set_physical_resolution(disp, lv_disp_get_hor_res(disp), lv_disp_get_ver_res(disp));
        lv_display_set_resolution(disp, cli_opts.hor_res, cli_opts.ver_res);
    }
    if (cli_opts.dpi > 0) {
        lv_display_set_dpi(disp, cli_opts.dpi);
    }

    /* Set up display rotation */
    int32_t hor_res_phys = lv_display_get_horizontal_resolution(disp);
    int32_t ver_res_phys = lv_display_get_vertical_resolution(disp);
    lv_display_set_physical_resolution(disp, hor_res_phys, ver_res_phys);
    lv_display_set_rotation(disp, cli_opts.rotation);
    switch (cli_opts.rotation) {
        case LV_DISPLAY_ROTATION_0:
        case LV_DISPLAY_ROTATION_180: {
            lv_coord_t denom = keyboard_height_denominator(hor_res_phys, ver_res_phys);
            lv_display_set_resolution(disp, hor_res_phys, ver_res_phys / denom);
            lv_display_set_offset(disp, 0, (cli_opts.rotation == LV_DISPLAY_ROTATION_0) ? (denom - 1) * ver_res_phys / denom : 0);
            break;
        }
        case LV_DISPLAY_ROTATION_90:
        case LV_DISPLAY_ROTATION_270: {
            lv_coord_t denom = keyboard_height_denominator(ver_res_phys, hor_res_phys);
            lv_display_set_resolution(disp, hor_res_phys / denom, ver_res_phys);
            lv_display_set_offset(disp, 0, (cli_opts.rotation == LV_DISPLAY_ROTATION_90) ? (denom - 1) * hor_res_phys / denom : 0);
            break;
        }
    }

    /* Start input device monitor and auto-connect available devices */
    bbx_indev_start_monitor_and_autoconnect(false, conf_opts.input.pointer, conf_opts.input.touchscreen);

    /* Initialise theme */
    bbx_theme_apply(bbx_themes_themes[conf_opts.theme.default_id]);

    /* Add keyboard */
    keyboard = lv_keyboard_create(lv_scr_act());
    uint32_t num_keyboard_events = lv_obj_get_event_count(keyboard);
    for(uint32_t i = 0; i < num_keyboard_events; ++i) {
        if(lv_event_dsc_get_cb(lv_obj_get_event_dsc(keyboard, i)) == lv_keyboard_def_event_cb) {
            lv_obj_remove_event(keyboard, i);
            break;
        }
    }
    lv_obj_add_event_cb(keyboard, keyboard_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_pos(keyboard, 0, 0);
    lv_obj_set_size(keyboard, LV_HOR_RES, LV_VER_RES);
    bbx_theme_prepare_keyboard(keyboard);

    /* Apply default keyboard layout */
    sq2lv_switch_layout(keyboard, SQ2LV_LAYOUT_TERMINAL_US);

    /* Start timer for periodically resizing terminals */
    lv_timer_create(terminal_resize_timer_cb, 1000,  NULL);

    /* Periodically run timer / task handler */
    while(1) {
        lv_timer_periodic_handler();
    }

    return 0;
}


/**
 * Tick generation
 */

/**
 * Generate tick for LVGL.
 * 
 * @return tick in ms
 */
uint32_t bb_get_tick(void) {
    static uint64_t start_ms = 0;
    if (start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
