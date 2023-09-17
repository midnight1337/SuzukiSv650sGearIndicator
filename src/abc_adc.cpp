#include <abc_adc.h>

void AbcADC::read_samples(const uint8_t mux_channel)
{
    switch (mux_channel)
    {
        case 0:
            ADMUX &= 0b11111000;     // Select ADC channel to pin A0
            break;
        case 1:
            ADMUX |= (1 << MUX0);   // Select ADC channel to pin A1
            break;
        default:
            return;
    }
    
    ADCSRA |= (1 << ADSC);   // Start conversion
    while (ADCSRA & (1 << ADSC));    // Wait for conversion to complete
    m_samples = ADC; // Read ADC value//analogRead(BATTERY_PIN);
}

void AbcADC::convert_samples_to_voltage()
{
    m_voltage = (m_samples *  VCC)  / MAX_SAMPLES;
}
