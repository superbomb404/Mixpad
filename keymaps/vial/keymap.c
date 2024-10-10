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
    FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT(
//       col0        col1    col2    col3     col4
                    KC_MPRV, KC_P7,  KC_P8,   KC_P9, //row0
                    KC_MNXT, KC_P4,  KC_P5,   KC_P6, //row1
        TO(FN),     KC_MPLY, KC_P1,  KC_P2,   KC_P3, //row2
        KC_F13,     KC_F14,  KC_P0,  KC_PDOT,        //row3
        KC_F15,     KC_F16,  KC_F17, KC_F18,  KC_F19 //row4
    ),

    [FN] = LAYOUT(
                     XXXXXXX, UG_NEXT, XXXXXXX, XXXXXXX,
                     EE_CLR,  XXXXXXX, UG_TOGG, XXXXXXX,
        TO(DEFAULT), QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F13,      KC_F14,  XXXXXXX, XXXXXXX, 
        KC_F15,      KC_F16,  KC_F17,  KC_F18,  KC_F19
    ),
};


//RGB
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { NO_LED, 0, 1, 2, 3 },
  { NO_LED, 4, 5, 6, 7 },
  { 8, 9, 10, 11, 12 },
  { 13, 14, 15, 16, NO_LED },
  { 17, 18, 19, 20, 21 }
}, {
  // LED Index to Physical Position
  			 { 1,  4 }, { 2,  4 }, { 3,  4 }, { 4,  4 },
  			 { 1,  3 }, { 2,  3 }, { 3,  3 }, { 4,  3 },
  { 0,  2 }, { 1,  2 }, { 2,  2 }, { 3,  2 }, { 4,  2 }, 
  { 0,  1 }, { 1,  1 }, { 2,  1 }, { 3,  1 },
  { 0,  0 }, { 1,  0 }, { 2,  0 }, { 3,  0 }, { 4,  0 }
}, {
  // LED Index to Flag
     4, 4, 4, 4,
     4, 4, 4, 4,
  4, 4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 4
} };








/*
// 屏幕旋转90度
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}
*/


//显示测试文字
bool oled_task_user(void) {
    oled_write_P(PSTR("Test1"),false);
    oled_set_cursor(10,1);
    oled_write_P(PSTR("Test2\n"),false);
    oled_write_P(PSTR("Test3"),false);
    return false;
}





//显示图片
/*
const char PROGMEM my_bitmap[] = {	
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

bool oled_task_user(void) {
    oled_write_raw_P(my_bitmap, sizeof(my_bitmap));
    return false;
}
*/



/*
// 显示当前的键层，并且显示大写锁定与数字键盘锁定的信息
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: \n"), false);

    switch (get_highest_layer(layer_state)) {
        case DEFAULT:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif
*/



//编码器配置
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [DEFAULT] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_F13, KC_F14), ENCODER_CCW_CW(KC_F15, KC_F16), ENCODER_CCW_CW(KC_F17, KC_F18), ENCODER_CCW_CW(KC_F19, KC_F20), ENCODER_CCW_CW(KC_F21, KC_F22), ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    //                                 Encoder 1                              Encoder 2                         Encoder 3                         Encoder 4                     Encoder 5                      Encoder 6                      Encoder 7
    [FN] =        { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)  }
    //                    Encoder 1                          Encoder 2
};
#endif
