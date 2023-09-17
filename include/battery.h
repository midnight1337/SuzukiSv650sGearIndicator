#include <Arduino.h>
#include "defined_variables.h"
#include <abc_adc.h>

#ifndef BATTERY_H
#define BATTERY_H

class Battery: public AbcADC
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
