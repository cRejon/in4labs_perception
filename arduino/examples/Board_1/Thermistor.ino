/*
  Sketch name: Thermistor 
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a thermistor connected to pin A10.
  The analog value read from the sensor is converted to temperature and displayed on the LCD.

  Circuit:
    - Thermistor connected to A2.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define THERMISTOR_PIN A2  // define pin for the thermistor

// Parameters for the thermistor calculation
#define R_NOMINAL 10000    // resistance at 25 degrees C
#define TEMP_NOMINAL 25    // temp. for nominal resistance (almost always 25 C)
#define B_COEFF 3435       // The beta coefficient of the thermistor (usually 3000-4000)
#define R_SERIE 10000      // the value of the 'other' resistor in the voltage divider

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup(){
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop(){
  float signal = analogRead(THERMISTOR_PIN);
  float resistance = (float)(1023 - signal) * R_SERIE / signal; //get the resistance of the sensor

  // Steinhart-Hart thermistor Equation
  float temperature = 1.0/(log(resistance/R_NOMINAL)/B_COEFF+1/(TEMP_NOMINAL+273.15))-273.15;
    
  // Print the temperature
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print(" C");

  delay(2000);  // delay for 2 seconds
}