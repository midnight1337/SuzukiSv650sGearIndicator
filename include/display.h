#include "defined_variables.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
    private:
        Adafruit_SSD1306 m_display;
        const uint8_t m_address[1] = {0x3C};

        void draw_current_gear(const char* gear);
        void draw_battery_voltage(const char* batter_voltage);
        void draw_temperature(const char* temperature);
        void draw_battery_icon();
        void draw_temperature_icon();
        void draw_top_text();

    public:
        Display();
        void draw_data(const char* gear, const char* battery_voltage, const char* temperature);
        void setup_display();
        void draw_startup_text();
};

#endif