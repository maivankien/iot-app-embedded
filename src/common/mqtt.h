#include <ArduinoJson.h>
#include "service/mqtt.h"

void callback(char *topic, byte *payload, unsigned int length)
{
    JsonDocument doc;
    deserializeJson(doc, payload, length);

    if (strcmp(topic, "home/device") == 0)
    {
        handleMQTTDevice(doc);
    }
    else
    {
        Serial.println("Topic not found.");
    }
}
