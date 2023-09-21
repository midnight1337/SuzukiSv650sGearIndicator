#include <abc_adc.h>

// AbcADC::~AbcADC() {}

void AbcADC::read_samples(const uint8_t& mux_channel)
{
    switch (mux_channel)
    {
        case BATTERY_MUX_CHANNEL:
            ADMUX &= ~(1 << MUX0) & ~(1 << MUX1) & ~(1 << MUX2);    // &= ~() -> set to 0 only selected bit, leave rest of register untouched
            break;
        case GEARBOX_MUX_CHANNEL:
            ADMUX |= (1 << MUX0);   // Select ADC channel to pin A1
            break;
        default:
            return;
    }
    
    ADCSRA |= (1 << ADSC);   // Start conversion
    while (ADCSRA & (1 << ADSC));    // Wait for conversion to complete
    m_samples = ADC; // Read ADC value
}

void AbcADC::convert_samples_to_voltage()
{
    m_voltage = (m_samples *  VCC) / MAX_SAMPLES;
}
