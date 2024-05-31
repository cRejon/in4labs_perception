/**
 * UNED - Departamento de Ingenieria Electrica, Electronica y de Control
 * Sketch name: Gas
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

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
	int valorSensor = analogRead(gasPin); //Se lee el valor analógico del sensor
	float voltage = (float)(valorSensor*5.0)/1024; //Se calcula el valor de tensión del MQ2

    lcd.setCursor(0,0);
    lcd.print("Voltage at MQ2:");
    lcd.setCursor(6,1);
    lcd.print(voltage);

    // Wait
    delay(1000);
}
