/*
Author:
Date:
Description:
*/
#define BATTERRY_LOW_LEVEL = 12; // find out what's the low batterry level

class Batterry()
{
private:
    float m_voltage;
    bool m_isBatteryConditionGood;

public:
    float voltage();
    bool battery_condition();
    void read_battery_voltage();
    void check_battery_condition();
};
