#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;

void InitializeGyroscope() {
  Serial.begin(115200);
  Serial.println("Initialize MPU6050");

  if (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("Failed to initialize MPU6050");
  } else {
    Serial.println("Succesfully initialize MPU6050");
  }
}

void getGyroscopeData() {
  // Get the normalized values
  Vector normAccel = mpu.readNormalizeAccel();

  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis * normAccel.YAxis + normAccel.ZAxis * normAccel.ZAxis)) * 180.0) / M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis) * 180.0) / M_PI;

  // Output
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);
  Serial.println();
}
