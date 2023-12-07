/*
  Sketch name: Barometer
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of the BMP280 barometer sensor with the Seeed Studio library.
  Temperature and pressure readings are obtained every 2 seconds and displayed on the LCD.

  The BMP280 sensor communicates over the I2C bus.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Seeed_BMP280.h>

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

// BMP280
BMP280 bmp280;

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the BMP280 sensor
  if(!bmp280.init()){
    lcd.print("BMP280 init fail");
    while(1);
  }
}

void loop() {
  // Read temperature and pressure
  float temp = bmp280.getTemperature();
  uint32_t pressure = bmp280.getPressure();

  // Print temperature and pressure
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Pres:");
  lcd.print(pressure);
  lcd.print(" Pa");

  delay(2000);

  // Exercise: Get the altitude from the pressure reading
}
