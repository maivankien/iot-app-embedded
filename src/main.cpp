#include <connect/wifi.h>
#include <connect/mqtt.h>

void setup()
{
    Serial.begin(115200);
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