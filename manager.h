/*
Author: Kamil Koltowski
Date: 2023-08-14
Description:
*/
#ifndef MANAGER_H
#define MANAGER_H

#include "battery.h"
#include "gearbox.h"
#include "temperature_sensor.h"
#include "display.h"
//#include <Arduino.h>


class Manager
{
    private:
        Battery battery = Battery();
        Gearbox gearbox = Gearbox();
        TemperatureSensor temperature_sensor = TemperatureSensor();
        Display display = Display();

    public:

};

#endif
