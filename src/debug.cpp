/*
These methods are for debugging purpose
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