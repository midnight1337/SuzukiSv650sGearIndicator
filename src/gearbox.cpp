#include "../include/gearbox.h"

enum GearsVoltage
{
    first = 136,
    second = 177,
    third = 249,
    fourth = 323,
    fifth = 410,
    sixth = 455,
    neutral = 500
};

Gearbox::Gearbox(): m_gear(0) {}

uint8_t Gearbox::gear() {return m_gear;}

void Gearbox::read_gear()
{
    read_samples(GEARBOX_MUX_CHANNEL);
    convert_samples_to_voltage();
    determine_gear();
}

void Gearbox::determine_gear()
{   
    int gear_voltage = int(m_voltage * 100); // gear voltage in: [V * 100]

    if (gear_voltage <= GEARBOX_INDETERMINATE_VOLTAGE)
    {
        m_gear = 0;
        return;
    }

    if (gear_voltage >= neutral) {m_gear = 0;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= first && (gear_voltage + GEAR_THRESHOLD) >= first) {m_gear = 1;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= second && (gear_voltage + GEAR_THRESHOLD) >= second) {m_gear = 2;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= third && (gear_voltage + GEAR_THRESHOLD) >= third) {m_gear = 3;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= fourth && (gear_voltage + GEAR_THRESHOLD) >= fourth) {m_gear = 4;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= fifth && (gear_voltage + GEAR_THRESHOLD) >= fifth) {m_gear = 5;}
    else if ((gear_voltage - GEAR_THRESHOLD) <= sixth && (gear_voltage + GEAR_THRESHOLD) >= sixth) {m_gear = 6;}
}
