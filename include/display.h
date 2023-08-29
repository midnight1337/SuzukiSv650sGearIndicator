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
        const int m_address[1] = {0x3C};

        void draw_current_gear(int gear);
        void draw_battery_voltage(float voltage);
        void draw_temperature(float temperature);
        void draw_battery_icon();
        void draw_temperature_icon();
        void draw_top_text();

    public:
        Display();
        void setup_display();
        void draw_startup_text();
        void draw_data(int gear, float voltage, float temperature);
};

#endif