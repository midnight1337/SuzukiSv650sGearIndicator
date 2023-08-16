#include "../include/battery.h"

Battery::Battery() {}

float Battery::voltage()
{
    return m_voltage;
}

void Battery::read_battery_voltage()
{
    float voltage = 1; // round(AnalogRead(BATTERY_PIN) * 100.00) / 100.00; // read analog pin and convert it as it was divided by voltage divider
    voltage *= 10;     // voltage has been divided by voltage divider so multiply by 10 to get real value
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
