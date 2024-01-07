
#ifndef CONFIG_H
#define CONFIG_H

// Config WiFi
extern const char* ssid;
extern const char* password;

// Config MQTT
extern const int mqttPort;
extern const char *mqttUser;
extern const char *mqttBroker;
extern const char *mqttPassword;
extern const int topicSubscribesSize;
extern const char *topicSubscribes[];

#endif
