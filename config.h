/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 5000

// This sends whether or not ctrl, shift, etc. are held to the secondary half of
// the keyboard. Note that it seems to "break" one half entirely unless BOTH
// halves have this enabled.
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
// Allow the current layer to be synced between the halves.
#define SPLIT_LAYER_STATE_ENABLE

// Allow the state of caps lock, num lock, etc. to be synced between the halves.
#define SPLIT_LED_STATE_ENABLE

#define USE_SERIAL_PD2

// RPC to sync `keymap_config` which back magic keycodes.
// See https://github.com/qmk/qmk_firmware/blob/c4551d7ef1ed2c1069f23cc8499b7c7fc30f3ecf/users/drashna/config.h#L32
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_KEYMAP_SYNC


// Setting this to ≤100 makes home-row mods very hard to use since I end up
// holding a key naturally for 100 ms sometimes (especially with my LH).
// However, having it at the default makes modifier keys and the mouse a little
// harder to use since QMK isn't aware of keys pressed on the mouse.
#define TAPPING_TERM 260

// I hold some keys for a just a bit too long (especially "S" for some reason),
// so this lets me increase the tapping term on those keys.
#define TAPPING_TERM_PER_KEY

// Allow mod-tap to work without having to wait for TAPPING_TERM as long as it's
// held for the duration of the modified key being pressed/released.
//
// Tue 12/14/2021 - 09:09 PM - on second thought, this results in too many typos
// and accidental hotkeys.
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

// See https://configure.zsa.io/moonlander/layouts/bn3qp/latest/config/mouse
// for an explanation.
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_DELAY 400

// Allow toggling to a TT layer with just two taps.
#define TAPPING_TOGGLE 2

// Tapping a dual-function key twice will enable its hold action rather than
// repeatedly invoking its tap action.
#define TAPPING_FORCE_HOLD

// Some common bigrams should have lower COMBO_TERMs so that I only activate the
// combo when I really mean to.
#define COMBO_TERM_PER_COMBO








# define DISABLE_RGB_MATRIX_ALPHAS_MODS
# define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
# define DISABLE_RGB_MATRIX_BREATHING
# define DISABLE_RGB_MATRIX_BAND_SAT
# define DISABLE_RGB_MATRIX_BAND_VAL
# define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
# define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
# define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
# define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
# define DISABLE_RGB_MATRIX_CYCLE_ALL
# define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
# define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
# define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
# define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
# define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
# define DISABLE_RGB_MATRIX_DUAL_BEACON
# define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
# define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
# define DISABLE_RGB_MATRIX_RAINBOW_BEACON
# define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
# define DISABLE_RGB_MATRIX_RAINDROPS
# define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
# define DISABLE_RGB_MATRIX_TYPING_HEATMAP
# define DISABLE_RGB_MATRIX_DIGITAL_RAIN
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
# define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
# define DISABLE_RGB_MATRIX_SPLASH
# define DISABLE_RGB_MATRIX_MULTISPLASH
# define DISABLE_RGB_MATRIX_SOLID_SPLASH
# define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH