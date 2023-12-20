/*
  Sketch name: Line Finder
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a Line Finder sensor every second.
  If the sensor detects a black line, it displays "Black Line" on the LCD.
  If the sensor does not detect a black line, it displays "No Black Line".

  Circuit:
    - Line Finder sensor connected to digital pin 51.
*/


#include <LiquidCrystal_I2C.h>

#define LINE_SENSOR_PIN 51   // Line Finder pin

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup()
{
    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.display();

    pinMode(LINE_SENSOR_PIN, INPUT);
}

void loop()
{
    if (digitalRead(LINE_SENSOR_PIN) == HIGH)
    {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Black Line");
    }
    else
    {
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("No Black Line");
    }

    // Wait
    delay(1000);
}
