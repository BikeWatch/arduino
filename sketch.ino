/*
   Created for Edge Computing
   Created by Steffen Gemin
*/

const int delayTime = 1000;

//Disable if module is not connected (Testing only)
const bool gyroscopeConnected = true;
const bool gpsConnected = true;
const bool rfidConnected = true;


void setup() {
  Serial.begin(115200);

  //Initialize Components
  InitializeGyroscope();
  InitializeGPS();
  InitializeRFID();

}

void loop() {
  //Serial.println("__________________");

  //Component logic
  getGyroscopeData();
  getGPSData();
  getRFIDData();
  
  Serial.println();
  delay(delayTime);
}
