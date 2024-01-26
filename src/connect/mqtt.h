#pragma once

#include <WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include "config/config.h"
#include "common/pzem.h"
#include "service/mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);

void publishData(const char *topic, JsonDocument doc)
{
    char buffer[200];
    serializeJson(doc, buffer);
    client.publish(topic, buffer);
}

void callback(char *topic, byte *payload, unsigned int length)
{
    JsonDocument doc;
    deserializeJson(doc, payload, length);

    if (strcmp(topic, "home/device") == 0)
    {
        handleMQTTDevice(doc);
    }
    else if (strcmp(topic, "home/energy/getDay") == 0)
    {
        JsonDocument energy = getElectricalPower();
        energy["date"] = doc["date"];
        publishData("home/energy/day", energy);
    }
    else if (strcmp(topic, "home/energy/getMonth") == 0)
    {
        JsonDocument energy = getElectricalPower();
        energy["date"] = doc["date"];
        publishData("home/energy/month", energy);
        resetEnergyConsumption();
    }
    else
    {
        Serial.println("Topic not found.");
    }
}

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
            Serial.printf("Failed, rc=%d. Retrying ...\n", client.state());
        }
    }
    client.publish("home/device/connected", NULL);
}
