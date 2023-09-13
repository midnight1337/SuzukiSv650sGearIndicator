#include "../include/manager.h"

Manager::Manager() {}

void Manager::run()
{
    m_gearbox.read_gear();
    m_battery.read_voltage();
    m_temperature_sensor.read_temperature();
    convert_data();
    check_warnings();
    m_display.draw_data(m_data_buffer, m_warning_data_buffer);
}

void Manager::setup()
{
    m_temperature_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}

void Manager::convert_data()
{
    uint8_t gear = m_gearbox.gear();
    float battery_voltage = m_battery.voltage();
    float temperature = m_temperature_sensor.temperature();

    String convert_gear = (gear == GEAR_NEUTRAL_VALUE) ? GEAR_N : String(gear);
    String convert_battery_voltage = (battery_voltage > BATTERY_READ_ERORR_VALUE) ? READ_ERROR : String(battery_voltage, 1) + VOLTAGE_SIGN;
    String convert_temperature = (temperature == TEMPERATURE_ERROR_VALUE) ? READ_ERROR : String(temperature, 1) + TEMPERATURE_SIGN;

    String str_data[3] = {convert_gear, convert_battery_voltage, convert_temperature};
    
    for (uint8_t i = 0; i < 3; i++)
    {
        uint8_t str_len = str_data[i].length() + 1;    // +1 extra for null termination character
        char str_buffer[str_len];
        str_data[i].toCharArray(str_buffer, str_len);
        strcpy(m_data_buffer[i], str_buffer);
    }
}

void Manager::check_warnings()
{
    float battery_voltage = m_battery.voltage();
    float temperature = m_temperature_sensor.temperature();

    m_warning_data_buffer[0] = (battery_voltage <= LOW_BATTERY_THRESHOLD || battery_voltage >= BATTERY_READ_ERORR_VALUE) ? true : false;
    m_warning_data_buffer[1] = (temperature <= LOW_TEMPERATURE_THRESHOLD) ? true : false;
}

void Manager::setup_port_registers() {}

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
inline const char *type_of(int var) { return "int "; }
inline const char *type_of(long var) { return "long "; }
inline const char *type_of(float var) { return "float "; }
inline const char *type_of(const char *var) { return "char "; }
inline const char *type_of(String var) { return "string "; }
