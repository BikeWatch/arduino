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
  delay(4);        // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println("Info: Succesfully initialize rfid");
}

void getRFIDData(){
  if (!rfidConnected) {
    return;
  }
  
  //Serial.println("Searching for card");
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("uuid: ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.print(content);
  
  //Serial.print(" | ");
}
