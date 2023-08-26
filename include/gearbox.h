/*
Author: Kamil Koltowski
Date: 2023-08-14
Description: Gearbox class represents a motorbike gearbox
*/
#include "defined_variables.h"

#ifndef GEARBOX_H
#define GEARBOX_H

class Gearbox
{
private:
    int m_current_gear;
    float m_current_gear_voltage;

public:
    Gearbox();
    int current_gear();
    float current_gear_voltage();
    void read_gear();
    void read_gear_voltage_from_gearbox();
    void determine_gear();
};

#endif
