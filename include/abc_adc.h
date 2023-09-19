#include <Arduino.h>
#include <defined_variables.h>

#ifndef ADC_H
#define ADC_H

class AbcADC
{
    protected:
        int m_samples;
        float m_voltage;
        virtual void read_samples(const uint8_t mux_channel);
        virtual void convert_samples_to_voltage();
        // virtual ~AbcADC() = 0;
};

#endif
