#pragma once

#include <ArduinoJson.h>
#include "connect/mqtt.h"
#include "common/pzem.h"

void handleMQTTDevice(JsonDocument doc)
{
    int pin = doc["pin"];
    int value = doc["state"];

    digitalWrite(pin, value);
}