#include "../include/manager.h"

Manager::Manager() {}

void Manager::run()
{
    m_gearbox.read_gear();
    m_battery.read_voltage();
    m_temperature_sensor.read_temperature();
    convert_data_to_string(m_gearbox.gear(), m_battery.voltage(), m_temperature_sensor.temperature());
    m_display.draw_data(m_data[0], m_data[1], m_data[2]);
}

void Manager::setup()
{
    m_temperature_sensor.setup_sensor();
    m_display.setup_display();
    m_display.draw_startup_text();
}

void Manager::convert_data_to_string(const int gear, const float battery_voltage, const float temperature)
{
    String convert_gear = (gear == 0) ? GEAR_N : String(gear);
    String convert_battery_voltage = String(battery_voltage, 1) + VOLTAGE_SIGN;
    String convert_temperature = (temperature == -273) ? TEMPERATURE_ERROR : String(temperature, 1) + TEMPERATURE_SIGN;

    m_data[0] = convert_gear;
    m_data[1] = convert_battery_voltage;
    m_data[2] = convert_temperature;
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

void Manager::print_data()
{
    Serial.println("start print data");
    for (int i = 0; i < 3; i++)
    {
        Serial.print("DATA: ");
        Serial.println(m_data[i]);
        Serial.println((unsigned long)&m_data[i], HEX);
    }
    Serial.println("");
}

// Check type of variable
inline const char *typeStr(int var) { return " int "; }
inline const char *typeStr(long var) { return " long "; }
inline const char *typeStr(float var) { return " float "; }
inline const char *typeStr(const char *var) { return " char "; }
inline const char *typeStr(String var) { return " string "; }
