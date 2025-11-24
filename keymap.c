/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "version.h"
#include "transactions.h"
#include <stdio.h>

#ifdef OLED_ENABLE
#include "demon.c"
#endif

enum layers {
    _BASE,    // default layer
    _NUM,     // numbers
    _SYMB,    // symbols
    _FUN,     // fn keys
    _NAV,     // navigation keys
};

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 45 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}
#endif

#ifdef OLED_ENABLE
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        // Shortened layer names
        char layer_name[6];  // Limit length to 5 characters + null terminator

        // Clear the line where the layer name will be written
        oled_set_cursor(0, 0);  // Set cursor to the top
        oled_write("     ", false);  // Overwrite any previous text with spaces

        // Switch to determine which layer name to display
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                snprintf(layer_name, sizeof(layer_name), "BSE");  // Use a short name
                break;
            case _NUM:
                snprintf(layer_name, sizeof(layer_name), "NUM");
                break;
            case _SYMB:
                snprintf(layer_name, sizeof(layer_name), "SYM");
                break;
            case _FUN:
                snprintf(layer_name, sizeof(layer_name), "FUN");
                break;
            case _NAV:
                snprintf(layer_name, sizeof(layer_name), "NAV");
                break;
            default:
                snprintf(layer_name, sizeof(layer_name), "???");
                break;
        }

        // Display the shortened layer name
        oled_set_cursor(0, 0);  // Reset the cursor to top left
        oled_write(layer_name, false);  // Write the layer name

        // Render the animation after the layer name
        oled_render_anim();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,     KC_J,    KC_K,    KC_L,    KC_ENT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    MO(_SYMB), TG(_NUM),  MT(MOD_LGUI, KC_SPC),               KC_LSFT,  KC_BSPC, TG(_NAV) 
  ),

  [_NUM] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,     KC_4,   KC_5,                    KC_6, KC_7,    KC_8,   KC_9,    KC_0,
    KC_QUOT, KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_SCLN,
    KC_GRV, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
                      KC_TRNS,   KC_TRNS,    MO(_FUN),                KC_ENT, KC_TRNS, TO(_BASE)
  ),

  [_SYMB] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,         KC_HASH,       KC_DLR, KC_PERC,                 KC_CIRC, KC_AMPR,    KC_ASTR,   KC_LPRN,    KC_RPRN,
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                 KC_TRNS, KC_TRNS,    KC_TRNS,   KC_LBRC,    KC_RBRC,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
                            KC_TRNS, KC_TRNS,  TO(_BASE),         KC_TRNS, KC_TRNS, TO(_BASE)
  ),

  [_FUN] = LAYOUT_split_3x5_3(
    KC_F1,    KC_F2,    KC_F3,     KC_F4,   KC_F5,                    KC_F6, KC_F7,    KC_F8,   KC_F9,    KC_F10,
    KC_QUOT, KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_GRV, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
                      KC_TRNS,   KC_TRNS,    MO(_FUN),                KC_ENT, KC_TRNS, TO(_BASE)
  ),

  [_NAV] = LAYOUT_split_3x5_3(
    KC_ESC,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,     KC_TRNS,    KC_UP,    KC_TRNS,  KC_DEL,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,     KC_LEFT,    KC_DOWN,  KC_RIGHT, KC_ENT,
    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                    KC_TRNS,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
                    KC_LCTL, KC_LOPT,  KC_LCMD,               KC_TRNS,  KC_TRNS, TG(_NAV) 
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSPC:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(KC_DEL);  // If Shift is held, register Delete key
                } else {
                    register_code(KC_BSPC);  // Otherwise, register Backspace
                }
            } else {
                unregister_code(KC_BSPC);  // Unregister backspace
                unregister_code(KC_DEL);   // Unregister delete
            }
            return false;  // Skip all further processing of KC_BSPC
        default:
            return true;  // Process all other keycodes normally
    }
}
