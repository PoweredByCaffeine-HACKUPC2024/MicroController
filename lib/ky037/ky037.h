#ifndef _KY037_H // This stops the compiler trying to include the header multiple times.
#define _KY037_H // (Not strictly necessary in this case, but it is if the function definitions are in a separate *.cpp file.)

#include <Arduino.h>

#define VOLTAGEVALUE_KY037 5.0
#define DATARANGE_KY037 4095.0

class ky037
{
private:
    uint8_t analogPin;
    uint8_t digitalPin;
    int analogValue;
    int digitalValue;

public:
    ky037(uint8_t analogPin, uint8_t digitalPin);
    ky037(uint8_t pin, char type);

    int8_t readDigital();
    int8_t readAnalog();

    float getAnalogValue();
    int getDigitalValue();

    void setup();
};

#endif