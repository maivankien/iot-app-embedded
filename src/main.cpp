#include <connect/wifi.h>
#include "connect/mqtt.h"
#include <common/pinMode.h>
#include <service/queue.h>
#include <sensor/temperature.h>


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
    if (millis() / 100 - lastSendTime >= 10)
    {
        pushElectricalPowerQueue();
        lastSendTime = millis() / 100;
    }
}