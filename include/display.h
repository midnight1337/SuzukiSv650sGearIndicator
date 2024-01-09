#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "hardware_variables.h"

#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
    private:
        Adafruit_SSD1306 m_display;
        const uint8_t m_address[1] = {0x3C};

        void draw_current_gear(const char (&gear)[6]);
        void draw_battery_voltage(const char (&battery_voltage)[6]);
        void draw_temperature(const char (&temperature)[6]);
        void draw_battery_icon();
        void draw_temperature_icon();
        void draw_battery_warning_icon(const bool (&battery_warning));
        void draw_temperature_warning_icon(const bool (&temperature_warning));
        void clear_part_of_display(uint8_t x, uint8_t y, uint8_t width, uint8_t height);

    public:
        Display();
        void draw_data(const char (&r_data_buffer)[3][6], const bool (&r_warning_data_buffer)[2]);
        void setup_display();
        void draw_startup_text();
};

#endif