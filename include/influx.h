#include <WiFi.h>
#include <InfluxDBClient.h>
#include "definitions.h"

class Influx
{

public:
    static void sendMesure(String bucket, String measurement, String tag, float value);
};
