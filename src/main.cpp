#include <Arduino.h>
#include "wifi_connection.h"
#include <ky015.h>
#include <ky026.h>
#include <ky028.h>
#include "definitions.h"
#include "influx.h"

// put function declarations here:
uint8_t AnalogPin = 33;
uint8_t DigitalPin = 32;
ky028 TempSensor(AnalogPin, DigitalPin);
WiFiServer server;

void setup()
{
  // Setup sensor pins
  TempSensor.setup();
  Serial.begin(9600);
  delay(1000);
  WiFiConnection::connectToWiFi();
  Influx::sendMesure("test", "testing", "test1", 1.f);
  server = WiFiConnection::startServer(SERVER_PORT);
}

void loop()
{
  printf("Entering loop part\n");
  // put your main code here, to run repeatedly:
  int counter = 0;
  uint32_t lastTime = millis();
  while (1)
  {
    uint32_t currentTime = millis();
    if ((currentTime - lastTime) > 1000)
    {
      lastTime = currentTime;
      if (counter == 5)
      {
        counter = 0;
        TempSensor.readAnalog();
        int temperature = TempSensor.getAnalogValue();
        printf("Temperature: %d\n", temperature);
        Influx::sendMesure("test", "testing", "test1", temperature);
      }
      else
      {
        counter++;
      }
    }

    WiFiClient client = server.available();
    if (!client)
    {
      continue;
    }
    Serial.println("New client connected");
    WiFiConnection::handleClient(client);
    Serial.println("Client disconnected");
  }
}

// put function definitions here:
