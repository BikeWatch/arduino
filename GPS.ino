#include <TinyGPS++.h>
#include <SoftwareSerial.h>

int RXPin = 3;
int TXPin = 2;

int GPSBaud = 9600;

TinyGPSPlus gps;

SoftwareSerial gpsSerial(3, 2);

void InitializeGPS() {
  if (!gpsConnected) {
    return;
  }
  Serial.println("Info: Initialize GPS");

  gpsSerial.begin(GPSBaud);

  Serial.println("Info: Succesfully initialize gps");
}


void getGPSData() {
  // This sketch displays information every time a new sentence is correctly encoded.
  while (gpsSerial.available() > 0){
    gps.encode(gpsSerial.read());
      
    //Serial.println("Inside while");
  }
    

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
//  if (millis() > 5000 && gps.charsProcessed() < 10)
//  {
//    Serial.println("No GPS detected");
//    while(true);
//  }
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
    Serial.print("lat: None | long: None | alt: None | ");
  }

  Serial.print("date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.year());
     Serial.print(" | ");
  }
  else
  {
    Serial.print("date: None | ");
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
     Serial.print(" | ");
  }
  else
  {
    Serial.print("time: None | ");
  }

  if(gps.speed.isValid()){
    Serial.print("speed: ");
    Serial.print(gps.speed.kmph());
    Serial.print(" | ");
  }else{
    Serial.print("speed: None | ");
  }
  //Serial.println("DONE");
//  delay(1000);
}
