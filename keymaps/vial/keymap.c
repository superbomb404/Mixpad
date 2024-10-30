
#include QMK_KEYBOARD_H

enum layers {
    DEFAULT,
    FN,
    FN1
};

#define ANTIMATION_FRAME_)SIZE 128

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT(
//       col0        col1    col2    col3     col4
                    KC_MPRV, KC_P7,  KC_P8,   KC_P9, //row0
                    KC_MNXT, KC_P4,  KC_P5,   KC_P6, //row1
        TO(FN),     KC_MPLY, KC_P1,  KC_P2,   KC_P3, //row2
        KC_F13,     TO(FN1), KC_P0,  KC_PDOT,        //row3
        KC_F15,     KC_F16,  KC_F17, KC_F18,  KC_F19 //row4
    ),

    [FN] = LAYOUT(
                     RGB_RMOD, RGB_MOD, RGB_SPD, RGB_SPI,
                     XXXXXXX,  RGB_TOG, RGB_VAD,  RGB_VAI,
        TO(DEFAULT), QK_BOOT,  XXXXXXX, XXXXXXX,  XXXXXXX,
        KC_F13,      TO(FN1),  XXXXXXX, XXXXXXX, 
        KC_F15,      KC_F16,   KC_F17,  KC_F18,   KC_F19
    ),

    [FN1] = LAYOUT(
                 XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
                 XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,
        TO(FN),  QK_BOOT,     XXXXXXX, XXXXXXX,  XXXXXXX,
        KC_F13,  TO(DEFAULT), XXXXXXX, XXXXXXX, 
        KC_F15,  KC_F16,      KC_F17,  KC_F18,   KC_F19
    ),
};

//编码器配置
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [DEFAULT] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_F13, KC_F14), ENCODER_CCW_CW(KC_F15, KC_F16), ENCODER_CCW_CW(KC_F17, KC_F18), ENCODER_CCW_CW(KC_F19, KC_F20), ENCODER_CCW_CW(KC_F21, KC_F22), ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    //                         Encoder 1                          Encoder 2                         Encoder 3                      Encoder 4                     Encoder 5                      Encoder 6                       Encoder 7
    [FN] =        { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)  },
    //                    Encoder 1                          Encoder 2
    [FN1] =       { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)  }
    //                    Encoder 1                          Encoder 2
};
#endif



// 屏幕旋转90度
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
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
        case FN1:
            oled_write_P(PSTR("FN1\n"), false);
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



