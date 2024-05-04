#include "influx.h"

void Influx::sendMesure(String bucket, String measurement, String tag, float value)
{
    // Define your InfluxDB server details
    InfluxDBClient client(INFLUXDB_HOST, ORGANIZATION_ID, bucket, INFLUXDB_TOKEN);

    if (!client.validateConnection())
    {
        Serial.print("InfluxDB connection failed: ");
        Serial.println(client.getLastErrorMessage());
        return;
    }

    // Create a Point with the measurement data
    Point point(measurement);
    point.addField(tag, value);

    // Write the Point to the specified bucket
    if (client.writePoint(point))
    {
        Serial.println("Data sent to InfluxDB successfully");
    }
    else
    {
        Serial.print("Failed to send data to InfluxDB: ");
        Serial.println(client.getLastErrorMessage());
    }
}
