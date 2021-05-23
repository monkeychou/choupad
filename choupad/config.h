/*
Copyright 2019 bigo

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    chou
#define PRODUCT         ChouPad
#define DESCRIPTION     A Encoder Keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { B3, F4, F5, F7 }
#define MATRIX_COL_PINS { F0, F1, F6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN B7

#ifdef RGB_DI_PIN
#define RGBLED_NUM 9
#define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8 }

#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif

#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_KEYPRESSES
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE



#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B2 }
#define ENCODER_RESOLUTION 4
#define FORCE_NKRO