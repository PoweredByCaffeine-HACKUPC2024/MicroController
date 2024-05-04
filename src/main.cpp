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

void setup()
{
  // Setup sensor pins
  TempSensor.setup();
  Serial.begin(9600);
  delay(1000);
  WiFiConnection::connectToWiFi();
  Influx::sendMesure("test", "testing", "test1", 1.f);
}

void loop()
{
  printf("Entering loop part\n");
  // put your main code here, to run repeatedly:
  while (1)
  {
    delay(2500);
    // TODO update the sensor data
    TempSensor.readAnalog();
    printf("Temperature: %d\n", TempSensor.getAnalogValue());

    // TODO make the api call
  }
}

// put function definitions here:
