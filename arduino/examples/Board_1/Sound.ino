/*
  Sketch name: Sound Sensor
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a sound sensor connected to pin A0.
  The sketch checks if the sound level crosses a certain threshold and displays 
  "Sound Detected" or "No Sound" on the LCD.

  Circuit:
    - Sound sensor connected to A7.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SOUND_SENSOR_PIN A0  // define pin for the sound sensor
#define SOUND_THRESHOLD 400   // define the threshold for sound detection

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the sound sensor input pin
  pinMode(SOUND_SENSOR_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(SOUND_SENSOR_PIN);  // read the sound sensor

  // Print the sensor status
  lcd.clear();
  lcd.setCursor(0, 0);
  if (sensorValue > SOUND_THRESHOLD) {
    lcd.print("Sound Detected");
  } else {
    lcd.print("No Sound");
  }

  delay(1000);  // Delay for 1 second

  // Exercise: Modify the code to sample the sound sensor N_SAMPLES times and
  //           calculate the average value. Then, compare the average value
  //           to the threshold.
}
