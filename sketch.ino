/*
   Created for Edge Computing
   Created by Steffen Gemin
*/

const int delayTime = 1000;
unsigned long delayStart = 0;
bool delayRunning = true; 

//Disable if module is not connected (Testing only)
const bool gyroscopeConnected = true;
const bool gpsConnected = false;
const bool rfidConnected = false;


void setup() {
  Serial.begin(115200);

  //Initialize Components
  InitializeGyroscope();
  InitializeGPS();
  InitializeRFID();
  delayStart = millis();

  unsigned long delayStart = 0;

}

void loop() {  
  getGPSData();
  if (((millis() - delayStart) >= delayTime)) {
    delayStart += delayTime;
    getGyroscopeData();
    displayGPSInfo();
    getRFIDData();
    Serial.println();
  }
}
