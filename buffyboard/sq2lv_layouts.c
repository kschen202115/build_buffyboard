/**
 * Auto-generated with squeek2lvgl
 **/

#include "sq2lv_layouts.h"
#include "../squeek2lvgl/sq2lv.h"
#include <linux/input.h>

#define SQ2LV_SYMBOL_SHIFT "\xef\x8d\x9b"

/**
 * Layout: US English (Terminal) - generated from terminal/us
 **/

static const char * const name_terminal_us = "US English (Terminal)";
static const char * const short_name_terminal_us = "terminal/us";

/* Layer: Lowercase letters - generated from base */

static const int num_keys_lower_terminal_us = 38;

static const char * const keycaps_lower_terminal_us[] = { \
    "Ctrl", "Alt", LV_SYMBOL_UP, LV_SYMBOL_DOWN, LV_SYMBOL_LEFT, LV_SYMBOL_RIGHT, "\n", \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    SQ2LV_SYMBOL_SHIFT, "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "123", " ", ">_", LV_SYMBOL_OK, "" \
};

static const lv_buttonmatrix_ctrl_t attributes_lower_terminal_us[] = { \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, 7, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_lower_terminal_us = 2;

static const int modifier_idxs_lower_terminal_us[] = { \
    0, 1 \
};

static const int num_switchers_lower_terminal_us = 3;

static const int switcher_idxs_lower_terminal_us[] = { \
    25, 34, 36 \
};

static const int switcher_dests_lower_terminal_us[] = { \
    1, 2, 4 \
};

static const int num_scancodes_lower_terminal_us = 5;

static const int scancodes_lower_terminal_us[] = { \
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, \
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, \
    KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, \
    KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_BACKSPACE, \
    KEY_SPACE, KEY_ENTER \
};

static const int scancode_idxs_lower_terminal_us[] = { \
    0, 1, 2, 3, 4, 5, \
    6, 7, 8, 9, 10, 11, 12, 13, 14, 15, \
    16, 17, 18, 19, 20, 21, 22, 23, 24, \
    -1, 25, 26, 27, 28, 29, 30, 31, 32, \
    -1, 33, -1, 34 \
};

static const int scancode_nums_lower_terminal_us[] = { \
    1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, \
    0, 1, 1, 1, 1, 1, 1, 1, 1, \
    0, 1, 0, 1 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_terminal_us = 38;

static const char * const keycaps_upper_terminal_us[] = { \
    "Ctrl", "Alt", "PgUp", "PgDn", "Home", "End", "\n", \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    SQ2LV_SYMBOL_SHIFT, "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "123", " ", ">_", LV_SYMBOL_OK, "" \
};

static const lv_buttonmatrix_ctrl_t attributes_upper_terminal_us[] = { \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    SQ2LV_CTRL_MOD_ACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, 7, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_upper_terminal_us = 2;

static const int modifier_idxs_upper_terminal_us[] = { \
    0, 1 \
};

static const int num_switchers_upper_terminal_us = 3;

static const int switcher_idxs_upper_terminal_us[] = { \
    25, 34, 36 \
};

static const int switcher_dests_upper_terminal_us[] = { \
    0, 2, 4 \
};

static const int num_scancodes_upper_terminal_us = 5;

static const int scancodes_upper_terminal_us[] = { \
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_PAGEUP, KEY_PAGEDOWN, KEY_HOME, KEY_END, \
    KEY_LEFTSHIFT, KEY_Q, KEY_LEFTSHIFT, KEY_W, KEY_LEFTSHIFT, KEY_E, KEY_LEFTSHIFT, KEY_R, KEY_LEFTSHIFT, KEY_T, KEY_LEFTSHIFT, KEY_Y, KEY_LEFTSHIFT, KEY_U, KEY_LEFTSHIFT, KEY_I, KEY_LEFTSHIFT, KEY_O, KEY_LEFTSHIFT, KEY_P, \
    KEY_LEFTSHIFT, KEY_A, KEY_LEFTSHIFT, KEY_S, KEY_LEFTSHIFT, KEY_D, KEY_LEFTSHIFT, KEY_F, KEY_LEFTSHIFT, KEY_G, KEY_LEFTSHIFT, KEY_H, KEY_LEFTSHIFT, KEY_J, KEY_LEFTSHIFT, KEY_K, KEY_LEFTSHIFT, KEY_L, \
    KEY_LEFTSHIFT, KEY_Z, KEY_LEFTSHIFT, KEY_X, KEY_LEFTSHIFT, KEY_C, KEY_LEFTSHIFT, KEY_V, KEY_LEFTSHIFT, KEY_B, KEY_LEFTSHIFT, KEY_N, KEY_LEFTSHIFT, KEY_M, KEY_BACKSPACE, \
    KEY_SPACE, KEY_ENTER \
};

static const int scancode_idxs_upper_terminal_us[] = { \
    0, 1, 2, 3, 4, 5, \
    6, 8, 10, 12, 14, 16, 18, 20, 22, 24, \
    26, 28, 30, 32, 34, 36, 38, 40, 42, \
    -1, 44, 46, 48, 50, 52, 54, 56, 58, \
    -1, 59, -1, 60 \
};

static const int scancode_nums_upper_terminal_us[] = { \
    1, 1, 1, 1, 1, 1, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    0, 2, 2, 2, 2, 2, 2, 2, 1, \
    0, 1, 0, 1 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_terminal_us = 39;

static const char * const keycaps_numbers_terminal_us[] = { \
    "Ctrl", "Alt", LV_SYMBOL_UP, LV_SYMBOL_DOWN, LV_SYMBOL_LEFT, LV_SYMBOL_RIGHT, "\n", \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "*", "#", "$", "/", "&", "-", "_", "+", "(", ")", "\n", \
    "τ=\\", ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "ABC", " ", ".", LV_SYMBOL_OK, "" \
};

static const lv_buttonmatrix_ctrl_t attributes_numbers_terminal_us[] = { \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, 7, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_numbers_terminal_us = 2;

static const int modifier_idxs_numbers_terminal_us[] = { \
    0, 1 \
};

static const int num_switchers_numbers_terminal_us = 2;

static const int switcher_idxs_numbers_terminal_us[] = { \
    26, 35 \
};

static const int switcher_dests_numbers_terminal_us[] = { \
    3, 0 \
};

static const int num_scancodes_numbers_terminal_us = 5;

static const int scancodes_numbers_terminal_us[] = { \
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, \
    KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, \
    KEY_LEFTSHIFT, KEY_8, KEY_LEFTSHIFT, KEY_3, KEY_LEFTSHIFT, KEY_4, KEY_SLASH, KEY_LEFTSHIFT, KEY_7, KEY_MINUS, KEY_LEFTSHIFT, KEY_MINUS, KEY_LEFTSHIFT, KEY_EQUAL, KEY_LEFTSHIFT, KEY_9, KEY_LEFTSHIFT, KEY_0, \
    KEY_COMMA, KEY_LEFTSHIFT, KEY_APOSTROPHE, KEY_APOSTROPHE, KEY_LEFTSHIFT, KEY_SEMICOLON, KEY_SEMICOLON, KEY_LEFTSHIFT, KEY_1, KEY_LEFTSHIFT, KEY_SLASH, KEY_BACKSPACE, \
    KEY_SPACE, KEY_DOT, KEY_ENTER \
};

static const int scancode_idxs_numbers_terminal_us[] = { \
    0, 1, 2, 3, 4, 5, \
    6, 7, 8, 9, 10, 11, 12, 13, 14, 15, \
    16, 18, 20, 22, 23, 25, 26, 28, 30, 32, \
    -1, 34, 35, 37, 38, 40, 41, 43, 45, \
    -1, 46, 47, 48 \
};

static const int scancode_nums_numbers_terminal_us[] = { \
    1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    2, 2, 2, 1, 2, 1, 2, 2, 2, 2, \
    0, 1, 2, 1, 2, 1, 2, 2, 1, \
    0, 1, 1, 1 \
};

/* Layer: Symbols - generated from symbols */

static const int num_keys_symbols_terminal_us = 39;

static const char * const keycaps_symbols_terminal_us[] = { \
    "Ctrl", "Alt", LV_SYMBOL_UP, LV_SYMBOL_DOWN, LV_SYMBOL_LEFT, LV_SYMBOL_RIGHT, "\n", \
    "~", "`", "|", "·", "√", "π", "τ", "÷", "×", "¶", "\n", \
    "©", "®", "£", "€", "¥", "^", "°", "@", "{", "}", "\n", \
    "123", "\\", "%", "<", ">", "=", "[", "]", LV_SYMBOL_BACKSPACE, "\n", \
    "ABC", " ", ".", LV_SYMBOL_OK, "" \
};

static const lv_buttonmatrix_ctrl_t attributes_symbols_terminal_us[] = { \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, 7, LV_BUTTONMATRIX_CTRL_POPOVER | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_symbols_terminal_us = 2;

static const int modifier_idxs_symbols_terminal_us[] = { \
    0, 1 \
};

static const int num_switchers_symbols_terminal_us = 2;

static const int switcher_idxs_symbols_terminal_us[] = { \
    26, 35 \
};

static const int switcher_dests_symbols_terminal_us[] = { \
    2, 0 \
};

static const int num_scancodes_symbols_terminal_us = 5;

static const int scancodes_symbols_terminal_us[] = { \
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, \
    KEY_LEFTSHIFT, KEY_GRAVE, KEY_GRAVE, KEY_LEFTSHIFT, KEY_BACKSLASH, \
    KEY_LEFTSHIFT, KEY_6, KEY_LEFTSHIFT, KEY_2, KEY_LEFTSHIFT, KEY_LEFTBRACE, KEY_LEFTSHIFT, KEY_RIGHTBRACE, \
    KEY_BACKSLASH, KEY_LEFTSHIFT, KEY_5, KEY_LEFTSHIFT, KEY_COMMA, KEY_LEFTSHIFT, KEY_DOT, KEY_EQUAL, KEY_LEFTBRACE, KEY_RIGHTBRACE, KEY_BACKSPACE, \
    KEY_SPACE, KEY_DOT, KEY_ENTER \
};

static const int scancode_idxs_symbols_terminal_us[] = { \
    0, 1, 2, 3, 4, 5, \
    6, 8, 9, -1, -1, -1, -1, -1, -1, -1, \
    -1, -1, -1, -1, -1, 11, -1, 13, 15, 17, \
    -1, 19, 20, 22, 24, 26, 27, 28, 29, \
    -1, 30, 31, 32 \
};

static const int scancode_nums_symbols_terminal_us[] = { \
    1, 1, 1, 1, 1, 1, \
    2, 1, 2, 0, 0, 0, 0, 0, 0, 0, \
    0, 0, 0, 0, 0, 2, 0, 2, 2, 2, \
    0, 1, 2, 2, 2, 1, 1, 1, 1, \
    0, 1, 1, 1 \
};

/* Layer: Actions - generated from actions */

static const int num_keys_actions_terminal_us = 30;

static const char * const keycaps_actions_terminal_us[] = { \
    "Ctrl", "Alt", "PgUp", "PgDn", "Home", "End", "\n", \
    "F1", "F2", "F3", "F4", "F5", "F6", "\n", \
    "F7", "F8", "F9", "F10", "F11", "F12", "\n", \
    "Esc", "Tab", "Pause", "Insert", LV_SYMBOL_UP, "Del", "\n", \
    "ABC", "Menu", "Break", LV_SYMBOL_LEFT, LV_SYMBOL_DOWN, LV_SYMBOL_RIGHT, "" \
};

static const lv_buttonmatrix_ctrl_t attributes_actions_terminal_us[] = { \
    SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_MOD_INACTIVE | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | LV_BUTTONMATRIX_CTRL_NO_REPEAT | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_actions_terminal_us = 2;

static const int modifier_idxs_actions_terminal_us[] = { \
    0, 1 \
};

static const int num_switchers_actions_terminal_us = 1;

static const int switcher_idxs_actions_terminal_us[] = { \
    24 \
};

static const int switcher_dests_actions_terminal_us[] = { \
    0 \
};

static const int num_scancodes_actions_terminal_us = 5;

static const int scancodes_actions_terminal_us[] = { \
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_PAGEUP, KEY_PAGEDOWN, KEY_HOME, KEY_END, \
    KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, \
    KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, \
    KEY_ESC, KEY_TAB, KEY_PAUSE, KEY_INSERT, KEY_UP, KEY_DELETE, \
    KEY_COMPOSE, KEY_BREAK, KEY_LEFT, KEY_DOWN, KEY_RIGHT \
};

static const int scancode_idxs_actions_terminal_us[] = { \
    0, 1, 2, 3, 4, 5, \
    6, 7, 8, 9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
    18, 19, 20, 21, 22, 23, \
    -1, 24, 25, 26, 27, 28 \
};

static const int scancode_nums_actions_terminal_us[] = { \
    1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, \
    0, 1, 1, 1, 1, 1 \
};

/* Layer array */

static const int num_layers_terminal_us = 5;

static const sq2lv_layer_t layers_terminal_us[] = {
    {
        .num_keys = num_keys_lower_terminal_us,
        .keycaps = keycaps_lower_terminal_us,
        .attributes = attributes_lower_terminal_us,
        .num_modifiers = num_modifiers_lower_terminal_us,
        .modifier_idxs = modifier_idxs_lower_terminal_us,
        .num_switchers = num_switchers_lower_terminal_us,
        .switcher_idxs = switcher_idxs_lower_terminal_us,
        .switcher_dests = switcher_dests_lower_terminal_us,
        .num_scancodes = num_scancodes_lower_terminal_us,
        .scancodes = scancodes_lower_terminal_us,
        .scancode_idxs = scancode_idxs_lower_terminal_us,
        .scancode_nums = scancode_nums_lower_terminal_us
    },
    {
        .num_keys = num_keys_upper_terminal_us,
        .keycaps = keycaps_upper_terminal_us,
        .attributes = attributes_upper_terminal_us,
        .num_modifiers = num_modifiers_upper_terminal_us,
        .modifier_idxs = modifier_idxs_upper_terminal_us,
        .num_switchers = num_switchers_upper_terminal_us,
        .switcher_idxs = switcher_idxs_upper_terminal_us,
        .switcher_dests = switcher_dests_upper_terminal_us,
        .num_scancodes = num_scancodes_upper_terminal_us,
        .scancodes = scancodes_upper_terminal_us,
        .scancode_idxs = scancode_idxs_upper_terminal_us,
        .scancode_nums = scancode_nums_upper_terminal_us
    },
    {
        .num_keys = num_keys_numbers_terminal_us,
        .keycaps = keycaps_numbers_terminal_us,
        .attributes = attributes_numbers_terminal_us,
        .num_modifiers = num_modifiers_numbers_terminal_us,
        .modifier_idxs = modifier_idxs_numbers_terminal_us,
        .num_switchers = num_switchers_numbers_terminal_us,
        .switcher_idxs = switcher_idxs_numbers_terminal_us,
        .switcher_dests = switcher_dests_numbers_terminal_us,
        .num_scancodes = num_scancodes_numbers_terminal_us,
        .scancodes = scancodes_numbers_terminal_us,
        .scancode_idxs = scancode_idxs_numbers_terminal_us,
        .scancode_nums = scancode_nums_numbers_terminal_us
    },
    {
        .num_keys = num_keys_symbols_terminal_us,
        .keycaps = keycaps_symbols_terminal_us,
        .attributes = attributes_symbols_terminal_us,
        .num_modifiers = num_modifiers_symbols_terminal_us,
        .modifier_idxs = modifier_idxs_symbols_terminal_us,
        .num_switchers = num_switchers_symbols_terminal_us,
        .switcher_idxs = switcher_idxs_symbols_terminal_us,
        .switcher_dests = switcher_dests_symbols_terminal_us,
        .num_scancodes = num_scancodes_symbols_terminal_us,
        .scancodes = scancodes_symbols_terminal_us,
        .scancode_idxs = scancode_idxs_symbols_terminal_us,
        .scancode_nums = scancode_nums_symbols_terminal_us
    },
    {
        .num_keys = num_keys_actions_terminal_us,
        .keycaps = keycaps_actions_terminal_us,
        .attributes = attributes_actions_terminal_us,
        .num_modifiers = num_modifiers_actions_terminal_us,
        .modifier_idxs = modifier_idxs_actions_terminal_us,
        .num_switchers = num_switchers_actions_terminal_us,
        .switcher_idxs = switcher_idxs_actions_terminal_us,
        .switcher_dests = switcher_dests_actions_terminal_us,
        .num_scancodes = num_scancodes_actions_terminal_us,
        .scancodes = scancodes_actions_terminal_us,
        .scancode_idxs = scancode_idxs_actions_terminal_us,
        .scancode_nums = scancode_nums_actions_terminal_us
    }
};

/**
 * Public interface
 **/

const int sq2lv_num_layouts = 1;

const sq2lv_layout_t sq2lv_layouts[] = {
    /* US English (Terminal) */
    {
        .name = name_terminal_us,
        .short_name = short_name_terminal_us,
        .num_layers = num_layers_terminal_us,
        .layers = layers_terminal_us
    }
};

const char * const sq2lv_layout_names =
    "US English (Terminal)";

const char * const sq2lv_layout_short_names =
    "terminal/us";

const int sq2lv_num_unique_scancodes = 80;

const int sq2lv_unique_scancodes[] = {
    KEY_LEFTCTRL, KEY_LEFTALT, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_Q, KEY_W, KEY_E, KEY_R,
    KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_A, KEY_S, KEY_D, KEY_F,
    KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B,
    KEY_N, KEY_M, KEY_BACKSPACE, KEY_SPACE, KEY_ENTER, KEY_PAGEUP, KEY_PAGEDOWN, KEY_HOME, KEY_END, KEY_LEFTSHIFT,
    KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
    KEY_SLASH, KEY_MINUS, KEY_EQUAL, KEY_COMMA, KEY_APOSTROPHE, KEY_SEMICOLON, KEY_DOT, KEY_GRAVE, KEY_BACKSLASH, KEY_LEFTBRACE,
    KEY_RIGHTBRACE, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9,
    KEY_F10, KEY_F11, KEY_F12, KEY_ESC, KEY_TAB, KEY_PAUSE, KEY_INSERT, KEY_DELETE, KEY_COMPOSE, KEY_BREAK
};
