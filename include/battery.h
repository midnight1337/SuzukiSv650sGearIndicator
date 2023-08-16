/*
Author: Kamil Koltowski
Date: 2023-08-14
Description: Battery class represents a motorbike battery
*/
#include "defined_variables.h"

#ifndef BATTERY_H
#define BATTERY_H

class Battery
{
private:
    float m_voltage;
    bool m_isBatteryConditionGood;

public:
    Battery();
    float voltage();
    bool check_battery_condition();
    void read_battery_voltage();
};

#endif
