#include "../include/temperature_sensor.h"

TemperatureSensor::TemperatureSensor(): m_onewire{DS18B20_ONE_WIRE_PIN}, m_sensor{&m_onewire} {}

void TemperatureSensor::setup_sensor()
{
    m_sensor.begin();
    m_sensor.request(m_address);
}

float TemperatureSensor::temperature()
{
    return m_temperature;
}

void TemperatureSensor::read_temperature()
{
    if (!m_sensor.available())
    {
        m_temperature = -99;
        return;
    }

    m_temperature = m_sensor.readTemperature(m_address);
    m_sensor.request(m_address);
}
