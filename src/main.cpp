/*
Title: Suzuki SV650S gear indicator
Author: midnight1337
Date:
*/
#include <Arduino.h>
#include "manager.h"


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

// ISR (ADC_vect)
// {
//   /*
//   Interrupt Service Routine
//   */
//  Serial.println("interrupt doesn't work sheesh");
// }
