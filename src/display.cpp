#include "display.h"

Display::Display() {}

void Display::setup_display() // why the fuck it fails allocation when put in Display contructor?!
{
    if (!m_display->begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println(F("SSD1306 allocation failed"));
    }
    m_display->clearDisplay();  // clear buffer
    m_display->display();
    Serial.println(F("SSD1306 allocation OK"));
}

void Display::draw_startup_text()
{
    m_display->setTextSize(2);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(0, 0);
    m_display->println("BOOTING");
    m_display->display();

    delay(2000);
    m_display->clearDisplay();
    m_display->display();
}

void Display::draw_data(int current_gear, float voltage, float temperature)
{
    draw_top_text();
    draw_battery_icon();
    draw_temperature_icon();

    draw_battery_voltage(voltage);
    draw_temperature(temperature);
    draw_current_gear(current_gear);

    m_display->display();
}

int dupa = 0;
void Display::draw_current_gear(int current_gear)
{   
    m_display->setTextSize(7);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(0, 16);
    m_display->println(String(dupa));
    m_display->display();
    delay(200);

    dupa++;
    if (dupa > current_gear) {dupa = 0;}
}

void Display::draw_battery_voltage(float voltage)
{   
    String convert_voltage = String(voltage, 1) + "V";   // convert to one decimal
    m_display->setTextSize(2);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(68, 18);
    m_display->println(convert_voltage);
    m_display->setCursor(68, 44);
}

void Display::draw_temperature(float temperature)
{   
    String convert_temperature = String(temperature, 1);   // convert to one decimal
    m_display->setTextSize(2);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(68, 44);
    m_display->println(convert_temperature);
    m_display->drawCircle(120, 44, 2, WHITE);
}

void Display::draw_battery_icon()
{   
    int coordinate_x = 42;
    int coordinate_y = 18;

    m_display->drawRect(coordinate_x, coordinate_y, 20, 15, WHITE);
    m_display->drawRect(coordinate_x + 2, coordinate_y - 2, 4, 2, WHITE);
    m_display->drawRect(coordinate_x + 14, coordinate_y - 2, 4, 2, WHITE);

    m_display->drawLine(coordinate_x + 2, coordinate_y + 7, coordinate_x + 6, coordinate_y + 7, WHITE);     // -
    m_display->drawLine(coordinate_x + 13, coordinate_y + 7, coordinate_x + 17, coordinate_y + 7, WHITE);     // + -> -
    m_display->drawLine(coordinate_x + 15, coordinate_y + 5, coordinate_x + 15, coordinate_y + 9, WHITE);     // + -> |

    /* // Draws on the top
    m_display->drawRect(50, 2, 20, 14, WHITE);
    m_display->drawRect(52, 0, 4, 2, WHITE);
    m_display->drawRect(64, 0, 4, 2, WHITE);
    m_display->drawLine(52, 9, 56, 9, WHITE);     // -
    m_display->drawLine(63, 9, 67, 9, WHITE);     // + -> -
    m_display->drawLine(65, 7, 65, 11, WHITE);     // + -> |
    */
}

void Display::draw_temperature_icon()
{
    m_display->setTextSize(1);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(42, 48);
    m_display->println("TEMP");
}

void Display::draw_top_text()
{
    m_display->setTextSize(1);
    m_display->setTextColor(WHITE, BLACK);
    m_display->setCursor(24, 0);
    m_display->println("SUZUKI SV650S");
    m_display->setCursor(6, 8);
    m_display->println("github/midnight1337");
}
