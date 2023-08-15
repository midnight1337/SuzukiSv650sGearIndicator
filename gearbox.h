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
        float m_gearbox_voltage;

    public:
        Gearbox();
        int gear();
        float gearbox_voltage();
        void read_gearbox_voltage();
        void determine_gear();
};

#endif
