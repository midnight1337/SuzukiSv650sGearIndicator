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
    String convert_battery_voltage = (battery_voltage == 0) ? READ_ERROR : String(battery_voltage, 1) + VOLTAGE_SIGN;
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

    m_warning_data_buffer[0] = (battery_voltage <= LOW_BATTERY_THRESHOLD) ? true : false;
    m_warning_data_buffer[1] = (temperature <= LOW_TEMPERATURE_THRESHOLD) ? true : false;
}

void Manager::setup_port_registers() {}

void Manager::setup_adc_registers()
{
    /*
    ADMUX (ADC Multiplexer Selection Register)
    ADLAR bti - Left(1)/Right(0) ADC result allignment -> ADC = MSB + LSB 00000010 + 00111101, ADC result is 16 bit but stored in 10 bits
    REFS[1:0] bit - Reference voltage source
    MUX[2:1:0] bit - Select which Analog channel is set as input for sample conversion

    ADCSRA (ADC Control and Status Register A): This register controls the ADC's enabling and starting conversions.
    ADEN bit - Enable/Disable ADC
    ADSC bit - Start conversion
    ADATE bit - Enable/Disable auto trigger, disabling requires using ADSC each time sample is needed
    ADPS[2:1:0] bit - Prescaler, Sets division factor for ADC clock

    ADCSRB (ADC Control and Status Register B): related do ADCSRA, TIMERs, choosing trigger source (free running or comparator)

    DIDR0 (Digital Input Disable Register 0): Disable/Enable  Analog channel used as digital buffer
    */
    ADMUX |= (0 << ADLAR);
    ADMUX |= (0 << REFS1) | (1 << REFS0);
    //ADMUX |= (0 << MUX2) | (0 << MUX1) | (1 << MUX0);
    
    ADCSRA |= (1 << ADEN);
    //ADCSRA |= (1 << ADSC);
    ADCSRA |= (0 << ADATE);
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); // set ADC clock prescaler of 128: 16mHz/128=125kHz -> 125KHz/13 = 9.61KHz sampling rate
    
    ADCSRB = 0;
    DIDR0 = B11111111;
}
