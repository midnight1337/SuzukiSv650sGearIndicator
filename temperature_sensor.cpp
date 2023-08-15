#include <iostream>
#include "temperature_sensor.h"


TemperatureSensor::TemperatureSensor()
{

}


float TemperatureSensor::temperature()
{
    return m_temperature;
}


float TemperatureSensor::convert_temperature_to_celcius(float temperature)
{
    float temperature_in_celcius = round(temperature * 1 * 100.00) / 100.00;
    return temperature_in_celcius;
}


void TemperatureSensor::read_temperature_from_sensor()
{
    float temperature = 0; // Read temp from sensor here
    temperature = convert_temperature_to_celcius(temperature);
    m_temperature = temperature;
}
