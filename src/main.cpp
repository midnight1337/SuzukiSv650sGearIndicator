/*
Title: Suzuki SV650S gear indicator
Author: midnight1337
Date:

TODO:
ISR on gearbox pin, add threshold to determining gears, check debouncing by changing gear in motorbike
ADC registers etc
When battery votlage below threshold, or Temperature below safe temp, show battery or temp icon on yellow part of screen
*/
#include <Arduino.h>
#include "manager.h"


int main()
{
  init();
  Serial.begin(115200);
  
  Manager manager{};
  manager.setup();

  while (true)
  {
    manager.run();
    delay(MAIN_LOOP_TIME);
  }
}

// volatile int adcReading;
// volatile boolean adcDone;

// ISR (ADC_vect)
//   {
/* Comparator interrupt for comparing a analog input voltage that determines gear change*/
//   adcReading = ADC;
//   adcDone = true;
//   }  // end of ADC_vect
