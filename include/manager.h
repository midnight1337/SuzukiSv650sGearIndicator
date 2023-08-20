/*
Author: Kamil Koltowski
Date: 2023-08-14
Description:
*/
#ifndef MANAGER_H
#define MANAGER_H

#include <Arduino.h>
#include "battery.h"
#include "gearbox.h"
#include "temperature_sensor.h"
#include "display.h"

class Manager
{
private:
    Battery m_battery = Battery();
    Gearbox m_gearbox = Gearbox();
    TemperatureSensor m_temp_sensor = TemperatureSensor();
    Display m_display;

public:
    Manager();
    void run();
    void setup();
};

#endif
