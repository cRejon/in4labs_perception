/*
  Sketch name: Barometer
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of the BMP085 barometer sensor with the Seeed Studio library.
  Temperature and pressure readings are obtained every 2 seconds and displayed on the LCD.

  The BMP085 sensor communicates over the I2C bus.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "BMP085.h"

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

// BMP085
BMP085 barometer;

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the BMP085 sensor
  barometer.init();
}

void loop() {
  // Read temperature and pressure
  float temperature = barometer.bmp085GetTemperature(barometer.bmp085ReadUT()); //Get the temperature, bmp085ReadUT MUST be called first
  float pressure = barometer.bmp085GetPressure(barometer.bmp085ReadUP());      //Get the pressure

  // Print temperature and pressure
  lcd.clear();
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(pressure);
  lcd.print(" Pa");

  delay(2000);

  // Exercise: Get the altitude from the pressure reading and the pressure in Atmosphere with 4 decimal places
}
