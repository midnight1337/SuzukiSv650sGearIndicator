#include "../include/temperature_sensor.h"

TemperatureSensor::TemperatureSensor(): m_onewire{DS18B20_ONE_WIRE_PIN}, m_sensor{&m_onewire} 
{
    m_temperature = 0.0f;
}

void TemperatureSensor::setup_sensor()
{
    m_sensor.begin() ? Serial.println("DS18B20 allocation OK") : Serial.println("DS18B20 allocation failed");
}

float TemperatureSensor::temperature()
{
    return m_temperature;
}

void TemperatureSensor::read_temperature()
{
    if (!m_sensor.request(m_address))
    {
        m_temperature = -273;
        return;
    }
    m_temperature = m_sensor.readTemperature(m_address);
}
