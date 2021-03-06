#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

int initPitch;
int initRoll;

void InitializeGyroscope() {
  if (!gyroscopeConnected) {
    return;
  }
  Serial.println("Info: Initialize MPU6050");

  if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("Info: Failed to initialize MPU6050");
  } else {
    Serial.println("Info: Succesfully initialize MPU6050");

    Vector normAccel = mpu.readNormalizeAccel();



    // Calculate Pitch & Roll start values
    initPitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis * normAccel.YAxis + normAccel.ZAxis * normAccel.ZAxis)) * 180.0) / M_PI;
    initRoll = (atan2(normAccel.YAxis, sqrt(normAccel.XAxis * normAccel.XAxis + normAccel.ZAxis * normAccel.ZAxis)) *180 / M_PI);
  }
}

void getGyroscopeData() {
  if (!gyroscopeConnected) {
    return;
  }
  // Get the normalized values
  Vector normAccel = mpu.readNormalizeAccel();



  // Calculate Pitch & Roll
  //Subtract init Pitch and roll because of normalization ( Ex. if the module was at a 30° angle on start it should be subracted from the normalized pitch to get a relative pitch or roll)
  //Just basic math ;)
  int pitch = ((-(atan2(normAccel.XAxis, sqrt(normAccel.YAxis * normAccel.YAxis + normAccel.ZAxis * normAccel.ZAxis)) * 180.0) / M_PI) - initPitch);
  int roll = ((atan2(normAccel.YAxis, sqrt(normAccel.XAxis * normAccel.XAxis + normAccel.ZAxis * normAccel.ZAxis)) *180 / M_PI) - initRoll);
  

  // Output
  Serial.print("roll: ");
  Serial.print(roll % 180);
  Serial.print(" | ");
  Serial.print("pitch: ");
  Serial.print(pitch % 180);
  Serial.print(" | ");
}
