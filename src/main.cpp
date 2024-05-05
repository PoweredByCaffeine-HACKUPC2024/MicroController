#include <Arduino.h>
#include "wifi_connection.h"
#include <ky015.h>
#include <ky026.h>
#include "definitions.h"
#include "influx.h"

// put function declarations here:
WiFiServer server;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  WiFiConnection::connectToWiFi();
  Influx::sendMesure(INFLUXDB_BUCKET, "testing", "test1", 1.f);
  server = WiFiConnection::startServer(SERVER_PORT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (1)
  {
    delay(5000);
    // TODO update the sensor data
    // TODO make the api call

    WiFiClient client = server.available();
    if (client)
    {
      Serial.println("New client connected");
      // Handle the client
      WiFiConnection::handleClient(client);
      Serial.println("Client disconnected");
    }
  }
}

// put function definitions here:
