#ifndef Tinker_WiFi_H
#define Tinker_WiFi_H

// Stuff only needed in WiFi_functions.cpp goes here.

#if defined(ESP8266)
    #include "ESP8266WiFi.h"
#elif defined(ESP32)
    #include "WiFi.h"
#endif

String ip3string(IPAddress ip);
String processor(const String &var);

#endif // Tinker_WiFi_H

// Function declarations

void setup_WiFi();

int WiFi_strength();

bool WiFi_Test();
