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
 *  @brief  Instanciates a new ky026 class
 *  @param  analogPin     Pin number the analog pin of the KY-026 is connected to.
 *
 *  @note   Sets analogValue to 0 and digitalValue to LOW
 *  @note   Sets digitalPin to NULL
 *
 */
ky026::ky026(uint8_t analogPin)
{
    this->analogPin = analogPin;
    this->digitalPin = NULL;
    this->analogValue = 0;
    this->digitalValue = LOW;
}

/**!
 *  @brief  Instanciates a new ky026 class
 *  @param  digitalPin     Pin number the digital pin of the KY-026 is connected to.
 *
 *  @note   Sets analogValue to 0 and digitalValue to LOW
 *  @note   Sets analogPin to NULL
 *
 */
ky026::ky026(uint8_t digitalPin)
{
    this->analogPin = NULL;
    this->digitalPin = digitalPin;
    this->analogValue = 0;
    this->digitalValue = LOW;
}

/**!
 *  @brief  Setup sensor pins
 *  @note   If analogPin is not NULL; sets analogPin to INPUT.
 *  @note   If digitalPin is not NULL; sets digitalPin to INPUT.
 */
void ky026::setup()
{
    if (this->analogPin != NULL)
    {
        pinMode(this->analogPin, INPUT);
    }
    if (this->digitalPin != NULL)
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
    if (this->digitalPin != NULL)
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
    if (this->analogPin != NULL)
    {
        this->analogPin = analogRead(this->analogPin);
        return 0;
    }
    else
    {
        return -1;
    }
}

/**!
 *  @brief  Returns the last value read in analogPin.
 */
int ky026::getAnalogValue()
{
    return this->analogValue;
}

/**!
 *  @brief  Returns the last value read in digitalPin.
 */
int ky026::getDigitalValue()
{
    return this->digitalValue;
}
