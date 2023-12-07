/**
 * UNED - Departamento de Ingenieria Electrica, Electronica y de Control
 * Sketch name: LCD Text
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup()
{
    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.display();
    lcd.clear();

    // Print a message in the LCD
    lcd.setCursor(2,0);
    lcd.print("Text Example");
    lcd.setCursor(5,1);
    lcd.print("in LCD");
}

void loop()
{
    // Do nothing
}