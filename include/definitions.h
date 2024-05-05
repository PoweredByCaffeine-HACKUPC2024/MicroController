#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H

#include <Arduino.h>

#define SSID "HACKUPC2024B"   // Your WiFi network SSID
#define PASSWORD "Biene2024!" // Your WiFi network password
#define WIFI_TIMEOUT_MS 40000 // 40 seconds
#define HTTPS_PORT 443;       // HTTPS port

// DB variables
#define INFLUXDB_URL "https://eu-central-1-1.aws.cloud2.influxdata.com"
#define INFLUXDB_TOKEN "usTl3DBiSAd75v1F7zp6XHuRSsOPNLVOUkjTkGgnqqq5oinQEyBgfk7Ej2iYEV_v1MfjUc6n8UF5jGY8z5w33A=="
#define INFLUXDB_HOST INFLUXDB_URL
#define ORGANIZATION_ID "0ca6ed4e7a7d9571"
#define INFLUXDB_BUCKET "HACKUPC2024"

// Flame Sensor variables
#define FLAME_AN_PIN 36u
#define FLAME_DG_PIN 0u
// Sound Sensor variables
#define SOUND_AN_PIN 39u
#define SOUND_DG_PIN 0u
// Temp & Humidity Sensor variables
#define TEMP_HUM_PIN 32u
#define DHTTYPE 11U
// Photoresistor Sensor variables
#define PHOTO_AN_PIN 35u
#define PHOTO_DG_PIN 0u
// Buzzer variables
#define BUZZER_PIN 33u
// Server variables
#define SERVER_PORT 80 // Server port
// Sensor variables
#define builtInLedPin 2

static boolean BuzzerActive = false;
static boolean FlameActive = true;
static boolean PhotoActive = true;
static boolean SoundActive = true;
static boolean TempHumActive = false;
static boolean led = false;
static uint16_t buzzerFrequency = 1500u;
#endif