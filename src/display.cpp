#include "display.h"

Display::Display(): m_display{SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1} {}

void Display::setup_display()
{
    m_display.begin(SSD1306_SWITCHCAPVCC, *m_address) ? Serial.println(F("SSD1306 allocation OK")) : Serial.println(F("SSD1306 allocation failed"));
    m_display.clearDisplay();
    m_display.display();
}

void Display::draw_startup_text()
{
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(0, 0);
    m_display.println(STARTUP_TEXT);
    

    m_display.setTextSize(1);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(24, 24);
    m_display.println(SUZUKI_TITLE);
    m_display.setCursor(6, 32);
    m_display.println(GITHUB);

    m_display.display();

    delay(STARTUP_TIME);

    m_display.clearDisplay();
    m_display.display();
}

void Display::draw_data(const char* gear, const char* battery_voltage, const char* temperature, const bool& battery_warning, const bool& temperature_warning)
{
    draw_battery_icon();
    draw_temperature_icon();
    draw_current_gear(gear);
    draw_battery_voltage(battery_voltage);
    draw_temperature(temperature);
    draw_battery_warning_icon(battery_warning);
    draw_temperature_warning_icon(temperature_warning);

    m_display.display();
}

void Display::draw_current_gear(const char* gear)
{   
    m_display.setTextSize(7);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(0, 16);
    m_display.println(gear);
}

void Display::draw_battery_voltage(const char* battery_voltage)
{   
    // m_display.fillRect(68, 18, 100, 30, BLACK);   // Clear display buffer (get rid of unwanted signs that ain't be overrited by new text)
    clear_part_of_display(68, 18, 100, 30);
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(68, 18);
    m_display.println(battery_voltage);
}

void Display::draw_temperature(const char* temperature)
{   
    // m_display.fillRect(68, 44, 100, 30, BLACK);   // x,y,width,height,color
    clear_part_of_display(68, 44, 100, 30);
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(68, 44);
    m_display.println(temperature);
}

void Display::draw_battery_icon()
{   
    int coordinate_x = 42;
    int coordinate_y = 18;

    m_display.drawRect(coordinate_x, coordinate_y, 20, 15, WHITE);
    m_display.drawRect(coordinate_x + 2, coordinate_y - 2, 4, 2, WHITE);
    m_display.drawRect(coordinate_x + 14, coordinate_y - 2, 4, 2, WHITE);

    m_display.drawLine(coordinate_x + 2, coordinate_y + 7, coordinate_x + 6, coordinate_y + 7, WHITE);
    m_display.drawLine(coordinate_x + 13, coordinate_y + 7, coordinate_x + 17, coordinate_y + 7, WHITE);
    m_display.drawLine(coordinate_x + 15, coordinate_y + 5, coordinate_x + 15, coordinate_y + 9, WHITE);
}

void Display::draw_temperature_icon()
{
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(44, 44);
    m_display.println(TEMPERATURE_TITLE);
}

void Display::draw_battery_warning_icon(const bool& battery_warning)
{
    if (!battery_warning)
    {
        clear_part_of_display(50 + 55, 0, 20, 16);
        return;
    }

    m_display.drawRect(50 + 55, 2, 20, 14, WHITE);
    m_display.drawRect(52 + 55, 0, 4, 2, WHITE);
    m_display.drawRect(64 + 55, 0, 4, 2, WHITE);
    m_display.drawLine(52 + 55, 9, 56 + 55, 9, WHITE);     // -
    m_display.drawLine(63 + 55, 9, 67 + 55, 9, WHITE);     // + . -
    m_display.drawLine(65 + 55, 7, 65 + 55, 11, WHITE);     // + . |
}

void Display::draw_temperature_warning_icon(const bool& temperature_warning)
{
    if (!temperature_warning)
    {
        clear_part_of_display(80, 0, 10, 16);
        return;
    }

    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(80, 2);
    m_display.println(TEMPERATURE_TITLE[0]);
}

void Display::clear_part_of_display(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    m_display.fillRect(x, y, width, height, BLACK);
}
