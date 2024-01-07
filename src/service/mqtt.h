#include <ArduinoJson.h>


void handleMQTTDevice(JsonDocument doc)
{
    const char *sensor = doc["sensor"];
    int value = doc["value"];

    Serial.print("Sensor: ");
    Serial.println(sensor);
    Serial.print("Value: ");
    Serial.println(value);
}