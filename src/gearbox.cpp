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

Gearbox::Gearbox() {m_gear = 0;}

uint8_t Gearbox::gear() {return m_gear;}

void Gearbox::read_gear()
{
    read_samples(GEARBOX_MUX_CHANNEL);
    convert_samples_to_voltage();
    determine_gear();
}

void Gearbox::determine_gear()
{   
    float round_up_voltage_to_two_decimals = round(m_voltage * 100.00) / 100.00;    // is it necessary??
    int gear_voltage_in_mv = int(round_up_voltage_to_two_decimals * 100);

    if (gear_voltage_in_mv <= GEARBOX_INDETERMINATE_VOLTAGE_IN_MV)
    {
        m_gear = 0;
        return;
    }

    if (gear_voltage_in_mv >= neutral) {m_gear = 0;}
    else if (gear_voltage_in_mv <= first) {m_gear = 1;}
    else if (gear_voltage_in_mv > first && gear_voltage_in_mv <= second) {m_gear = 2;}
    else if (gear_voltage_in_mv > second && gear_voltage_in_mv <= third) {m_gear = 3;}
    else if (gear_voltage_in_mv > third && gear_voltage_in_mv <= fourth) {m_gear = 4;}
    else if (gear_voltage_in_mv > fourth && gear_voltage_in_mv <= fifth) {m_gear = 5;}
    else if (gear_voltage_in_mv > fifth && gear_voltage_in_mv <= sixth) {m_gear = 6;}
}
