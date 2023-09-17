#include "defined_variables.h"
#include <abc_adc.h>

#ifndef GEARBOX_H
#define GEARBOX_H

class Gearbox: public AbcADC
{
private:
    uint8_t m_gear;
    float m_gear_voltage;
    void determine_gear();

public:
    Gearbox();
    uint8_t gear();
    void read_gear();
};

#endif
