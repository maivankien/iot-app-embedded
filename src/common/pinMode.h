#include <Arduino.h>

int pins[] = {16, 5, 4};
int pinCount = sizeof(pins) / sizeof(pins[0]);

void setUpPinMode()
{
    for (int i = 0; i < pinCount; i++)
    {
        pinMode(pins[i], OUTPUT);
        Serial.println(digitalPinToInterrupt(pins[i]));
    }
}
