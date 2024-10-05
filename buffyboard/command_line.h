/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#ifndef BB_COMMAND_LINE_H
#define BB_COMMAND_LINE_H

#include "lvgl/lvgl.h"

/**
 * Options parsed from command line arguments
 */
typedef struct {
    /* Number of config files */
    int num_config_files;
    /* Paths of config file */
    const char **config_files;
    /* Horizontal display resolution */
    int hor_res;
    /* Vertical display resolution */
    int ver_res;
    /* Horizontal display offset */
    int x_offset;
    /* Vertical display offset */
    int y_offset;
    /* DPI */
    int dpi;
    /* Display rotation */
    lv_display_rotation_t rotation;
    /* Verbose mode. If true, provide more detailed logging output on STDERR. */
    bool verbose;
} bb_cli_opts;

/**
 * Parse command line arguments and exit on failure.
 *
 * @param argc number of provided command line arguments
 * @param argv arguments as an array of strings
 * @param opts pointer for writing the parsed options into
 */
void bb_cli_parse_opts(int argc, char *argv[], bb_cli_opts *opts);

#endif /* BB_COMMAND_LINE_H */
