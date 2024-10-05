/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#include "terminal.h"

#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <linux/vt.h>

#include <sys/ioctl.h>


/**
 * Static variables
 */

static int current_fd = -1;
static int current_vt = -1;
static bool resized_vts[MAX_NR_CONSOLES];
static float height_factor = 1;


/**
 * Static prototypes
 */

/**
 * Close the current file descriptor and reopen /dev/tty0.
 * 
 * @return true if opening was successful, false otherwise
 */
static bool reopen_current_terminal(void);

/**
 * Close the current file descriptor.
 */
static void close_current_terminal(void);

/**
 * Get the currently active virtual terminal.
 * 
 * @return number of the active VT (e.g. 7 for /dev/tty7)
 */
static int get_active_terminal(void);

/**
 * Retrieve a terminal's size.
 * 
 * @param fd TTY file descriptor
 * @param size pointer to winsize struct for writing the size into
 * @return true if the operation was successful, false otherwise. On failure, errno will be set
 * to the value set by the failed system call.
 */
static bool get_terminal_size(int fd, struct winsize *size);

/**
 * Update a terminal's size.
 * 
 * @param fd TTY file descriptor
 * @param size pointer to winsize struct for reading the new size from
 * @return true if the operation was successful, false otherwise. On failure, errno will be set
 * to the value set by the failed system call.
 */
static bool set_terminal_size(int fd, struct winsize *size);

/**
 * Shrink the height of a terminal by the current factor.
 * 
 * @param fd TTY file descriptor
 * @return true if the operation was successful, false otherwise
 */
static bool shrink_terminal(int fd);

/**
 * Reset the height of a terminal to the maximum.
 * 
 * @param fd TTY file descriptor
 * @param size pointer to winsize struct for writing the final size into
 * @return true if the operation was successful, false otherwise
 */
static bool reset_terminal(int fd, struct winsize *size);


/**
 * Static functions
 */

static bool reopen_current_terminal(void) {
    close_current_terminal();

    current_fd = open("/dev/tty0", O_RDWR | O_NOCTTY);
	if (current_fd < 0) {
		perror("Could not open /dev/tty0");
		return false;
	}

    return true;
}

static void close_current_terminal(void) {
    if (current_fd < 0) {
        return;
    }

    close(current_fd);
    current_fd = -1;
}

static int get_active_terminal(void) {
    struct vt_stat stat;
    if (ioctl(current_fd, VT_GETSTATE, &stat) != 0) {
        perror("Could not retrieve current termimal state");
        return -1;
    }
    return stat.v_active;
}

static bool get_terminal_size(int fd, struct winsize *size) {
	if (ioctl(fd, TIOCGWINSZ, size) != 0) {
        int errsv = errno;
        perror("Could not retrieve current terminal size");
        errno = errsv;
        return false;
	}
    return true;
}

static bool set_terminal_size(int fd, struct winsize *size) {
    if (ioctl(fd, TIOCSWINSZ, size) != 0) {
        int errsv = errno;
        perror("Could not update current terminal size");
        errno = errsv;
        return false;
    }
    return true;
}

static bool shrink_terminal(int fd) {
    struct winsize size = { 0, 0, 0, 0 };
    
    if (!reset_terminal(fd, &size)) {
        perror("Could not shrink terminal size");
        return false;
    }

    size.ws_row = floor((float)size.ws_row * height_factor);
    if (!set_terminal_size(fd, &size)) {
        perror("Could not shrink terminal size");
        return false;
    }

    return true;
}

static bool reset_terminal(int fd, struct winsize *size) {
    if (!get_terminal_size(fd, size)) {
        perror("Could not reset terminal size");
        return false;
    }

    /* Test-resize by two rows. If the terminal is already maximised, this will fail and we can exit early. */
    size->ws_row += 2;
    if (!set_terminal_size(fd, size)) {
        bool is_max = (errno == EINVAL);
        size->ws_row -= 2;
        return is_max;
    }

    size->ws_row = floor((float)size->ws_row / height_factor);
    if (!set_terminal_size(fd, size)) {
        if (errno != EINVAL) {
            perror("Could not reset terminal size");
            return false;
        }

        /* Size too large. Reduce by one row until it fits. */
        do {
            size->ws_row -= 1;
        } while (size->ws_row > 0 && !set_terminal_size(fd, size) && errno == EINVAL);

        if (errno != EINVAL || size->ws_row == 0) {
            perror("Could not reset terminal size");
            return false;
        }
    } else {
        /* Size fits but may not max out available space. Increase by one row until it doesn't fit anymore. */
        do {
            size->ws_row += 1;
        } while (set_terminal_size(fd, size));

        if (errno != EINVAL) {
            perror("Could not reset terminal size");
            return false;
        }

        size->ws_row -= 1;
    }

    return true;
}


/**
 * Public functions
 */

bool bb_terminal_init(float factor) {
    if (!reopen_current_terminal()) {
        perror("Could not prepare for terminal resizing");
        return false;
    }

    current_vt = get_active_terminal();
    if (current_vt < 0) {
        perror("Could not prepare for terminal resizing");
        return false;
    }

    height_factor = factor;
    return true;
}

void bb_terminal_shrink_current(void) {
    int active_vt = get_active_terminal();
    if (active_vt < 0) {
        perror("Could not resize current terminal");
        return;
    }

    if (active_vt < 0 || active_vt > MAX_NR_CONSOLES - 1) {
        perror("Could not resize current terminal, index is out of bounds");
        return;
    }

    if (resized_vts[active_vt - 1]) {
        return; /* Already resized */
    }

    if (active_vt != current_vt) {
        if (!reopen_current_terminal()) {
            perror("Could not resize current terminal");
            return;
        }
        current_vt = active_vt;
    }

    if (!shrink_terminal(current_fd)) {
        perror("Could not resize current terminal");
        return;
    }

    resized_vts[current_vt - 1] = true;
}

void bb_terminal_reset_all(void) {
    char device[16];
    struct winsize size = { 0, 0, 0, 0 };

    for (int i = 0; i < MAX_NR_CONSOLES; ++i) {
        if (!resized_vts[i]) {
            continue;
        }

        snprintf(device, 16, "/dev/tty%d", i + 1);
        int fd = open(device, O_RDWR | O_NOCTTY);
        if (fd < 0) {
            perror("Could not reset TTY, unable to open TTY");
            continue;
        }

        reset_terminal(fd, &size);
    }
}
