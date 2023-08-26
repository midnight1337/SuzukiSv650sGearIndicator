#include <Arduino.h>
#include "manager.h"
/*
Title: Suzuki SV650S gear indicator
Author: midnight1337
Date:
*/

Manager manager{};

void setup() 
{
  Serial.begin(115200);
  manager.setup();
}

void loop() 
{
  manager.run();
  delay(RUN_LOOP_TIME);
}
