#include "config.h"

// Config WiFi
const char* ssid = "WIFI FREE";
const char *password = "khongcho";

// Config MQTT
const int mqttPort = 1883;
const char *mqttUser = "admin";
const char *mqttPassword = "123456";
const char *mqttBroker = "192.168.1.9";

const int topicSubscribesSize = 3;
const char *topicSubscribes[] = {"home/device", "home/energy/getDay", "home/energy/getMonth"};
