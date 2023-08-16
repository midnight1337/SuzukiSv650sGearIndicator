/*
Author: Kamil Koltowski
Date: 2023-08-15
Description:
*/
#include "defined_variables.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
private:
    const uint_8t m_address = {0x3C};
    Adafruit_SSD1306 m_display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

public:
    Display();
    draw_startup_text();
    draw_current_gear();
    draw_battery_level();
    draw_battery_icon();
    draw_temperature_level();
    draw_temperature_icon();

    draw_text();
};

#endif