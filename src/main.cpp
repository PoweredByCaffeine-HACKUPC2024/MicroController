#include <Arduino.h>
#include "wifi_connection.h"
#include <ky006.h>
#include <ky015.h>
#include <ky026.h>
#include <ky037.h>
#include "definitions.h"
#include "influx.h"

// put function declarations here:
ky026 FlameSensor(FLAME_AN_PIN, FLAME_DG_PIN);
ky026 PhotoResistor(PHOTO_AN_PIN, PHOTO_DG_PIN);
ky037 SoundSensor(SOUND_AN_PIN, SOUND_DG_PIN);
ky006 Buzzer(BUZZER_PIN, buzzerFrequency);

AsyncWebServer server(SERVER_PORT);

void setup()
{
  Serial.begin(9600);

  FlameSensor.setup();
  PhotoResistor.setup();
  SoundSensor.setup();
  // Buzzer.setup();
  pinMode(builtInLedPin, OUTPUT);
  delay(1000);
  WiFiConnection::connectToWiFi();
  // config the server
  printf("Starting server on port %d\n", SERVER_PORT);
  WiFiConnection::startServer(server);
  printf("Server started\n");
}

void loop()
{
  long time = micros();
  long timeBuzzer = micros();
  // put your main code here, to run repeatedly:
  while (1)
  {
    if (micros() - time > 5 * 1000000)
    {
      time = micros();
      if ((FlameActive == true) && (FlameSensor.readAnalog() == 0))
      {
        Influx::sendMesure(INFLUXDB_BUCKET, "FlameSensor", "Voltage Lvl", FlameSensor.getAnalogValue());
        printf("FlameSensor: %f\n", FlameSensor.getAnalogValue());
      }
      if ((SoundActive == true) && (SoundSensor.readAnalog() == 0))
      {
        Influx::sendMesure(INFLUXDB_BUCKET, "SoundSensor", "Voltage Lvl", SoundSensor.getAnalogValue());
        printf("SoundSensor: %f\n", SoundSensor.getAnalogValue());
      }
      if ((PhotoActive == true) && (PhotoResistor.readAnalog() == 0))
      {
        Influx::sendMesure(INFLUXDB_BUCKET, "PhotoResistor", "Voltage Lvl", PhotoResistor.getAnalogValue());
        printf("PhotoResistor: %f\n", PhotoResistor.getAnalogValue());
      }
    }
    if ((BuzzerActive == true) && (micros() - timeBuzzer > ((1 / buzzerFrequency) * 1000000)))
    {
      timeBuzzer = micros();
      if (Buzzer.getFrequency() != buzzerFrequency)
      {
        Buzzer.setFrequency(buzzerFrequency);
      }
      if (Buzzer.getActive() != BuzzerActive)
      {
        Buzzer.setActive(BuzzerActive);
      }
      Buzzer.buzzerMain();
    }

    // TODO update the sensor data
    // TODO make the api call
  }

  // put function definitions here:
}