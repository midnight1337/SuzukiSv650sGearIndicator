/*

 */

class Gearbox()
{
private:
    int m_gear;
    float m_gearbox_voltage;

public:
    int gear();
    float gearbox_voltage();
    void read_gearbox_voltage();
    void determine_gear();
}
