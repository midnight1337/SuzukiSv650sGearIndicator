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
        int m_address = 0x3C;
        Adafruit_SSD1306 m_display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

    public:
        Display();
        void draw_startup_text(String text);
        void draw_battery_level(float battery_voltage);
        void draw_temperature_level(int temperature);
        void draw_current_gear(int current_gear);
        void draw_battery_icon();
        void draw_temperature_icon();

        void draw_data(float battery_voltage, int temperature, int current_gear);
        void draw_icons();

        void clear_display();
};

#endif