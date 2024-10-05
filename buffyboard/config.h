/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#ifndef BB_CONFIG_H
#define BB_CONFIG_H

#include "../shared/themes.h"

#include "sq2lv_layouts.h"

/**
 * Options related to the theme
 */
typedef struct {
    /* Default theme */
    bbx_themes_theme_id_t default_id;
} bb_config_opts_theme;

/**
 * Options related to input devices
 */
typedef struct {
    /* If true and a pointer device is connected, use it for input */
    bool pointer;
    /* If true and a touchscreen device is connected, use it for input */
    bool touchscreen;
} bb_config_opts_input;

/**
 * (Normally unneeded) quirky options
 */
typedef struct {
    /* If true and using the framebuffer backend, force a refresh on every draw operation */
    bool fbdev_force_refresh;
} bb_config_opts_quirks;

/**
 * Options parsed from config file(s)
 */
typedef struct {
    /* Options related to the theme */
    bb_config_opts_theme theme;
    /* Options related to input devices */
    bb_config_opts_input input;
    /* Options related to (normally unneeded) quirks */
    bb_config_opts_quirks quirks;
} bb_config_opts;

/**
 * Initialise a config options struct with default values.
 * 
 * @param opts pointer to the options struct
 */
void bb_config_init_opts(bb_config_opts *opts);

/**
 * Find configuration files in a directory and parse them in alphabetic order.
 * 
 * @param path directory path
 * @param opts pointer for writing the parsed options into
 */
void bb_config_parse_directory(const char *path, bb_config_opts *opts);

/**
 * Parse one or more configuration files.
 * 
 * @param files paths to configuration files
 * @param num_files number of configuration files
 * @param opts pointer for writing the parsed options into
 */
void bb_config_parse_files(const char **files, int num_files, bb_config_opts *opts);

/**
 * Parse a configuration file.
 * 
 * @param path path to configuration file
 * @param opts pointer for writing the parsed options into
 */
void bb_config_parse_file(const char *path, bb_config_opts *opts);

#endif /* BB_CONFIG_H */
