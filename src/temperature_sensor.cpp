#include "../include/temperature_sensor.h"

TemperatureSensor::TemperatureSensor() {}

void TemperatureSensor::setup_sensor()
{
    m_sensor.begin();
    m_sensor.request(m_address);
}

float TemperatureSensor::temperature()
{
    return m_temperature;
}

void TemperatureSensor::read_temperature_from_sensor()
{
    if (!m_sensor.available())
    {
        m_temperature = -99;
        return;
    }

    m_temperature = m_sensor.readTemperature(m_address);
    m_sensor.request(m_address);
}
