#include <Tinker_DEBUG.h>
#include <Tinker_WiFi.h>

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
        int dotcount = 0;
        while (WiFi.status() != WL_CONNECTED) // Give it a bit of time to establish the WiFi connection...
        {
            delay(500);
            dotcount = DEBUG_ProgressBar(dotcount);
        } // while (WiFi.status() != WL_CONNECTED)
        DEBUG_ProgressBar2(dotcount);
    }

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

bool WiFi_Test() // Is Good...  Maybe
{
    if (WiFi.status() != WL_CONNECTED)
    {
        // DEBUG_Trouble("Lost WiFi!");
        return false;
    }
    else
    {
        // DEBUG_Success("Have WiFi!");
        return true;
    }
}
