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
  delay(1000);
}
