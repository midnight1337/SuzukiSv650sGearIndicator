#include "../include/manager.h"

Manager::Manager() {}

void Manager::run()
{
    m_temp_sensor.read_temperature_from_sensor();
    m_display.draw_data(6, 0, m_temp_sensor.temperature());
}

void Manager::setup()
{
    m_temp_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}
