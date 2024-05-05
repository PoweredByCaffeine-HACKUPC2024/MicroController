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
uint8_t Flame_An_Pin = 32;
uint8_t Flame_Dg_Pin = 0;
// Sound Sensor variables
uint8_t Sound_An_Pin = 33;
uint8_t Sound_Dg_Pin = 0;
// Temp & Humidity Sensor variables
uint8_t Temp_Hum_Pin = 25;
uint8_t DHTType = 11U;
// Buzzer variables
uint8_t Buzzer_Pin = 26;
