#ifndef _KY015_H // This stops the compiler trying to include the header multiple times.
#define _KY015_H // (Not strictly necessary in this case, but it is if the function definitions are in a separate *.cpp file.)

#include "DHT.h"

/**!
 * @brief Class that provides access to the KY-015 temperature and humidity sensor.
 */
class ky015
{
private:
    uint8_t pin;
    uint8_t DHTType;
    float temperature;
    float humidity;
    float heat_index;
    DHT _dht;

public:
    ky015(uint8_t pin, uint8_t DHTType);
    void ky015_begin();
    int8_t readTemperature();
    int8_t readHumidity();
    int8_t calculateHeatIndex();
    float getTemperature();
    float getHumidity();
    float getHeatIndex();
};

#endif // _KY015_H
