#include <WiFi.h>
#include <PubSubClient.h>
#include "config/config.h"
#include "common/mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);

void connectToMQTT()
{
    client.setServer(mqttBroker, mqttPort);
    client.setCallback(callback);

    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");
        if (client.connect("ESP32Client", mqttUser, mqttPassword))
        {
            Serial.println("Connected to MQTT broker");
            for (int i = 0; i < topicSubscribesSize; i++)
            {
                client.subscribe(topicSubscribes[i]);
            }
        }
        else
        {
            Serial.printf("Failed, rc=%d. Retrying in 3 seconds...\n", client.state());
            delay(3000);
        }
    }
    client.publish("home/device/connected", NULL);
}
