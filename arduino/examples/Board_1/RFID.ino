#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define RST_PIN	6    //Pin 6 para el reset del RC522
#define SS_PIN	53   //Pin 53 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

// LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // address, columns, rows

void setup() {
    SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522

    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Scanning PICC");
    lcd.setCursor(0,1);
    lcd.print("to see UID");
  	delay(4000);
}

void loop() {
    if ( mfrc522.PICC_IsNewCardPresent())  // Revisamos si hay nuevas tarjetas  presentes
    {  
        if ( mfrc522.PICC_ReadCardSerial()) //Seleccionamos una tarjeta
        {
            // Guardamos el UID de la tarjeta en un string
            String cardUID = "";
            for (byte i = 0; i < mfrc522.uid.size; i++) {
                cardUID += mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ";
                cardUID += String(mfrc522.uid.uidByte[i], HEX);   
            }
            mfrc522.PICC_HaltA(); // Terminamos la lectura de la tarjeta  actual   
            // Mostramos el UID en el LCD
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Card UID:");
            lcd.setCursor(0,1);
            lcd.print(cardUID);
            delay(2000);
            
        }      
    }   
}