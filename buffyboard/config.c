/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#include "config.h"

#include "../shared/config.h"
#include "../shared/log.h"
#include "../squeek2lvgl/sq2lv.h"

#include "lvgl/lvgl.h"

#include <ini.h>
#include <stdlib.h>
#include <string.h>


/**
 * Static prototypes
 */

/**
 * Handle parsing events from INIH.
 *
 * @param user_data pointer to user data
 * @param section current section name
 * @param key option key
 * @param value option value
 * @return 0 on error, non-0 otherwise
 */
static int parsing_handler(void* user_data, const char* section, const char* key, const char* value);


/**
 * Static functions
 */

static int parsing_handler(void* user_data, const char* section, const char* key, const char* value) {
    bb_config_opts *opts = (bb_config_opts *)user_data;

    if (strcmp(section, "theme") == 0) {
        if (strcmp(key, "default") == 0) {
            bbx_themes_theme_id_t id = bbx_themes_find_theme_with_name(value);
            if (id != BBX_THEMES_THEME_NONE) {
                opts->theme.default_id = id;
                return 1;
            }
        }
    } else if (strcmp(section, "input") == 0) {
        if (strcmp(key, "pointer") == 0) {
            if (bbx_config_parse_bool(value, &(opts->input.pointer))) {
                return 1;
            }
        } else if (strcmp(key, "touchscreen") == 0) {
            if (bbx_config_parse_bool(value, &(opts->input.touchscreen))) {
                return 1;
            }
        }
    } else if (strcmp(section, "quirks") == 0) {
        if (strcmp(key, "fbdev_force_refresh") == 0) {
            if (bbx_config_parse_bool(value, &(opts->quirks.fbdev_force_refresh))) {
                return 1;
            }
        }
    }

    bbx_log(BBX_LOG_LEVEL_ERROR, "Ignoring invalid config value \"%s\" for key \"%s\" in section \"%s\"", value, key, section);
    return 1; /* Return 1 (true) so that we can use the return value of ini_parse exclusively for file-level errors (e.g. file not found) */
}


/**
 * Public functions
 */

void bb_config_init_opts(bb_config_opts *opts) {
    opts->theme.default_id = BBX_THEMES_THEME_BREEZY_DARK;
    opts->input.pointer = true;
    opts->input.touchscreen = true;
    opts->quirks.fbdev_force_refresh = false;
}

void bb_config_parse_directory(const char *path, bb_config_opts *opts) {
    /* Find files in directory */
    char **found = NULL;
    int num_found = 0;
    bbx_config_find_files(path, &found, &num_found);

    /* Sort and parse files */
    qsort(found, num_found, sizeof(char *), bbx_config_compare_strings);
    bb_config_parse_files((const char **)found, num_found, opts);

    /* Free memory */
    for (int i = 0; i < num_found; ++i) {
        free(found[i]);
    }
    free(found);
}

void bb_config_parse_files(const char **files, int num_files, bb_config_opts *opts) {
    for (int i = 0; i < num_files; ++i) {
        bb_config_parse_file(files[i], opts);
    }
}

void bb_config_parse_file(const char *path, bb_config_opts *opts) {
    bbx_log(BBX_LOG_LEVEL_VERBOSE, "Parsing config file %s", path);
    if (ini_parse(path, parsing_handler, opts) != 0) {
        bbx_log(BBX_LOG_LEVEL_ERROR, "Ignoring invalid config file %s", path);
    }
}
