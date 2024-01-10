#include <ArduinoJson.h>


JsonDocument getTemperatureAndHumidity() {
    JsonDocument doc;
    doc["temperature"] = random(1, 100);
    doc["humidity"] = random(1, 100);
    return doc;
}