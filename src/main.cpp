/*
Title: Suzuki SV650S gear indicator
Author: midnight1337
Date:
TODO: ISR on gearbox pin, add threshold to determining gears, check debouncing by changing gear in motorbike
*/

#include <Arduino.h>
#include "manager.h"

Manager manager{};

void setup()
{
  Serial.begin(115200);
  manager.setup();
}

void loop()
{
  manager.run();
  delay(MAIN_LOOP_TIME);
}
