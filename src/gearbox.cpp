#include "../include/gearbox.h"
/*
1st: 1.36V
2nd: 1.77V
3rd: 2.49V
4th: 3.23V
5th: 4.10V
6th: 4.55V
N: 5.00V
 */

enum GearsVoltageInMiliVolts
{
    first = 136,
    second = 177,
    third = 249,
    fourth = 323,
    fifth = 410,
    sixth = 455,
    neutral = 500
};

Gearbox::Gearbox()
{
    m_gear = 0;
}

int Gearbox::gear()
{
    return m_gear;
}

void Gearbox::read_gear()
{
    read_gear_voltage_from_gearbox();
    determine_gear();
}

void Gearbox::read_gear_voltage_from_gearbox()
{
    m_gear_voltage = round(analogRead(A1) * 100.00) / 100.00; // round up to 2 decimals
}

void Gearbox::determine_gear()
{   
    int gearbox_voltage_in_mv = int(m_gear_voltage * 100);

    if (gearbox_voltage_in_mv >= neutral) {m_gear = 0;}
    else if (gearbox_voltage_in_mv <= first) {m_gear = 1;}
    else if (gearbox_voltage_in_mv > first && gearbox_voltage_in_mv <= second) {m_gear = 2;}
    else if (gearbox_voltage_in_mv > second && gearbox_voltage_in_mv <= third) {m_gear = 3;}
    else if (gearbox_voltage_in_mv > third && gearbox_voltage_in_mv <= fourth) {m_gear = 4;}
    else if (gearbox_voltage_in_mv > fourth && gearbox_voltage_in_mv <= fifth) {m_gear = 5;}
    else if (gearbox_voltage_in_mv > fifth && gearbox_voltage_in_mv <= sixth) {m_gear = 6;}
}
