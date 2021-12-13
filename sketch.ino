/*
 * Created for Edge Computing
 * 
 */


void setup() {
  // put your setup code here, to run once:
  InitializeGyroscope();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("I'm inside the loop");   
  //getGyroscopeData();
  delay(1000);
}
