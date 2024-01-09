/**
 * @title: Suzuki SV650S Gear Indicator
 * @author midnight1337
 * @brief Gear Indicator module for SV650S Motorbike, abiility to read gears, ambient temperature and battery voltage.
 * date: 21-09-2023
*/
#include <Arduino.h>
#include "../include/manager.h"


int main()
{
  init();
  Serial.begin(115200);

  Manager manager{};
  manager.setup();
  manager.setup_adc_registers();

  while (true)
  {
    manager.run();
    delay(MAIN_LOOP_TIME);
  }
}
