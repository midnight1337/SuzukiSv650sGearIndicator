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
    char m_display_data[3][8];  // 2D char array of arrays, 3 string arrays - 8 characters each
    bool m_warning_data[2];

    void convert_data_to_char_array_and_check_for_warning(const uint8_t& gear, const float& battery_voltage, const float& temperature);
    void check_for_warning(const float& battery_voltage, const float& temperature);

public:
    Manager();
    void run();
    void setup();
    void setup_port_registers();
    void setup_adc_registers();
};

#endif
