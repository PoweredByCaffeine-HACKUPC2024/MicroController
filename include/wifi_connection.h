#include <WiFi.h>

#define SSID "HACKUPC2024B"   // Your WiFi network SSID
#define password "Biene2024!" // Your WiFi network password
#define WIFI_TIMEOUT_MS 40000

class WiFiConnection
{

public:
    /**
     * Connect to WiFi with the given credentials
     */
    static void connectToWiFi();
};