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
    int battery_voltage_as_adc_value = read_battery_voltage_from_adc();
    convert_voltage(battery_voltage_as_adc_value);
}

int Battery::read_battery_voltage_from_adc()
{
    int read_adc = analogRead(BATTERY_PIN);
    return read_adc;
}

void Battery::convert_voltage(int voltage_from_adc)
{
    float convert_adc_to_voltage = (voltage_from_adc *  5.0)  / 1023.0;
    float calculate_source_voltage = (convert_adc_to_voltage * (R_TOP + R_BOTTOM)) / R_BOTTOM;
    m_voltage = calculate_source_voltage;
}
