#pragma once

#include <WiFi.h>
#include "config/config.h"

void connectToWiFi() {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println(WiFi.status());
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
}
