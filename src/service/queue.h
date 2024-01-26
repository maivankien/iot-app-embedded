#pragma once

#include <vector>
#include <ArduinoJson.h>
#include "common/pzem.h"

std::vector<JsonDocument> messageQueue;

void pushElectricalPowerQueue()
{
    JsonDocument doc = getElectricalPower();
    messageQueue.push_back(doc);
}

void sendData(PubSubClient &client, std::vector<JsonDocument> &messageQueue, const char *topic)
{
    JsonDocument doc = messageQueue.front();
    char buffer[200];
    serializeJson(doc, buffer);
    client.publish(topic, buffer);
    messageQueue.erase(messageQueue.begin());
}