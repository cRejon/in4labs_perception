/*
 *
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN	6    //Pin 5 para el reset del RC522
#define SS_PIN	53   //Pin 53 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); //Creamos el objeto para el RC522

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	Serial.println(F("Scan PICC to see UID"));
}

void loop() {
	if ( mfrc522.PICC_IsNewCardPresent())  // Revisamos si hay nuevas tarjetas  presentes
        {  
            if ( mfrc522.PICC_ReadCardSerial()) //Seleccionamos una tarjeta
            {
                  Serial.print("Card UID:");  // Enviamos serialemente su UID
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                  } 
                  Serial.println();
                  mfrc522.PICC_HaltA(); // Terminamos la lectura de la tarjeta  actual     
            }      
	}	
}