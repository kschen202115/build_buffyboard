/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#include "command_line.h"

#include "buffyboard.h"

#include "../shared/log.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Static prototypes
 */

/**
 * Initialise a command line options struct with default values and exit on failure.
 *
 * @param opts pointer to the options struct
 */
static void init_opts(bb_cli_opts *opts);

/**
 * Output usage instructions.
 */
static void print_usage();


/**
 * Static functions
 */

static void init_opts(bb_cli_opts *opts) {
    opts->num_config_files = 0;
    opts->config_files = NULL;
    opts->hor_res = -1;
    opts->ver_res = -1;
    opts->x_offset = 0;
    opts->y_offset = 0;
    opts->dpi = 0;
    opts->rotation = LV_DISPLAY_ROTATION_0;
    opts->verbose = false;
}

static void print_usage() {
    fprintf(stderr,
        /*-------------------------------- 78 CHARS --------------------------------*/
        "Usage: buffyboard [OPTION]\n"
        "\n"
        "Mandatory arguments to long options are mandatory for short options too.\n"
        "  -C, --config-override     Path to a config override file. Can be supplied\n"
        "                            multiple times. Config files are merged in the\n"
        "                            following order:\n"
        "                            * /usr/share/buffyboard/buffyboard.conf\n"
        "                            * /usr/share/buffyboard/buffyboard.conf.d/* (alphabetically)\n"
        "                            * /etc/buffyboard.conf\n"
        "                            * /etc/buffyboard.conf.d/* (alphabetically)\n"
        "                            * Override files (in supplied order)\n"
        "  -g, --geometry=NxM[@X,Y]  Force a display size of N horizontal times M\n"
        "                            vertical pixels, offset horizontally by X\n"
        "                            pixels and vertically by Y pixels\n"
        "  -d  --dpi=N               Override the display's DPI value\n"
        "  -r, --rotate=[0-3]        Rotate the UI to the given orientation. The\n"
        "                            values match the ones provided by the kernel in\n"
        "                            /sys/class/graphics/fbcon/rotate.\n"
        "                            * 0 - normal orientation (0 degree)\n"
        "                            * 1 - clockwise orientation (90 degrees)\n"
        "                            * 2 - upside down orientation (180 degrees)\n"
        "                            * 3 - counterclockwise orientation (270 degrees)\n"
        "  -h, --help                Print this message and exit\n"
        "  -v, --verbose             Enable more detailed logging output on STDERR\n"
        "  -V, --version             Print the buffyboard version and exit\n");
        /*-------------------------------- 78 CHARS --------------------------------*/
}


/**
 * Public functions
 */

void bb_cli_parse_opts(int argc, char *argv[], bb_cli_opts *opts) {
    init_opts(opts);

    struct option long_opts[] = {
        { "config-override", required_argument, NULL, 'C' },
        { "geometry",        required_argument, NULL, 'g' },
        { "dpi",             required_argument, NULL, 'd' },
        { "rotate",          required_argument, NULL, 'r' },
        { "help",            no_argument,       NULL, 'h' },
        { "verbose",         no_argument,       NULL, 'v' },
        { "version",         no_argument,       NULL, 'V' },
        { NULL, 0, NULL, 0 }
    };

    int opt, index = 0;

    while ((opt = getopt_long(argc, argv, "C:g:d:r:hvV", long_opts, &index)) != -1) {
        switch (opt) {
        case 'C':
            opts->config_files = realloc(opts->config_files, (opts->num_config_files + 1) * sizeof(char *));
            if (!opts->config_files) {
                bbx_log(BBX_LOG_LEVEL_ERROR, "Could not allocate memory for config file paths");
                exit(EXIT_FAILURE);
            }
            opts->config_files[opts->num_config_files] = optarg;
            opts->num_config_files++;
            break;
        case 'g':
            if (sscanf(optarg, "%ix%i@%i,%i", &(opts->hor_res), &(opts->ver_res), &(opts->x_offset), &(opts->y_offset)) != 4) {
                if (sscanf(optarg, "%ix%i", &(opts->hor_res), &(opts->ver_res)) != 2) {
                    bbx_log(BBX_LOG_LEVEL_ERROR, "Invalid geometry argument \"%s\"\n", optarg);
                    exit(EXIT_FAILURE);
                }
            }
            break;
        case 'd':
            if (sscanf(optarg, "%i", &(opts->dpi)) != 1) {
                bbx_log(BBX_LOG_LEVEL_ERROR, "Invalid dpi argument \"%s\"\n", optarg);
                exit(EXIT_FAILURE);
            }
            break;
        case 'r': {
            int orientation;
            if (sscanf(optarg, "%i", &orientation) != 1 || orientation < 0 || orientation > 3) {
                fprintf(stderr, "Invalid orientation argument \"%s\"\n", optarg);
                exit(EXIT_FAILURE);
            }
            switch (orientation) {
                case 0:
                    opts->rotation = LV_DISPLAY_ROTATION_0;
                    break;
                case 1:
                    opts->rotation = LV_DISPLAY_ROTATION_270;
                    break;
                case 2:
                    opts->rotation = LV_DISPLAY_ROTATION_180;
                    break;
                case 3:
                    opts->rotation = LV_DISPLAY_ROTATION_90;
                    break;
            }
            break;
        }
        case 'h':
            print_usage();
            exit(EXIT_SUCCESS);
        case 'v':
            opts->verbose = true;
            break;
        case 'V':
            fprintf(stderr, "buffyboard %s\n", PROJECT_VERSION);
            exit(0);
        default:
            print_usage();
            exit(EXIT_FAILURE);
        }
    }
}
