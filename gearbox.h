/*
Author: Kamil Koltowski
Date: 2023-08-14
Description: Gearbox class represents a motorbike gearbox
*/
#ifndef GEARBOX_H
#define GEARBOX_H


class Gearbox
{
    private:
        int m_gear;
        float m_gear_voltage;

    public:
        Gearbox();
        int gear();
        float gear_voltage();
        void read_gear_voltage_from_gearbox();
        void determine_gear();
};

#endif
