/*
  Sketch name: PIR
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a PIR sensor connected to pin 4.
  The sketch detects motion and displays "Motion Detected" or "No Motion" on the LCD.

  Circuit:
    - PIR sensor connected to digital pin 4.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIR_SENSOR_PIN 28  // define pin for the PIR sensor

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the PIR sensor input pin
  pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {
  int sensorValue = digitalRead(PIR_SENSOR_PIN);  // read the PIR sensor

  // Print the sensor status
  lcd.clear();
  if (sensorValue == HIGH) {
    lcd.print("Motion Detected");
  } else {
    lcd.print("No Motion");
  }

  // Shorter delay for responsive detection
  delay(500);  
}

