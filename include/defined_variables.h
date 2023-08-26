#include <Arduino.h>

#ifndef HARDWARE_H
#define HARDWARE_H

#define DS18B20_ONE_WIRE_PIN 2
#define BATTERY_PIN nullptr
#define GEARBOX_PIN nullptr
#define DISPLAY_PIN nullptr

#define BATTERRY_LOW_LEVEL 12

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1

#define STARTUP_TIME 2000
#define STARTUP_TEXT "BOOTING"

#define GEAR_N "N"
#define VOLTAGE_SIGN "V"
#define TEMPERATURE_SIGN "TEMP"
#define SUZUKI_TITLE "SUZUKI SV650S"
#define GITHUB "github/midnight1337"

#endif