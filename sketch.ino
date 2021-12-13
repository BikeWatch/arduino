/*
   Created for Edge Computing

*/

//Disable if module is not connected (Testing only)
bool gyroscopeConnected = false;
bool gpsConnected = false;
bool rfidConnected = true;


void setup() {
  Serial.begin(115200);

  //Initialize Components
  InitializeGyroscope();
  InitializeGPS();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("__________________");

  //Component logic
  getGyroscopeData();
  getGPSData();


  delay(1000);
}
