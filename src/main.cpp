#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4   // Pin a cui è connesso il sensore
#define DHTTYPE DHT22   // Tipo di sensore che stiamo utilizzando (DHT22)
#define REFRESH 20000 // Intervallo di tempo tra un refresh e l'altro

DHT dht(DHTPIN, DHTTYPE); // Parametri: pin a cui è connesso il sensore, tipo di dht 11/22

//Variabili
unsigned long myTime; //Variabile per salvare il tempo passato dall'inizio dell'esecuzione del programma
float hum;  //Variabile in cui verrà inserita la % di umidità
float temp; //Variabile in cui verrà inserita la temperatura

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  myTime = millis();

  if (myTime%REFRESH == 0) { //Se il tempo passato dall'inizio dell'esecuzione del programma è multiplo di REFRESH
    hum = dht.readHumidity(); //Leggo l'umidità
    temp = dht.readTemperature(); //Leggo la temperatura
    Serial.print("Umidità: ");
    Serial.print(hum);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
  }

}