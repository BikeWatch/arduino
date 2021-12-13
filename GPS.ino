#include <TinyGPS++.h>
#include <SoftwareSerial.h>

int RXPin = 2;
int TXPin = 3;

int GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial gpsSerial(RXPin, TXPin);

void InitializeGPS() {
  if (!gpsConnected) {
    return;
  }
  Serial.println("Initialize GPS");

  gpsSerial.begin(GPSBaud);

  Serial.println("Succesfully initialize gps");
}
