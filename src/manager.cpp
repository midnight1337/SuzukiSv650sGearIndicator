#include "../include/manager.h"

Manager::Manager() {}

void Manager::run()
{
    m_battery.read_voltage();
    m_gearbox.read_gear();
    m_temperature_sensor.read_temperature();
    m_display.draw_data(m_gearbox.gear(), m_battery.voltage(), m_temperature_sensor.temperature());
}

void Manager::setup()
{
    m_temperature_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}
