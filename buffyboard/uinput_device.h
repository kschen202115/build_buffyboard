/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#ifndef BB_UINPUT_DEVICE_H
#define BB_UINPUT_DEVICE_H

#include <stdbool.h>

/**
 * Initialise the uinput keyboard device
 * 
 * @param scancodes array of scancodes the device can emit
 * @param num_scancodes number of scancodes the device can emit
 * @return true if creating the device was successful, false otherwise
 */
bool bb_uinput_device_init(const int * const scancodes, int num_scancodes);

/**
 * Emit a key down event
 * 
 * @param scancode the key's scancode
 * @return true if emitting the event was successful, false otherwise
 */
bool bb_uinput_device_emit_key_down(int scancode);

/**
 * Emit a key up event
 * 
 * @param scancode the key's scancode
 * @return true if emitting the event was successful, false otherwise
 */
bool bb_uinput_device_emit_key_up(int scancode);

#endif /* BB_UINPUT_DEVICE_H */
