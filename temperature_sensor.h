/*
Author: Kamil Koltowski
Date: 2023-08-15
Description: 
*/
#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H


class TemperatureSensor
{
    private:
        float m_temperature;

    public:
        TemperatureSensor();
        float temperature();
        float convert_temperature_to_celcius(float temperature);
        void read_temperature_from_sensor();
        
};

#endif