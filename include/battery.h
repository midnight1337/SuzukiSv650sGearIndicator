#include <Arduino.h>
#include "defined_variables.h"

#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
private:
    float m_voltage;

    int read_battery_voltage_from_adc();
    void convert_voltage(int voltage_from_adc);

public:
    Battery();
    float voltage();
    void read_voltage();
};

#endif
