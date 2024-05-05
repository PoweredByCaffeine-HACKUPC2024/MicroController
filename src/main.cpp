#include <Arduino.h>
#include "wifi_connection.h"
#include <ky015.h>
#include <ky026.h>
#include "definitions.h"
#include "influx.h"

// put function declarations here:

AsyncWebServer server(SERVER_PORT);

void setup()
{
  Serial.begin(9600);
  pinMode(builtInLedPin, OUTPUT);
  delay(1000);
  WiFiConnection::connectToWiFi();
  Influx::sendMesure(INFLUXDB_BUCKET, "testing", "test1", 1.f);
  // config the server
  printf("Starting server on port %d\n", SERVER_PORT);
  WiFiConnection::startServer(server);
  printf("Server started\n");
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (1)
  {
    delay(5000);
    // TODO update the sensor data
    // TODO make the api call
  }

  // put function definitions here:
}