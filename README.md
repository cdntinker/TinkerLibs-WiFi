# TinkerLibs-WiFi

- [Overview](#overview)
- [Oddities](#oddities-to-be-sorted)
- [Required Libraries](#required-libraries)
- Usage:
  - [With PlatformIO](#platformio)
  - [With Arduino IDE](#arduino-ide)
- [The Functions](#the-functions)
- [An Example](#an-example)

## Overview
Tools & wrappers to ease WiFi setup & use on both ESP8266 __AND__ ESP32 devices.

Is it just me?

Or is it _really_ that annoying how __similar yet not quite__ WiFi handling on these 2 MCUs are?

## Oddities to be sorted
For some bizarre reason, if you comment out the call to `setup_HTTP()`, rebuild & upload the firmware, the device still connects happily to WiFi...

This does not happen if you erase the flash first...

WTF???

## Required Libraries:

This library uses [my DEBUG library](https://github.com/cdntinker/TinkerLibs-DEBUGhttps://github.com/cdntinker/TinkerLibs-DEBUG).

### ESP8266

* ESP8266WiFi
    * https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

### ESP32

* WiFi
    * https://github.com/arduino-libraries/WiFi

## Usage

### PlatformIO

In `platformio.ini`, add https://github.com/cdntinker/TinkerLibs-WiFi to your `lib-deps` for the project.

```
lib_deps =
   Some Library
   https://github.com/cdntinker/TinkerLibs-DEBUG
   https://github.com/cdntinker/TinkerLibs-WiFi
   Some Other Library
```

Then add `#include "Tinker_WiFi.h"` to any source file you want to reference these functions in.

### Arduino IDE

No idea...  Don't use it...

Anybody wanna work this out for me?

## The Functions

These are all declared in **Tinker_WiFi.h**

### `void setup_WiFi()`
Connects to a WiFi network.

SSID, Password & preferred Hostname must be set up before calling.

```
const char *host;
const char *ssid;
const char *password;
```

### `int WiFi_strength()`
Returns the signal strength of your WiFi connection in dBm.

### `bool WiFi_Test()`
Returns a TRUE/FALSE result wether we still have WiFi.

(8266 seems to recover if the AP comes back online, 32 doesn't.  weird...)

## An Example
Sorry...  Not yet.
