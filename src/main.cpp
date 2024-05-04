#include <Arduino.h>
#include "wifi_connection.h"
#include <ky015.h>
#include <ky026.h>
#include "definitions.h"
#include "influx.h"

// put function declarations here:

void setup()
{
  Serial.begin(9600);
  delay(1000);
  WiFiConnection::connectToWiFi();
  Influx::sendMesure("test", "testing", "test1", 1.f);
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
