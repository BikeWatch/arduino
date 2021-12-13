/*
   Created for Edge Computing

*/

//Disable if module is not connected (Testing only)
bool gyroscopeConnected = false;
bool gpsConnected = true;


void setup() {
  Serial.begin(115200);


  InitializeGyroscope();


  InitializeGPS();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I'm inside the loop");

  getGyroscopeData();


  delay(1000);
}
