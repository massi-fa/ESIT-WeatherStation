#include "wifi32.h"

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

String hostname = "ESP32-Sensors";

namespace connect{
  void setup(){
    initWiFi();
  }
  void initWiFi() {
    WiFi.hostname(hostname.c_str());
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print('.');
      delay(1000);
    }
    Serial.println(WiFi.macAddress());
    Serial.println(WiFi.localIP());
  }
}