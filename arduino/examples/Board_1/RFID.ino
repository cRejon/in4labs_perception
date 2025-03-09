/*
  Sketch name: RFID
  UNED In4Labs - Perception Lab.

  This code demonstrates how to read the UID of a 
  RFID card using the MFRC522 library.

  Circuit:
    - RFID RC522 connected to pins 6 and 53.
    - LCD connected to I2C pins.
*/

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RST_PIN	6    // Pin 6 for RC522 reset 
#define SS_PIN	53   // Pin 53 for RC522 SS (SDA


MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 object
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // address, columns, rows

// Helper function for retrieving card UID
String getCardUID() {
    String cardUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        cardUID += mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ";
        cardUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    return cardUID;
}

void setup() {
    SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522

    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scanning PICC");
    lcd.setCursor(0, 1);
    lcd.print("to see UID");
  	delay(4000);
}

void loop() {
    if (mfrc522.PICC_IsNewCardPresent())  // Check if there are new cards present
    {  
        if (mfrc522.PICC_ReadCardSerial()) // Select a card
        {
            String cardUID = getCardUID();
            mfrc522.PICC_HaltA(); // Finish reading the current card  
            
            // Show the UID on the LCD
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Card UID:");
            lcd.setCursor(0, 1);
            lcd.print(cardUID);
        }      
    }
    
    delay(2000);
}