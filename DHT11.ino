#include <ESP8266WiFi.h> 
#include <DHT.h>

#define DHTPIN D7 //Pin data dari DHT terhubung ke pin D7 NodeMCU
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Baca DHT11");
  dht.begin();
}

void loop() {
  delay(1000); //1 detik
  float h = dht.readHumidity(); //Membaca kelembaban
  float c = dht.readTemperature(); //Membaca suhu dalam satuan Celcius

  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.print("% RH ");
  Serial.print("Suhu: ");
  Serial.print(c);
  Serial.print(" *C ");
}