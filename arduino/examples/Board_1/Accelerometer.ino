/*
  Sketch name: Accelerometer
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of the ADXL335 3-Axis accelerometer with the Seeed Studio library.
  Acceleration readings from the X, Y, and Z axes are obtained every 1 second and
  displayed on the LCD.

  Circuit:
    - X_AXIS_PIN (A8), Y_AXIS_PIN (A9), Z_AXIS_PIN (A10) connected to the accelerometer.

  The Accelerometer_ADXL335 library provides functionality for reading and interpreting accelerometer data.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ADXL335.h"

#define X_AXIS_PIN A8  // define pins for the accelerometer axes
#define Y_AXIS_PIN A9
#define Z_AXIS_PIN A10

ADXL335 accelerometer;  // Instantiate the accelerometer

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows


void setup()
{
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Init accelerometer
  accelerometer.begin();
}

void loop()
{
  // Calculate
  int x,y,z;
  accelerometer.getXYZ(&x,&y,&z);

  // Print accelerometer values
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(x);
  lcd.setCursor(8, 0);
  lcd.print("Y:");
  lcd.print(y);
  lcd.setCursor(0, 1);
  lcd.print("Z:");
  lcd.print(z);

  delay(1000);

  // Exercise: get acceleration
}
