#include "../include/battery.h"

Battery::Battery() {}

float Battery::voltage()
{
    return m_voltage;
}

void Battery::read_voltage()
{
    ADMUX &= 0b11111000;     // Select ADC channel to pin A0
    ADCSRA |= (1 << ADSC);   // Start conversion
    while (ADCSRA & (1 << ADSC));    // Wait for conversion to complete
    int adc_value = ADC; // Read ADC value//analogRead(BATTERY_PIN);
    m_voltage = convert_adc_value_to_voltage(adc_value);
}

float Battery::convert_adc_value_to_voltage(const int& adc_value)
{
    float adc_value_to_voltage = (adc_value *  VCC)  / MAX_SAMPLES;
    float source_voltage = (adc_value_to_voltage * (R_TOP + R_BOTTOM)) / R_BOTTOM;
    return source_voltage;
}
