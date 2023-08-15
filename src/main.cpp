#include <Arduino.h>


void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("test test");
  delay(1000);
}





// #include <OneWire.h>
// #include <DS18B20.h>

// // Numer pinu do którego podłaczasz czujnik
// #define ONEWIRE_PIN 2

// // Adres czujnika
// byte address[8] = {0x28, 0xF4, 0x55, 0x56, 0xB5, 0x1, 0x3C, 0x76};

// OneWire onewire(ONEWIRE_PIN);
// DS18B20 sensors(&onewire);

// void setup() {
//   while(!Serial);
//   Serial.begin(115200);

//   sensors.begin();
//   sensors.request(address);
// }

// void loop() {
//   if (sensors.available())
//   {
//     float temperature = sensors.readTemperature(address);

//     Serial.print(temperature);
//     Serial.println(F(" 'C"));

//     sensors.request(address);
//   }

//   // tu umieść resztę twojego programu
//   // Będzie działał bez blokowania
// }