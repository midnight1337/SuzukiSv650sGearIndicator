#include "defined_variables.h"

#ifndef GEARBOX_H
#define GEARBOX_H

class Gearbox
{
private:
    uint8_t m_gear;
    float m_gear_voltage;

    void read_gear_voltage_from_gearbox();
    float convert_adc_value_to_voltage(const int& adc_value);
    void determine_gear();

public:
    Gearbox();
    uint8_t gear();
    float gear_voltage();
    void read_gear();
};

#endif
