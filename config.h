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
#define I2C_SDA_PIN GP2  // 将 SDA 引脚设置为 GP1
#define I2C_SCL_PIN GP3  // 将 SCL 引脚设置为 GP0
#define I2C_DRIVER I2CD1
// #define I2C1_SCL_PAL_MODE 3
// #define I2C1_SDA_PAL_MODE 3
// #define OLED_DISPLAY_ADDRESS 0x3C
#define OLED_DISPLAY_128X64
