#include <Arduino.h>
#include <WiFi.h> // Include the WiFi library

#define SSID "HACKUPC2024B"   // Your WiFi network SSID
#define password "Biene2024!" // Your WiFi network password
#define WIFI_TIMEOUT_MS 20000

// put function declarations here:
void connectToWiFi();

void setup()
{
  Serial.begin(9600);
  delay(1000);
  connectToWiFi();
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (1)
  {
    sleep(5 * 1000);
    // TODO update the sensor data
    // TODO make the api call
  }
}

// put function definitions here:
void connectToWiFi()
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
