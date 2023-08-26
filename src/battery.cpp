#include "../include/battery.h"

Battery::Battery() {}

float Battery::voltage()
{
    return m_voltage;
}

void Battery::read_voltage()
{
    /*
        Atmega328P has 10bit ADC operating on voltage level 0-5V (VCC), which is 2^10 -> 0-1023 possible values
    */
    int read_adc = analogRead(BATTERY_PIN);
    float convert_adc_to_voltage = (read_adc *  5.0)  / 1023.0;
    float calculate_source_voltage = (convert_adc_to_voltage * (R_TOP + R_BOTTOM)) / R_BOTTOM;
    m_voltage = calculate_source_voltage;
}
