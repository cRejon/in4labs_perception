/*
  Sketch name: Gas
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of the MQ2 gas sensor.
  The voltage at the MQ2 is read every second and displayed on the LCD.

    Circuit:
    - MQ2 sensor connected to A5.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // address, columns, rows

// Gas sensor
const int gasPin = A5;

void setup()
{
    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void loop()
{
	int valorSensor = analogRead(gasPin); // Read the value from the sensor
	float voltage = (float)(valorSensor*5.0)/1024; // Convert the value to voltage

    lcd.setCursor(0, 0);
    lcd.print("Voltage at MQ2:");
    lcd.setCursor(6,1);
    lcd.print(voltage);

    // Wait
    delay(1000);
}
