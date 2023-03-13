#include "ThingSpeak.h" //library platform thingspeak
#include <ESP8266WiFi.h> //library platform thingspeak

const char* ssid     = ""; //setting nama wifi router
const char* password = ""; //password wifi router

unsigned long channel = 0000000; //ID channel project pada Thingspeak

//1,2 merupakan channel yang kita gunakan pada channel Thingspeak
unsigned int led1 = 1;
unsigned int led2 = 2;

WiFiClient  client;

void setup() {
  Serial.begin(115200); //memulai komunikasi serial dengan baud rate 115200
  delay(100); //waktu tunda 0.1 detik

  pinMode(D3, OUTPUT); //inisialisasi pin D3 sebagai output
  pinMode(D4, OUTPUT); //inisialisasi pin D4 sebagai output
  digitalWrite(D3, 0); //memberikan output LOW atau tegangan 0 volt ke pin D3
  digitalWrite(D4, 0); //memberikan output LOW atau tegangan 0 volt ke pin D4
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password); //menghubungkan dengan wifi router

  while (WiFi.status() != WL_CONNECTED) { //Cek koneksi Wifi.
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}


void loop(){

  //update data terakhir dari field Thingspeak
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  int led_2 = ThingSpeak.readFloatField(channel, led2);


  if(led_1 == 1){ //Jika data yang dibaca dari Field1 bernilai 1, maka LED 1 menyala
    digitalWrite(D3, 1);
    Serial.println("D3 is On..!");
  }
  
  if(led_1 == 0){ //Jika data yang dibaca dari Field1 bernilai 0, maka LED 1 padam
    digitalWrite(D3, 0);
    Serial.println("D3 is Off..!");
  }

  if(led_2 == 1){ //Jika data yang dibaca dari Field1 bernilai 1, maka LED 2 menyala
    digitalWrite(D4, 1);
    Serial.println("D4 is On..!");
  }
  
  if(led_2 == 0){ //Jika data yang dibaca dari Field1 bernilai 0, maka LED 2 padam
    digitalWrite(D4, 0);
    Serial.println("D4 is Off..!");
  }
 
  Serial.println(led_1);
  Serial.println(led_2);
  delay(500);

}