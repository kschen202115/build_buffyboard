/**
 * Copyright 2021 Johannes Marbach
 * SPDX-License-Identifier: GPL-3.0-or-later
 */


#ifndef BB_TERMINAL_H
#define BB_TERMINAL_H

#include <stdbool.h>

/**
 * Prepare for resizing terminals by opening the current one.
 * 
 * @param factor factor (between 0 and 1) by which to adapt terminal sizes
 * @return true if the operation was successful, false otherwise. No other bb_terminal_* functions
 * must be called if false is returned.
 */
bool bb_terminal_init(float factor);

/**
 * Shrink the height of the active terminal by the current factor.
 */
void bb_terminal_shrink_current(void);

/**
 * Re-maximise the height of all previously resized terminals.
 */
void bb_terminal_reset_all(void);

#endif /* BB_TERMINAL_H */
