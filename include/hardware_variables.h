#include <Arduino.h>

#ifndef HARDWARE_VARIABLES_H
#define HARDWARE_VARIABLES_H

enum MainLoopVariables
{
    MAIN_LOOP_TIME = 500U,
    STARTUP_TIME = 2000U,
};

enum TemperatureVariables
{
    DS18B20_ONE_WIRE_PIN = 2,
    LOW_TEMPERATURE_THRESHOLD = 5U,
    TEMPERATURE_ERROR_VALUE = -273,
};

enum GearboxVariables
{
    R_TOP = 46300U,
    R_BOTTOM = 4600U,
    GEARBOX_PIN = A1,
    GEARBOX_MUX_CHANNEL = 1U,
    GEAR_NEUTRAL_VALUE = 0U,
    GEARBOX_INDETERMINATE_VOLTAGE = 50,
    GEAR_THRESHOLD = 15,
};

enum GearboxVoltage
{
    first = 136,
    second = 177,
    third = 249,
    fourth = 323,
    fifth = 410,
    sixth = 455,
    neutral = 500
};

enum BatteryVariables
{
    BATTERY_PIN = A0,
    BATTERY_MUX_CHANNEL = 0U,
    LOW_BATTERY_THRESHOLD = 12U,
    BATTERRY_LOW_LEVEL = 12,
};

enum DisplayVariables
{
    SCREEN_WIDTH = 128U, // OLED display width, in pixels
    SCREEN_HEIGHT = 64U, // OLED display height, in pixels
    OLED_RESET = -1
};

#define VCC 5.0f
#define MAX_SAMPLES 1023.0f

#define STARTUP_TEXT "BOOTING"
#define GEAR_N "N"
#define VOLTAGE_SIGN "V"
#define TEMPERATURE_SIGN "C"
#define TEMPERATURE_TITLE "T:"
#define READ_ERROR "ERR"
#define SUZUKI_TITLE "SUZUKI SV650S"
#define GITHUB_TEXT "github/midnight1337"

#endif