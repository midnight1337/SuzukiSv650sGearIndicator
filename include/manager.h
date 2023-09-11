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
    char m_data[3][8];  // 2D char array of arrays, 3 arrays 8 characters each
    
    void convert_data_to_char_array(const int& gear, const float& battery_voltage, const float& temperature);

public:
    Manager();
    void run();
    void setup();
    void setup_port_registers();
    void setup_adc_registers();
};

#endif
