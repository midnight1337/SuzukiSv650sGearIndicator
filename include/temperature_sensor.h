#include <Arduino.h>
#include <OneWire.h>
#include <DS18B20.h>
#include "defined_variables.h"

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

class TemperatureSensor
{
private:
    OneWire m_onewire;
    DS18B20 m_sensor;
    float m_temperature;
    uint8_t m_address[8] = {0x28, 0xF4, 0x55, 0x56, 0xB5, 0x1, 0x3C, 0x76};
    
public:
    TemperatureSensor();
    float temperature();
    void read_temperature();
    void setup_sensor();
};

#endif