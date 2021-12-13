#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5

MFRC522 mfrc522(SS_PIN, RST_PIN);

void InitializeRFID() {
  if (!rfidConnected) {
    return;
  }

  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Succesfully initialize rfid");
}
