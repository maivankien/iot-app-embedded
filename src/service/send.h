#include <vector>
#include <ArduinoJson.h>

void pushQueue(JsonDocument doc, std::vector<JsonDocument> &messageQueue)
{
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
