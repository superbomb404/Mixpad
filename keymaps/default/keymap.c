/*
Copyright 2020 MisonoWorks

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

enum layers {
    DEFAULT,
    SUPER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT] = LAYOUT(
                    KC_MNXT, KC_P1,  KC_P2,   KC_P3,
                    KC_MPRV, KC_P4,  KC_P5,   KC_P6,
        TO(SUPER),  KC_MPLY, KC_P7,  KC_P8,   KC_P9,
        KC_F13,     KC_F14,  KC_P0,  KC_PDOT,
        KC_F15,     KC_F16,  KC_F17, KC_F18,  KC_F19
    ),

    [SUPER] = LAYOUT(
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,
        TO(DEFAULT), QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F13,      KC_F14,  XXXXXXX, XXXXXXX, 
        KC_F15,      KC_F16,  KC_F17,  KC_F18,  KC_F19
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("Test1"),false);
    oled_set_cursor(10,1);
    oled_write_P(PSTR("Test2\n"),false);
    oled_write_P(PSTR("Test3"),false);
    return false;
}

