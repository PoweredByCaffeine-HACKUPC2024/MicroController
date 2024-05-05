#include "ky006.h"

ky006::ky006(uint8_t pin, uint16_t frequency)
{
    this->pin = pin;
    this->frequency = frequency;
    active = false;
}

ky006::ky006(uint8_t pin)
{
    this->pin = pin;
    frequency = 0;
    active = false;
}

void ky006::setup()
{
    pinMode(this->pin, OUTPUT);
}

void ky006::setFrequency(uint16_t frequency)
{
    this->frequency = frequency;
}
void ky006::setActive(boolean active)
{
    this->active = active;
}
uint16_t ky006::getFrequency()
{
    return frequency;
}
boolean ky006::getActive()
{
    return active;
}
void ky006::buzzerMain()
{
    static uint8_t state = LOW;
    if (active = true)
    {
        if (state == LOW)
        {
            digitalWrite(pin, state);
            state = HIGH;
        }
        else if (state == HIGH)
        {
            digitalWrite(pin, state);
            state = LOW;
        }
    }
    else
    {
        /* Do nothing */
    }
}