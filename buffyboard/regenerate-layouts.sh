#!/bin/bash

# Copyright 2021 Johannes Marbach
# SPDX-License-Identifier: GPL-3.0-or-later


cd ../squeek2lvgl
pipenv install
pipenv run python squeek2lvgl.py \
    --input terminal/us.yaml \
        --name "US English (Terminal)" \
    --output ../buffyboard \
    --generate-scancodes \
    --shift-keycap '\xef\x8d\x9b'
