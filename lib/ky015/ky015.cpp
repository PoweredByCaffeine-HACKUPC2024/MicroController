/*!
 *  @file ky015.cpp
 *
 *  Temperature & Humidity Sensor Library for KY-015
 *
 *  This is a library for DHT series of low cost temperature/humidity sensors.
 *
 *  You must have Adafruit Unified Sensor Library library installed to use this
 * class.
 *
 */
#include "ky015.h"

/*!
 *  @brief  Setup sensor pins and set pull timings
 */
void ky015::ky015_begin()
{
    _dht.begin();
}

/*!
 *  @brief  Instanciates a new ky015 class
 *  @param  pin     Pin number the KY-015 is connected to
 *  @param  DHTType Type of DHT sensor
 *
 *  @note   Sets temperature and humidity to 0
 *
 */
ky015::ky015(uint8_t pin, uint8_t DHTType) : _dht(pin, DHTType)
{
    this->pin = pin;
    this->DHTType = DHTType;
    this->temperature = 0;
    this->humidity = 0;
}

/**!
 * @brief  Reads temperature
 * @return 0 if OK, -1 if error
 *
 */
int8_t ky015::readTemperature()
{
    this->temperature = _dht.readTemperature();
    if (isnan(this->temperature))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/**!
 * @brief  Reads humidity
 * @return 0 if OK, -1 if error
 *
 */
int8_t ky015::readHumidity()
{
    this->humidity = _dht.readHumidity();
    if (isnan(this->humidity))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/**!
 * @brief  calculates Heat Index
 * @return 0 if OK, -1 if error
 *
 */
int8_t ky015::calculateHeatIndex()
{
    if (isnan(this->temperature) || isnan(this->humidity))
    {
        return -1;
    }
    else
    {
        this->heat_index = _dht.computeHeatIndex(this->temperature, this->humidity, false);
        return 0;
    }
}

/**!
 * @brief  Returns last temperature read
 */
float ky015::getTemperature()
{
    return this->temperature;
}

/**!
 * @brief  Returns last humidity read
 */
float ky015::getHumidity()
{
    return this->humidity;
}

/**!
 * @brief  Returns last Heat Index calculated
 */
float ky015::getHeatIndex()
{
    return this->heat_index;
}