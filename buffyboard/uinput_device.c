/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#include "uinput_device.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <linux/uinput.h>


/**
 * Static variables
 */

static int fd = -1;
struct input_event event;


/**
 * Static prototypes
 */

/**
 * Emit an event on the device.
 * @param type event type
 * @param code event code
 * @param value event value
 * @return true if emitting the event was succesful, false otherwise
 */
static bool uinput_device_emit(int type, int code, int value);

/**
 * Emit a synchronisation event on the device
 * @return true if emitting the event was succesful, false otherwise
 */
static bool uinput_device_synchronise();


/**
 * Static functions
 */

static bool uinput_device_emit(int type, int code, int value) {
    event.type = type;
    event.code = code;
    event.value = value;
    event.input_event_sec = 0;
    event.input_event_usec = 0;

    if (write(fd, &event, sizeof(event)) != sizeof(event)) {
        perror("Could not emit event");
        return false;
    }

    return true;
}

static bool uinput_device_synchronise() {
    return uinput_device_emit(EV_SYN, SYN_REPORT, 0);
}


/**
 * Public functions
 */

bool bb_uinput_device_init(const int * const scancodes, int num_scancodes) {
    fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("Could not open /dev/uinput");
		return false;
	}

	if (ioctl(fd, UI_SET_EVBIT, EV_KEY) < 0) {
		perror("Could not set EVBIT for EV_KEY");
		return false;
	}

	if (ioctl(fd, UI_SET_EVBIT, EV_SYN) < 0) {
		perror("Could not set EVBIT for EV_SYN");
		return false;
	}

	for (int i = 0; i < num_scancodes; ++i) {
        if (ioctl(fd, UI_SET_KEYBIT, scancodes[i]) < 0) {
            perror("Could not set KEYBIT");
            return false;
        }
    }

    struct uinput_user_dev device;
	memset(&device, 0, sizeof(device));
    strcpy(device.name, "buffyboard");
	device.id.bustype = BUS_USB;
	device.id.vendor = 1;
	device.id.product = 1;
	device.id.version = 1;

	if (ioctl(fd, UI_DEV_SETUP, &device) < 0) {
		perror("Could not set up uinput device");
		return false;
	}

	if (ioctl(fd, UI_DEV_CREATE) < 0) {
		perror("Could not create uinput device");
		return false;
	}

    memset(&event, 0, sizeof(event));

    return true;
}

bool bb_uinput_device_emit_key_down(int scancode) {
    return uinput_device_emit(EV_KEY, scancode, 1) && uinput_device_synchronise();
}

bool bb_uinput_device_emit_key_up(int scancode) {
    return uinput_device_emit(EV_KEY, scancode, 0) && uinput_device_synchronise();
}
