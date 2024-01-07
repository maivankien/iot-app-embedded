#include <ESP8266WiFi.h>
// #include "wifi.h"
WiFiClient espClient;

void connectToWiFi() {
    WiFi.begin("WIFI FREE", "khongcho");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
}
