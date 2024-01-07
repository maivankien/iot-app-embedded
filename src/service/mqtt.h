#include <ArduinoJson.h>


void handleMQTTDevice(JsonDocument doc)
{
    int pin = doc["pin"];
    int value = doc["state"];

    digitalWrite(pin, value);
}