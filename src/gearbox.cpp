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
    m_current_gear = 0;
}

int Gearbox::current_gear()
{
    return m_current_gear;
}

float Gearbox::current_gear_voltage()
{
    return m_current_gear_voltage;
}

void Gearbox::read_gear()
{
    read_gear_voltage_from_gearbox();
    determine_gear();
}

void Gearbox::read_gear_voltage_from_gearbox()
{
    m_current_gear_voltage = round(analogRead(A1) * 100.00) / 100.00; // round up to 2 decimals
}

void Gearbox::determine_gear()
{   
    int gearbox_voltage_in_mv = int(m_current_gear_voltage * 100);

    switch (gearbox_voltage_in_mv)
    {
    case first:
        m_current_gear = 1;
        break;
    case second:
        m_current_gear = 2;
        break;
    case third:
        m_current_gear = 3;
        break;
    case fourth:
        m_current_gear = 4;
        break;
    case fifth:
        m_current_gear = 5;
        break;
    case sixth:
        m_current_gear = 6;
        break;
    case neutral:
        m_current_gear = 0;
        break;
    default:
        break;
    }
}
