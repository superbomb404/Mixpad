
#pragma once

#define MK_3_SPEED
#define TERMINAL_HELP

#define I2C_DRIVER I2CD1
#define I2C_SDA_PIN GP2  // 将 SDA 引脚设置为 GP2
#define I2C_SCL_PIN GP3  // 将 SCL 引脚设置为 GP3

#define OLED_DISPLAY_128X64  //设置屏幕分辨率
#define OLED_BRIGHTNESS 255  //设置屏幕亮度
// #define OLED_SCROLL_TIMEOUT 300000          //在 OLED 静止 300000 毫秒(300秒)后滚动 OLED 屏幕 设置为 0 则禁用
#define OLED_TIMEOUT 120000                    //在 OLED 更新 120000 毫秒(120秒)后关闭 OLED 屏幕 设置为 0 则禁用
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2   //设置i2c通信为快速模式(提高屏幕刷新率)
#define I2C1_CLOCK_SPEED 400000             //设置i2c通信速率(提高屏幕刷新率)



/* SH1106屏幕驱动 */
#define OLED_IC OLED_IC_SH1106
#define OLED_COLUMN_OFFSET 2  //SH1106屏幕偏移

#define I2C1_TIMINGR_PRESC 0x00U
#define I2C1_TIMINGR_SCLDEL 0x03U
#define I2C1_TIMINGR_SDADEL 0x01U
#define I2C1_TIMINGR_SCLH 0x03U
#define I2C1_TIMINGR_SCLL 0x09U

#define OLED_UPDATE_INTERVAL 66
