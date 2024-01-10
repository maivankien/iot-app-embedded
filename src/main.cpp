#include <vector>
#include <connect/wifi.h>
#include <connect/mqtt.h>
#include <common/pinMode.h>
#include <service/send.h>
#include <sensor/temperature.h>

std::vector<JsonDocument> messageQueue;


void setup()
{
    Serial.begin(115200);
    setUpPinMode();
    connectToWiFi();
    connectToMQTT();
}

void loop()
{
    if (!client.connected())
    {
        connectToMQTT();
    }
    client.loop();
    if (client.connected() && !messageQueue.empty())
    {
        sendData(client, messageQueue, "home/data");
    }

    static unsigned long lastSendTime = 0;
    if (millis() / 100 - lastSendTime >= 30)
    {
        JsonDocument doc = getTemperatureAndHumidity();
        
        pushQueue(doc, messageQueue);
        lastSendTime = millis() / 100;
    }
}