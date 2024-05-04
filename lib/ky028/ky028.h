#ifndef _KY028_H // This stops the compiler trying to include the header multiple times.
#define _KY028_H // (Not strictly necessary in this case, but it is if the function definitions are in a separate *.cpp file.)

#include <Arduino.h>

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

    int getAnalogValue();
    int getDigitalValue();

    void setup();
};

#endif // _KY028_H