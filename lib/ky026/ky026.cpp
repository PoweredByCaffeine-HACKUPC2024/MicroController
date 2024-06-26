/*!
 *  @file ky026.cpp
 *
 *  Flame detector IR sensor library for KY-026
 *
 *  This is a library for a flame detector sensor using IR light sensor.
 *
 */
#include "ky026.h"

/**!
 *  @brief  Instanciates a new ky026 class
 *  @param  analogPin     Pin number the analog pin of the KY-026 is connected to.
 *  @param  digitalPin    Pin number the digital pin of the KY-026 is connected to.
 *
 *  @note   Sets analogValue to 0 and digitalValue to LOW
 *
 */
ky026::ky026(uint8_t analogPin, uint8_t digitalPin)
{
    this->analogPin = analogPin;
    this->digitalPin = digitalPin;
    this->analogValue = 0;
    this->digitalValue = LOW;
}

/**!
 *  @brief  Setup sensor pins
 *  @note   If analogPin is not 0; sets analogPin to INPUT.
 *  @note   If digitalPin is not 0; sets digitalPin to INPUT.
 */
void ky026::setup()
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
int8_t ky026::readDigital()
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
int8_t ky026::readAnalog()
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
float ky026::getAnalogValue()
{
    float data = this->analogValue * (VOLTAGEVALUE_KY026 / DATARANGE_KY026);
    return data;
}

/**!
 *  @brief  Returns the last value read in digitalPin.
 */
int ky026::getDigitalValue()
{
    return this->digitalValue;
}
