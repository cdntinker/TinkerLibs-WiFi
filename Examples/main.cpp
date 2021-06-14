#include <Arduino.h>
#include <Tinker_DEBUG.h>
extern char DEBUGtxt[48];

#include "TopSecret.h"
const char *host = "FooBar";
#include <Tinker_WiFi.h>

const char *DeviceNotes PROGMEM = R"rawliteral(
# Welcome to an example for TinkerLibs-WiFi.                     #
# This is the content of DeviceNotes.                            #)rawliteral";

void setup()
{
  setup_DEBUG();
  DEBUG_Title();
  DEBUG_Reset();

  setup_WiFi();

  sprintf(DEBUGtxt, "WiFi Strength: %d dBm", WiFi_strength());
  DEBUG_LineOut(DEBUGtxt);

  DEBUG_Ready();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!WiFi_Test())
  {
    Serial.println("Oh Poop! WiFi lost...");
  }
  delay(2000);
}
