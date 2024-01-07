#include <connect/wifi.h>
#include <connect/mqtt.h>
#include <common/pinMode.h>


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
}