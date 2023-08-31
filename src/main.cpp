/*
Title: Suzuki SV650S gear indicator
Author: midnight1337
Date:

TODO: 
ISR on gearbox pin, add threshold to determining gears, check debouncing by changing gear in motorbike
Change Strings in code into char array
Clear data on screen with fillrect
Figure out wtf is wrong with converting_data_in_string and joining with another String
When battery votlage below threshold, or Temperature below safe temp, show battery or temp icon on yellow part of screen
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
