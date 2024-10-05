# Copyright 2021 Johannes Marbach
# SPDX-License-Identifier: GPL-3.0-or-later

buffyboard_sources = files(
    'command_line.c',
    'config.c',
    'main.c',
    'sq2lv_layouts.c',
    'terminal.c',
    'uinput_device.c'
)

buffyboard_dependencies = [
    common_dependencies,
    meson.get_compiler('c').find_library('m', required: false)
]

executable('buffyboard',
    include_directories: common_include_dirs,
    sources: buffyboard_sources + shared_sources + squeek2lvgl_sources + lvgl_sources,
    dependencies: buffyboard_dependencies,
    install: true
)

install_data('buffyboard.conf', install_dir: get_option('sysconfdir'))

