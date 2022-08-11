#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <iostream>
#include <string>
#define AWS_IOT_PUBLISH_TOPIC   "$aws/things/ESP32/shadow/update" 
#define AWS_IOT_SUBSCRIBE_TOPIC "$aws/things/ESP32/shadow/update" 

namespace awsMqtt{
    void setup();
    void pubSubErr(int8_t MQTTErr);
    void publishMessage(float t, float h, int l);
    void messageHandler(char* topic, byte* payload, unsigned int length);
    void loop();
}