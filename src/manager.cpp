#include "../include/manager.h"

Manager::Manager() {}

void Manager::run()
{
    m_gearbox.read_gear();
    m_battery.read_voltage();
    m_temperature_sensor.read_temperature();
    convert_data_to_char_array(m_gearbox.gear(), m_battery.voltage(), m_temperature_sensor.temperature());
    m_display.draw_data(m_data[0], m_data[1], m_data[2]);   // pass pointer to a first character of an array
}

void Manager::setup()
{
    m_temperature_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}

void Manager::convert_data_to_char_array(const int& gear, const float& battery_voltage, const float& temperature)
{
    String convert_gear = (gear == 0) ? GEAR_N : String(gear);
    String convert_battery_voltage = (battery_voltage > 50) ? READ_ERROR : String(battery_voltage, 1) + VOLTAGE_SIGN;
    String convert_temperature = (temperature == -273) ? READ_ERROR : String(temperature, 1) + TEMPERATURE_SIGN;

    String str_data[3] = {convert_gear, convert_battery_voltage, convert_temperature};
    
    for (int i = 0; i < 3; i++)
    {
        int str_len = str_data[i].length() + 1;    // +1 extra for null termination character
        char str_buffer[str_len];
        str_data[i].toCharArray(str_buffer, str_len);
        strcpy(m_data[i], str_buffer);
    }
}

void Manager::setup_port_registers()
{
}

void Manager::setup_adc_registers()
{
    // ADCSRA = bit(ADEN);                             // turn ADC on
    // ADCSRA |= bit(ADPS0) | bit(ADPS1) | bit(ADPS2); // Prescaler of 128
    // ADMUX = bit(REFS0) | (adcPin & 0x07);           // AVcc and select input port
}


/*
These methods are for debugging purpose
*/
template <typename variable>
void address_of(variable& var)
{
    Serial.print("0x");
    Serial.println((unsigned long) var, HEX);
}

// Check type of variable
inline const char *typeStr(int var) { return "int "; }
inline const char *typeStr(long var) { return "long "; }
inline const char *typeStr(float var) { return "float "; }
inline const char *typeStr(const char *var) { return "char "; }
inline const char *typeStr(String var) { return "string "; }
