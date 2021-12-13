/*
   Created for Edge Computing

*/

//Disable if module is not connected (Testing only)
bool gyroscope = true;


void setup() {
  Serial.begin(115200);

  if (gyroscope) {
    InitializeGyroscope();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I'm inside the loop");
  if (gyroscope) {
    getGyroscopeData();
  }

  delay(1000);
}
