/*!
 *  @file ky028.cpp
 *
 *  Digital temperature sensor library for KY-028
 *
 *  This is a library for a digital temperature sensor using a thermistor
 *
 */
#include "ky028.h"

/**!
 *  @brief  Instanciates a new ky028 class
 *  @param  analogPin     Pin number the analog pin of the KY-026 is connected to.
 *  @param  digitalPin    Pin number the digital pin of the KY-026 is connected to.
 *
 *  @note   Sets analogValue to 0 and digitalValue to LOW
 *
 */
ky028::ky028(uint8_t analogPin, uint8_t digitalPin)
{
    this->analogPin = analogPin;
    this->digitalPin = digitalPin;
    this->analogValue = 0;
    this->digitalValue = LOW;
}

/**!
 *  @brief  Instanciates a new ky028 class
 *  @param  pin     Pin number for the KY-026 is connected to.
 *  @param  type    Char to determine analog or digital pin
 *
 *  @note   Sets analogValue to 0 and digitalValue to LOW
 *  @note   Sets digitalPin to 0
 *
 */
ky028::ky028(uint8_t pin, char type)
{
    if (type == 'd' || type == 'D')
    {
        this->digitalPin = pin;
        this->analogPin = 0;
    }
    else if (type == 'a' || type == 'A')
    {
        this->analogPin = pin;
        this->digitalPin = 0;
    }
    this->analogValue = 0;
    this->digitalValue = LOW;
}

/**!
 *  @brief  Setup sensor pins
 *  @note   If analogPin is not 0; sets analogPin to INPUT.
 *  @note   If digitalPin is not 0; sets digitalPin to INPUT.
 */
void ky028::setup()
{
    if (this->analogPin != 0)
    {
        pinMode(this->analogPin, INPUT);
    }
    if (this->digitalPin != 0)
    {
        pinMode(this->digitalPin, INPUT);
    }
}

/**!
 *  @brief  Reads digital pin of the KY-026 and stores result in digitalValue.
 *  @return 0 if OK, -1 if error
 */
int8_t ky028::readDigital()
{
    if (this->digitalPin != 0)
    {
        this->digitalValue = digitalRead(this->digitalPin);
        return 0;
    }
    else
    {
        return -1;
    }
}

/**!
 *  @brief  Reads analog pin of the KY-026 and stores result in analogValue.
 */
int8_t ky028::readAnalog()
{
    if (this->analogPin != 0)
    {
        this->analogValue = analogRead(this->analogPin);
        return 0;
    }
    else
    {
        return -1;
    }
}

/**!
 *  @brief  Returns the last value read in analogPin as the voltage value.
 */
float ky028::getAnalogValue()
{
    float data = this->analogValue * (VOLTAGEVALUE_KY028 / DATARANGE_KY028);
    return data;
}

/**!
 *  @brief  Returns the last value read in digitalPin.
 */
int ky028::getDigitalValue()
{
    return this->digitalValue;
}

/**!
 *  @brief  Returns analogValue as temperature in Celsius
 */
float ky028::getTemperature()
{
    float data = (this->getAnalogValue() * ((MAXVALUE_KY028 - MINVALUE_KY028) / VOLTAGEVALUE_KY028)) + (MINVALUE_KY028);

    return data;
}