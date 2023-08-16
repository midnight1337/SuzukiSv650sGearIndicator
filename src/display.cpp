#include "display.h"

Display::Display()
{
}

void Display::draw_battery_level(float battery_voltage)
{
}

void Display::draw_temperature_level(int temperature)
{
}

void Display::draw_current_gear(int current_gear)
{
}

void Display::draw_battery_icon()
{
    m_display.drawRect(10, 10, 30, 50, WHITE);
}

void Display::draw_temperature_icon()
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

void Display::draw_startup_text(String text = "Hello world")
{
  if(!m_display.begin(SSD1306_SWITCHCAPVCC, m_address)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    return;
  }
    
    m_display.clearDisplay();
    m_display.setTextSize(3);
    m_display.setTextColor(WHITE);
    m_display.setCursor(10, 20);
    m_display.println(text);
    m_display.display(); 
}

void Display::clear_display()
{
    if(!m_display.begin(SSD1306_SWITCHCAPVCC, m_address)) 
    {
        Serial.println(F("SSD1306 allocation failed"));
        return;
    }

    m_display.clearDisplay();
    m_display.setTextSize(1);
    m_display.setTextColor(WHITE);
    m_display.setCursor(10, 20);
    m_display.println();
    m_display.display();
}
