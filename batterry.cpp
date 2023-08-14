#include "batterry.h"

Battery::Battery()
{
    m_voltage = NULL;
    m_isBatteryConditionGood = NULL;
}

float Battery::voltage()
{
    return m_voltage;
}

bool Battery::battery_condition()
{
    return m_isBatteryConditionGood;
}

void Battery::read_battery_voltage()
{
    voltage = round(AnalogRead(A0) * 10 * 100.00) / 100.00; // read analog pin and convert it as it was divided by voltage divider
    m_voltage = voltage;
}

// if battery condition under threshold, trigger display to chagne color to RED
void Battery::check_battery_condition()
{
    if (m_voltage <= BATTERRY_LOW_LEVEL)
    {
        m_isBatteryConditionGood = False;
    }
    else
    {
        m_isBatteryConditionGood = True;
    }
}
