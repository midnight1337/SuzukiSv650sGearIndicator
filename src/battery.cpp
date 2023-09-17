#include "../include/battery.h"

Battery::Battery() {}

float Battery::voltage() {return m_source_voltage;} 

void Battery::read_voltage()
{
    read_samples(0);
    convert_samples_to_voltage();
    calculate_source_voltage();
}

void Battery::calculate_source_voltage()
{
    m_source_voltage = (m_voltage * (R_TOP + R_BOTTOM)) / R_BOTTOM;
}
