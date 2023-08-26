#include <Arduino.h>

#ifndef HARDWARE_H
#define HARDWARE_H

#define DS18B20_ONE_WIRE_PIN 2
#define BATTERY_PIN A0
#define GEARBOX_PIN A1

#define BATTERRY_LOW_LEVEL 12

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1

#define RUN_LOOP_TIME 1000
#define STARTUP_TIME 2000
#define STARTUP_TEXT "BOOTING"

#define GEAR_N "N"
#define VOLTAGE_SIGN "V"
#define TEMPERATURE_SIGN "TEMP"
#define SUZUKI_TITLE "SUZUKI SV650S"
#define GITHUB "github/midnight1337"

#define R_TOP 46000
#define R_BOTTOM 4600

#endif