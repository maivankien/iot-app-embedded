#pragma once

#include <Arduino.h>

int pins[] = {2, 4, 15, 16, 12, 13, 14, 27};
int pinCount = sizeof(pins) / sizeof(pins[0]);

void setUpPinMode()
{
    for (int i = 0; i < pinCount; i++)
    {
        pinMode(pins[i], OUTPUT);
        Serial.println(digitalPinToInterrupt(pins[i]));
    }
}
