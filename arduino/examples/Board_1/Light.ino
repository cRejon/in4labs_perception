/*
  Sketch name: Light
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a light sensor connected to pin A15.
  The sketch checks if the light level crosses a certain threshold and displays 
  "Light Detected" or "No Light" on the LCD.

  Circuit:
    - Light sensor connected to A15.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LIGHT_SENSOR_PIN A15  // define pin for the light sensor
#define LIGHT_THRESHOLD 500  // define the threshold for light detection

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the light sensor input pin
  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(LIGHT_SENSOR_PIN);  // read the light sensor

  // Print the sensor status
  lcd.clear();
  lcd.setCursor(0, 0);
  if (sensorValue > LIGHT_THRESHOLD) {
    lcd.print("Light Detected");
  } else {
    lcd.print("No Light");
  }

  delay(1000);
}
