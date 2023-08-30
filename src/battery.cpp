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
    int adc_value = analogRead(BATTERY_PIN);
    m_voltage = convert_adc_value_to_voltage(adc_value);
}

float Battery::convert_adc_value_to_voltage(int adc_value)
{
    float adc_value_to_voltage = (adc_value *  VCC)  / MAX_SAMPLES;
    float source_voltage = (adc_value_to_voltage * (R_TOP + R_BOTTOM)) / R_BOTTOM;
    return source_voltage;
}
