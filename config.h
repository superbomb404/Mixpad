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

#pragma once

#define MK_3_SPEED
#define TERMINAL_HELP

#define I2C_DRIVER I2CD1
#define I2C_SDA_PIN GP2  // 将 SDA 引脚设置为 GP2
#define I2C_SCL_PIN GP3  // 将 SCL 引脚设置为 GP3

// #define I2C1_SCL_PAL_MODE 3
// #define I2C1_SDA_PAL_MODE 3
// #define OLED_DISPLAY_ADDRESS 0x3C   //屏幕地址
// #define DISABLE_UART


#define OLED_DISPLAY_128X64  //设置屏幕分辨率
#define OLED_BRIGHTNESS 255  //设置屏幕亮度
// #define OLED_SCROLL_TIMEOUT 300000          //在 OLED 静止 300000 毫秒(300秒)后滚动 OLED 屏幕 设置为 0 则禁用
#define OLED_TIMEOUT 600000                    //在 OLED 更新 600000 毫秒(600秒)后关闭 OLED 屏幕 设置为 0 则禁用
// #define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2   //设置i2c通信为快速模式(提高屏幕刷新率)
// #define I2C1_CLOCK_SPEED 400000             //设置i2c通信速率(提高屏幕刷新率)

//自定义屏幕分辨率
// #define OLED_DISPLAY_WIDTH 128
// #define OLED_DISPLAY_HEIGHT 64


//RGB阵列
#define WS2812_DI_PIN GP16
// #define WS2812_LED_COUNT 22
#define RGB_MATRIX_LED_COUNT 22
// #define RGBLIGHT_LED_COUNT 22
#define ENABLE_RGB_MATRIX_CYCLE_ALL
