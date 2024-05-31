/*
  Sketch name: Ultrasonic Sensor
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of an ultrasonic sensor for distance measurement.
  Distance is measured in centimeters and displayed on the LCD.

  Circuit:
    - Ultrasonic sensor's TRIG and ECHO pins connected to digital pins 22 and 23 respectively.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 22        // define pin for TRIG
#define ECHO_PIN 23        // define pin for ECHO

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize ultrasonic sensor pinS
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

long measureDistance() {
  // Ensure pin is LOW before the measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting it HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  //delayMicroseconds(5);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the length of the echo pulse
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  // Speed of sound is 340 m/s or 29 microseconds per centimeter and the ping travels out 
  // and back, so to find the distance of the object we take half of the distance travelled.
  long distance = duration / 29 / 2;

  return distance;
}

void loop() {
  long distance = measureDistance();

  // Print the distance
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(1000);  // Delay for 1 second
}
