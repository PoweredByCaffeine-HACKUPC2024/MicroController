#ifndef _KY028_H // This stops the compiler trying to include the header multiple times.
#define _KY028_H // (Not strictly necessary in this case, but it is if the function definitions are in a separate *.cpp file.)

#include <Arduino.h>

#define VOLTAGEVALUE_KY028 5.0
#define DATARANGE_KY028 4095.0
#define MINVALUE_KY028 -55.0
#define MAXVALUE_KY028 125.0

class ky028
{
private:
    uint8_t analogPin;
    uint8_t digitalPin;
    int analogValue;
    int digitalValue;

public:
    ky028(uint8_t analogPin, uint8_t digitalPin);
    ky028(uint8_t pin, char type);

    int8_t readDigital();
    int8_t readAnalog();

    float getAnalogValue();
    int getDigitalValue();

    float getTemperature();
    void setup();
};

#endif // _KY028_H