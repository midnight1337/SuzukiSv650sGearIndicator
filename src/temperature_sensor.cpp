#include "../include/temperature_sensor.h"


TemperatureSensor::TemperatureSensor()
{  
    // m_onewire = new OneWire(DS18B20_ONE_WIRE_PIN);
    // m_sensor = new DS18B20(m_onewire);
    // m_sensor.begin();
    // m_sensor.request(m_address);
}


int TemperatureSensor::temperature()
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

    m_temperature = round(m_sensor.readTemperature(m_address));
    m_sensor.request(m_address);
}
