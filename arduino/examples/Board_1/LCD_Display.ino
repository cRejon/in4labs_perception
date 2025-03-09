/*
  Sketch name: LCD Display
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of the LCD display.
  A message is displayed on the LCD.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // address, columns, rows

void setup()
{
    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.display();
    lcd.clear();

    // Print a message in the LCD
    lcd.setCursor(2, 0);
    lcd.print("Text Example");
    lcd.setCursor(5, 1);
    lcd.print("in LCD");
}

void loop()
{
    // Do nothing
}