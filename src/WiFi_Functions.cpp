#include <Tinker_DEBUG.h>
#include "Tinker_WiFi.h"

// #include "TopSecret.h"

extern const char *host;
extern const char *ssid;
extern const char *password;

extern char DEBUGtxt[48];

void setup_WiFi() //   We start by connecting to a WiFi network
{
    WiFi.hostname(host);

    delay(10);

    DEBUG_Init("WiFi");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    sprintf(DEBUGtxt, "Connecting to: %-22s", ssid);
    DEBUG_SectionTitle(DEBUGtxt);
    {
        // DEBUG_ProgressBar0();
        int dotcount = 0;
        while (WiFi.status() != WL_CONNECTED) // Give it a bit of time to establish the WiFi connection...
        {
            delay(500);
            dotcount = DEBUG_ProgressBar(dotcount);
        }
        DEBUG_ProgressBar2(dotcount);
    } // while (WiFi.status() != WL_CONNECTED)

    randomSeed(micros());
    DEBUG_Success("WiFi connected");
    sprintf(DEBUGtxt,
            "IP address:  %-16s",
            WiFi.localIP().toString().c_str());
    DEBUG_LineOut(DEBUGtxt);
    sprintf(DEBUGtxt,
            "MAC address: %-18s",
            WiFi.macAddress().c_str());
    DEBUG_LineOut(DEBUGtxt);
}

int WiFi_strength()
{
    return (WiFi.RSSI());
}

int blip[3] = {000, 255, 000}; // GRN

void WiFi_Test() // Is Good...  Maybe
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Oh Poop!");
        blip[0] = 128;
        blip[1] = 128;
    }
    else
    {
        Serial.println(WiFi OK);
        if (blip[1] == 255)
            blip[1] = 0;
        else
            blip[1] = 255;
    }
#ifdef d_Pixels
    SetAPixel(3, blip);
#endif // d_Pixels
}
