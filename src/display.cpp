#include "display.h"

Display::Display()
{
    m_display.begin(SSD1306_SWITCHCAPVCC, m_address);
    m_display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

Display::draw_text(cursor_x = 0, cursor_y = 10, string text = "Hello world")
{
    display.setCursor(cursor_x, cursor_y);
    display.println(text);
    display.display();
}

Display::draw_battery_level(float battery_voltage)
{
}

Display::draw_temperature_level(int temperature)
{
}

Display::draw_current_gear(int current_gear)
{
}

Display::draw_battery_icon()
{
    display.drawRect(10, 10, 30, 50, WHITE);
}

Display::draw_temperature_icon()
{
}

Display::draw_startup_text()
{
}

void Display::draw_data(float battery_voltage, int temperature, int current_gear)
{
    draw_battery_level(battery_voltage);
    draw_temperature_level(temperature);
    draw_current_gear(current_gear);
}

void Display::draw_icons()
{
    draw_battery_icon();
    draw_temperature_icon();
}
