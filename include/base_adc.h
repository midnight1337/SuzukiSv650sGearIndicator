#include <Arduino.h>
#include <hardware_variables.h>

#ifndef BASE_ADC_H
#define BASE_ADC_H

class BaseADC
{
    protected:
        int m_samples;
        float m_voltage;
        virtual void read_samples(const uint8_t& mux_channel);
        virtual void convert_samples_to_voltage();
        // virtual ~BaseADC() = 0;
};

#endif
