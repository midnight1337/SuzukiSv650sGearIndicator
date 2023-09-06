#include <Arduino.h>
#include "defined_variables.h"

#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
private:
    float m_voltage;

    float convert_adc_value_to_voltage(const int& adc_value);

public:
    Battery();
    float voltage();
    void read_voltage();
};

#endif
