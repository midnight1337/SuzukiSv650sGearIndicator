#include "../include/manager.h"

Manager::Manager() {}

int dupa = 0;
void Manager::run()
{
    m_temp_sensor.read_temperature_from_sensor();
    m_display.draw_data(dupa, 0, m_temp_sensor.temperature());
    dupa >= 6 ? dupa = 0 : dupa++;
}

void Manager::setup()
{
    m_temp_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}
