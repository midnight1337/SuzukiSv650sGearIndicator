#include <iostream>
#include "battery.h"


Battery::Battery()
{
    
}

float Battery::voltage()
{
    return m_voltage;
}

void Battery::read_battery_voltage()
{
    float voltage = 1;//round(AnalogRead(A0) * 10 * 100.00) / 100.00; // read analog pin and convert it as it was divided by voltage divider
    m_voltage = voltage;
}

// if battery condition under threshold, trigger display to change color to RED
bool Battery::check_battery_condition()
{
    if (m_voltage <= BATTERRY_LOW_LEVEL)
    {
        m_isBatteryConditionGood = false;
    }
    else
    {
        m_isBatteryConditionGood = true;
    }
    return m_isBatteryConditionGood;
}
