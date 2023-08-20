/*
Author: Kamil Koltowski
Date: 2023-08-15
Description:
*/
#include <Arduino.h>
#include "defined_variables.h"
#include <OneWire.h>
#include <DS18B20.h>

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

class TemperatureSensor
{
private:
    float m_temperature;
    byte m_address[8] = {0x28, 0xF4, 0x55, 0x56, 0xB5, 0x1, 0x3C, 0x76};
    OneWire m_onewire = OneWire(DS18B20_ONE_WIRE_PIN);
    DS18B20 m_sensor = DS18B20(&m_onewire);

public:
    TemperatureSensor();
    float temperature();
    void read_temperature_from_sensor();
    void setup_sensor();
};

#endif