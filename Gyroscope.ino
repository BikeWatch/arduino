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
