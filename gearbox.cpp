#include "gearbox.h"
/*
1st: 1.36V
N: 5.00V
2nd: 1.77V
3rd: 2.49V
4th: 3.23V
5th: 4.10V
6th: 4.55V
 */

Gearbox::Gearbox()
{
    m_gear = NULL;
    m_gearbox_voltage = NULL;
}

int Gearbox::gear()
{
    return m_gear;
}

flaot Gearbox::gearbox_voltage()
{
    return m_gearbox_voltage;
}

void Gearbox::read_gearbox_voltage()
{
    m_gearbox_voltage = round(AnalogRead(A1) * 100.00) / 100.00; // round up to 2 decimals
}

void Gearbox::determine_gear()
{
    switch (m_gearbox_voltage)
    {
    case 1.36:
        m_gear = 1;
        break;
    case 1.77:
        m_gear = 2;
        break;
    case 2.49:
        m_gear = 3;
        break;
    case 3.23:
        m_gear = 4;
        break;
    case 4.10:
        m_gear = 5;
        break;
    case 4.55:
        m_gear = 6;
        break;
    case 5.00:
        m_gear = 0;
        break;
    default:
        break;
    }
}
