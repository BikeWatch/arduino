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
  Serial.println("Info: Initialize GPS");

  gpsSerial.begin(GPSBaud);

  Serial.println("Info: Succesfully initialize gps");
}


void getGPSData() {
  if (!gpsConnected) {
    return;
  }
  
  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read()))
      displayGPSInfo();

  // If 5000 milliseconds pass and there are no characters coming in
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println();
    Serial.println("Info: Can't find gps module");
  }
}

void displayGPSInfo() {
  if (gps.location.isValid())
  {
    Serial.print("lat: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(" | ");
    Serial.print("long: ");
    Serial.print(gps.location.lng(), 6);
    Serial.print(" | ");
    Serial.print("alt: ");
    Serial.print(gps.altitude.meters());
    Serial.print(" | ");
  }
  else
  {
    Serial.println("lat: None | long: None | alt: None | ");
  }

  Serial.print("date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.println("date: None | ");
  }

  Serial.print("time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.println("time: None | ");
  }

//  Serial.print("Speed in km/h = "); 
//  Serial.println(gps.speed.kmph());
//
//  Serial.print("Altitude in meters = "); 
//  Serial.println(gps.altitude.meters());

  Serial.println();
}
