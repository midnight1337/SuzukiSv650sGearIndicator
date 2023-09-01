#include "defined_variables.h"

#ifndef GEARBOX_H
#define GEARBOX_H

class Gearbox
{
private:
    int m_gear;
    float m_gear_voltage;

    void read_gear_voltage_from_gearbox();
    float convert_adc_value_to_voltage(int adc_value);
    void determine_gear();

public:
    Gearbox();
    int gear();
    float gear_voltage();
    void read_gear();
};

#endif
