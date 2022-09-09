#include <Arduino.h>
#include <DHT.h>
#include "bluetooth.h"
#include "wifi32.h"

#define DHTPIN 4   
#define DHTTYPE DHT11   
#define REFRESH 2000 
#define LIGHT_SENSOR_PIN 32 
DHT dht(DHTPIN, DHTTYPE);

//Variabili
unsigned long myTime; 
float hum;
float temp; 
int light;
void setup() {
  Serial.begin(115200);
  connect::setup();
  bluetooh::setup();
  dht.begin();
}

void loop() {
  connect::loop();
  bluetooh::loop();
  myTime = millis();

  if (myTime%REFRESH == 0) {
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    light = analogRead(LIGHT_SENSOR_PIN);
    Serial.print("Umidità: ");
    Serial.print(hum);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.print(" °C");
    Serial.print(" %\t");
    Serial.print("Luminosità: ");
    Serial.println(light);
  }
}