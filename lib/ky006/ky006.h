#ifndef _KY006_H // This stops the compiler trying to include the header multiple times.
#define _KY006_H // (Not strictly necessary in this case, but it is if the function definitions are in a separate *.cpp file.)

#include <Arduino.h>

#define MAXFREQ_KY006 2500
#define MINFREQ_KY006 1500

class ky006
{
private:
    uint8_t pin;
    uint16_t frequency;
    boolean active;

public:
    ky006(uint8_t pin, uint16_t frequency);
    ky006(uint8_t pin);

    void setup();
    void setFrequency(uint16_t frequency);
    void setActive(boolean active);
    uint16_t getFrequency();
    boolean getActive();

    void buzzerMain();
};

#endif