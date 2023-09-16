#include "../include/gearbox.h"

enum GearsVoltageInMiliVolts
{
    first = 136,
    second = 177,
    third = 249,
    fourth = 323,
    fifth = 410,
    sixth = 455,
    neutral = 500
};

// enum class GearsVoltageInMiliVoltsBinary
// {
//     first = 0B10001000,
//     second = 0B10110001,
//     third = 0B11111001,
//     fourth = 0B101000011,
//     fifth = 0B110011010,
//     sixth = 0B111000111,
//     neutral = 0B111110100
// };

Gearbox::Gearbox()
{
    m_gear = 0;
}

uint8_t Gearbox::gear()
{
    return m_gear;
}

float Gearbox::gear_voltage()
{
    return m_gear_voltage;
}

void Gearbox::read_gear()
{
    read_gear_voltage_from_gearbox();
    determine_gear();
}

void Gearbox::read_gear_voltage_from_gearbox()
{
    ADMUX |= (1 << MUX0);   // Select ADC channel to pin A1
    ADCSRA |= (1 << ADSC);  // Start conversion
    while (ADCSRA & (1 << ADSC));   // Wait for conversion to complete
    int adc_value = ADC; //analogRead(GEARBOX_PIN);
    m_gear_voltage = convert_adc_value_to_voltage(adc_value);
}

float Gearbox::convert_adc_value_to_voltage(const int& adc_value)
{
    float adc_value_to_voltage = (adc_value *  5.0)  / 1023.0;
    float round_up_voltage_to_two_decimals = round(adc_value_to_voltage * 100.00) / 100.00;
    return round_up_voltage_to_two_decimals;
}

void Gearbox::determine_gear()
{   
    int gear_voltage_in_mv = int(m_gear_voltage * 100);

    if (gear_voltage_in_mv >= neutral) {m_gear = 0;}
    else if (gear_voltage_in_mv <= first) {m_gear = 1;}
    else if (gear_voltage_in_mv > first && gear_voltage_in_mv <= second) {m_gear = 2;}
    else if (gear_voltage_in_mv > second && gear_voltage_in_mv <= third) {m_gear = 3;}
    else if (gear_voltage_in_mv > third && gear_voltage_in_mv <= fourth) {m_gear = 4;}
    else if (gear_voltage_in_mv > fourth && gear_voltage_in_mv <= fifth) {m_gear = 5;}
    else if (gear_voltage_in_mv > fifth && gear_voltage_in_mv <= sixth) {m_gear = 6;}
}
