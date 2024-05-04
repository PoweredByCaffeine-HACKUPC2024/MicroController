#include "wifi_connection.h"

/**
 * Connects to the WiFi network.
 *
 * @return void
 *
 * @throws None
 */
void WiFiConnection::connectToWiFi()
{
    WiFi.mode(WIFI_STA); // Optional
    Serial.println("\nConnecting to WiFi " + String(SSID) + "...");
    WiFi.begin(SSID, password);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS)
    {
        delay(1000);
        Serial.print(".");
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("\nFailed to connect to WiFi.");
    }
    else
    {
        Serial.print("\nConnected to WiFi!\nIP address: ");
        Serial.println(WiFi.localIP());
    }
}
