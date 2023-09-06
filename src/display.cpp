#include "display.h"

Display::Display(): m_display{SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1} {}

void Display::setup_display() // why initializing display fails allocation when put in Display contructor?!
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
    m_display.display();

    delay(STARTUP_TIME);

    m_display.clearDisplay();
    m_display.display();
}

void Display::draw_data(const String& gear, const String& battery_voltage, const String& temperature)
{
    // Serial.println((unsigned long)&data[0]); // show memory address

    draw_top_text();
    draw_battery_icon();
    draw_temperature_icon();
    draw_current_gear(gear);
    draw_battery_voltage(battery_voltage);
    draw_temperature(temperature);

    m_display.display();
}

void Display::draw_current_gear(const String& gear)
{   
    m_display.setTextSize(7);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(0, 16);
    m_display.println(gear);
}

void Display::draw_battery_voltage(const String& battery_voltage)
{   
    m_display.fillRect(68, 18, 100, 30, BLACK);   // Clear display buffer (get rid of unwanted signs that ain't be overrited by new text)
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(68, 18);
    m_display.println(battery_voltage);
}

void Display::draw_temperature(const String& temperature)
{   
    m_display.fillRect(68, 44, 100, 30, BLACK);   // x,y,width,height,color
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

    /* // Draws on the top
    m_display.drawRect(50, 2, 20, 14, WHITE);
    m_display.drawRect(52, 0, 4, 2, WHITE);
    m_display.drawRect(64, 0, 4, 2, WHITE);
    m_display.drawLine(52, 9, 56, 9, WHITE);     // -
    m_display.drawLine(63, 9, 67, 9, WHITE);     // + . -
    m_display.drawLine(65, 7, 65, 11, WHITE);     // + . |
    */
}

void Display::draw_temperature_icon()
{
    m_display.setTextSize(2);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(44, 44);
    m_display.println(TEMPERATURE_TITLE);
}

void Display::draw_top_text()
{
    m_display.setTextSize(1);
    m_display.setTextColor(WHITE, BLACK);
    m_display.setCursor(24, 0);
    m_display.println(SUZUKI_TITLE);
    m_display.setCursor(6, 8);
    m_display.println(GITHUB);
}
