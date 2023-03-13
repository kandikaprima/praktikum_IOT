#include <ESP8266WiFi.h> 
#include <ThingerESP8266.h>

#define USERNAME "" //Username thinger.io
#define DEVICE_ID "" 
#define DEVICE_CREDENTIAL ""

#define SSID "" //Hotspot yang kita pakai
#define SSID_PASSWORD ""

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
    pinMode(D7, OUTPUT);

    thing.add_wifi(SSID, SSID_PASSWORD);

    // digital pin control
    thing["led"] << digitalPin(D7);

    // response output
    thing["millis"] >> outputValue(millis());

    // More details at http://docs.thinger.io/arduino/
}

void loop{} (
    thing.handle();
)