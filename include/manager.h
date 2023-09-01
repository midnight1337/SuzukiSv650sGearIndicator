#include <Arduino.h>
#include "battery.h"
#include "gearbox.h"
#include "temperature_sensor.h"
#include "display.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager
{
private:
    Battery m_battery{};
    Gearbox m_gearbox{};
    TemperatureSensor m_temperature_sensor{};
    Display m_display{};
    String m_data[3];
    void convert_data_to_string(int gear, float battery_voltage, float temperature);
    void print_data();

public:
    Manager();
    void run();
    void setup();
};

#endif
