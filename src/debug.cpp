/*
These methods are for debugging purpose

ADC Registers good documentation: https://www.arnabkumardas.com/arduino-tutorial/adc-register-description/

Port Manipulation:
DDRx - setup pins in register x, 1 - output, 0 - input
DDRx = B11111110;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
DDRD = DDRD | B11111100;  // this is safer as it sets pins 2 to 7 as outputs, without changing the value of pins 0 & 1, which are RX & TX

PORTx - set higg/low state on pins in register
PORTD = B10101000; // sets digital pins 7,5,3 HIGH
*/
#include <Arduino.h>

template <typename variable>
void print(variable& var)
{
    Serial.println(var);
}

template <typename variable>
void address_of(variable& var)
{
    Serial.print("0x");
    Serial.println((unsigned long) var, HEX);
}

// Check type of variable
inline const char *type_of(int var) { return "int "; }
inline const char *type_of(long var) { return "long "; }
inline const char *type_of(float var) { return "float "; }
inline const char *type_of(const char *var) { return "char "; }
inline const char *type_of(String var) { return "string "; }