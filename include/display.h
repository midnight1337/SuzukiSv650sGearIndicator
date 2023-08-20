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
        int m_address[1] = {0x3C};
        // Adafruit_SSD1306 m_display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);   // why display behaves very weird with that?
        Adafruit_SSD1306* m_display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

    public:
        Display();
        void setup_display();
        void draw_data(int current_gear, float voltage, float temperature);
        void draw_current_gear(int current_gear);
        void draw_battery_voltage(float voltage);
        void draw_temperature(float temperature);
        void draw_battery_icon();
        void draw_temperature_icon();
        void draw_top_text();
        void draw_startup_text();
};

#endif