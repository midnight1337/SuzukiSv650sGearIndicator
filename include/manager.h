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
    char m_data_buffer[3][6];
    bool m_warning_data_buffer[2];

    void buffer_data_for_display();
    void check_warnings();

public:
    Manager();
    void run();
    void setup();
    void setup_adc_registers();
};

#endif
