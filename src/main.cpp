#include <Arduino.h>
#include "manager.h"

Manager manager;

void setup()
{
  Serial.begin(115200);

  manager = Manager();
  manager.display().draw_startup_text();
  delay(2000);
}

void loop()
{
  manager.battery().read_battery_voltage();
  manager.temp_sensor().read_temperature_from_sensor();
  manager.gearbox().read_gear_voltage_from_gearbox();

  manager.display().draw_data(manager.battery().voltage(), manager.temp_sensor().temperature(), manager.gearbox().current_gear());

  Serial.println("test test");
  delay(1000);
}
