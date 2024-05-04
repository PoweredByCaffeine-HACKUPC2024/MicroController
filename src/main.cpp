#include <Arduino.h>
#include "wifi_connection.h"
#include <ky015.h>
#include <ky026.h>
#include <ky028.h>
#include "definitions.h"
#include "DataSender.h"

// put function declarations here:
uint8_t AnalogPin = 33;
uint8_t DigitalPin = 32;
ky028 TempSensor(AnalogPin, DigitalPin);
WiFiServer server;
DataSender dataSender;
TimeSeries ts = TimeSeries(5, "temperature", "job=\"esp32-test\"");

void setupDemo()
{
  // Setup sensor pins
  TempSensor.setup();
  Serial.begin(9600);
  delay(1000);
  WiFiConnection::connectToWiFi();
  server = WiFiConnection::startServer(SERVER_PORT);
  dataSender = DataSender();
  dataSender.initialize();
  dataSender.addToSeries(&ts);
  printf("Exiting setup part\n");
}

void loopDemo()
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
        float value = TempSensor.getAnalogValue();
        if (!ts.addSample(dataSender.getTransport().getTimeMillis(), value))
        {
          Serial.println(ts.errmsg);
        }
        printf("Reached successfully\n");
        printf("value: %f\n", value);
        dataSender.sendData();
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
