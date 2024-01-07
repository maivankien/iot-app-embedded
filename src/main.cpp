#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <config/config.h>
#include <connect/wifi.cpp>

// const char *ssid = "WIFI FREE";
const char *password = "khongcho";
const char *mqttBroker = "192.168.1.9";
const int mqttPort = 1883;
const char *mqttUser = "admin";
const char *mqttPassword = "123456";
const char *topicSubscribe = "mqtt/topic";

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message received on topic: ");
    Serial.println(topic);

    // Parse JSON payload
    DynamicJsonDocument doc(512); // Adjust the size based on your JSON payload
    deserializeJson(doc, payload, length);

    // Access JSON data
    const char *sensor = doc["sensor"];
    int value = doc["value"];

    // Do something with the JSON data
    Serial.print("Sensor: ");
    Serial.println(sensor);
    Serial.print("Value: ");
    Serial.println(value);
}

void connectToWiFi();

void setup()
{
    Serial.begin(115200);
    // WiFi.begin(ssid, password);

    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(1000);
    //     Serial.println("Connecting to WiFi...");
    // }
    connectToWiFi();

    client.setServer(mqttBroker, mqttPort);
    client.setCallback(callback);

    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");
        if (client.connect("ESP8266Client", mqttUser, mqttPassword))
        {
            Serial.println("Connected to MQTT broker");
            client.subscribe(topicSubscribe);
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.println("Attempting MQTT connection...");
        if (client.connect("ESP8266Client", mqttUser, mqttPassword))
        {
            Serial.println("Connected to MQTT broker");
            client.subscribe(topicSubscribe);
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void loop()
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
}