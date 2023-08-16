#include "../include/manager.h"

Manager::Manager()
{
    m_battery = Battery();
    m_gearbox = Gearbox();
    m_temp_sensor = TemperatureSensor();
    m_display = Display();
}

Battery Manager::battery()
{
    return m_battery;
}

Gearbox Manager::gearbox()
{
    return m_gearbox;
}

TemperatureSensor Manager::temp_sensor()
{
    return m_temp_sensor;
}

Display Manager::display()
{
    return m_display;
}
