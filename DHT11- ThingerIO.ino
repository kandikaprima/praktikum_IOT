#include <ESP8266WiFi.h> 
#include <DHT.h>
#include <ThingerESP8266.h>

#define USERNAME "" //Username thinger.io
#define DEVICE_ID "" 
#define DEVICE_CREDENTIAL ""

#define SSID "" //Hotspot yang kita pakai
#define SSID_PASSWORD ""

#define DHTPIN D7 //Pin data dari DHT terhubung ke pin D7 NodeMCU
#define DHTTYPE DHT11

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

DHT dht(DHTPIN, DHTTYPE);

float hum,temp;

void setup() {
  Serial.begin(9600);
  Serial.println("Baca DHT11");

  dht.begin();

  thing.add_wifi(SSID, SSID_PASSWORD);

  thing["dht11"] >> [](pson& out){
    out["humidity"] = hum;
    out["celsius"] = temp;
  };
}

void loop() {  
  thing.handle(); 
  
  //sensor membutuhkan waktu 250 ms ketika membaca suhu dan kelembaban 
  float h = dht.readHumidity(); //Membaca kelembaban
  float c = dht.readTemperature(); //Membaca suhu dalam satuan Celcius

  hum = h;
  temp = c;
}