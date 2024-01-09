#include <Arduino.h>
#include "hardware_variables.h"
#include "base_adc.h"

#ifndef BATTERY_H
#define BATTERY_H

class Battery: public BaseADC
{
    private:
        float m_source_voltage;
        void calculate_source_voltage();

    public:
        Battery();
        void read_voltage();
        float voltage(); 
};

#endif
