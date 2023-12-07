/*
  Sketch name: Flame
  UNED In4Labs - Perception Lab.

  This code demonstrates reading from a flame sensor connected to pin A5.
  The analog value read from the sensor is displayed on the LCD every 1 second.

  Circuit:
    - Flame sensor connected to A5.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FLAME_SENSOR_PIN A5  // define pin for the flame sensor

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);  // address, columns, rows

void setup() {
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initialize the flame sensor input pin
  pinMode(FLAME_SENSOR_PIN, INPUT);
}

void loop()
{
	float A = 1023.0/5; // input voltage corresponding to 1V
	float B = 1023.0*(4.8/5); // input voltage corresponding to 4.8V

	int flameVal = analogRead(FLAME_SENSOR_PIN); // read the analog value from sensor

    if(flameVal < A){ // if the input voltage is less than 1V, there is no fire
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("No fire");
    }else if (flameVal < B){ // if the input voltage is less than 4.8V, there is a fire nearby
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("Fire nearby");
    }else{ // if the input voltage is greater than 4.8V, there is a fire very close
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("Fire very");
        lcd.setCursor(5,1);
        lcd.print("close");
    }

    delay(1000);
}
