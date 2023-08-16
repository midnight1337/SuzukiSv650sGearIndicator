#include <Arduino.h>
#include "manager.h"

Manager manager;

void setup()
{
  Serial.begin(115200);
  manager = Manager();
}

void loop()
{
  Serial.println("Start loop");
  for (int i = 0; i <10; i++)
  {
    manager.display().draw_startup_text(String(i));
    delay(500);
  }

  Serial.println("Finish loop");

  manager.display().clear_display();

  Serial.println("Clear");
  delay(3000);
  Serial.println("End loop");
}



// #include <Arduino.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels



// void setup() {
//   // Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
//   // display.clearDisplay();
//   // display.setTextSize(1);
//   // display.setTextColor(BLACK, WHITE);
//   // display.setCursor(10, 20);
//   // display.println("Hello, world!");
//   // display.display(); 
// }

// void loop() {
  
// }