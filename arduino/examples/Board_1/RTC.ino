/*
  Sketch name: RTC DS1307 Display with Date
  UNED In4Labs - Perception Lab.

  This code demonstrates the usage of a DS1307 RTC module.
  The current date and time are displayed on the LCD.

  The DS1307 RTC module communicates over the I2C bus.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <I2C_RTC.h>

// LCD
LiquidCrystal_I2C lcd(0x3F, 16, 2); // address, columns, rows

// RTC
DS1307 rtc;

void setup() {
    // Init LCD
    lcd.init();
    lcd.backlight();
    lcd.clear();

    // Initialize the RTC
    if (!rtc.begin()) {
        lcd.print("RTC init failed!");
        while (1);
    }

    // Set RTC to the compile time
    rtc.setDateTime(__DATE__, __TIME__);
}

// Function to print the numbers with leading zeros
void printDigits(int digits) {
    // Print a leading zero if the value is less than 10
    if (digits < 10) {
        lcd.print("0");
    }
    lcd.print(digits);
}

void loop() {
    // Get current date and time
    uint8_t day = rtc.getDay();
    uint8_t month = rtc.getMonth();
    uint16_t year = rtc.getYear();
    uint8_t hours = rtc.getHours();
    uint8_t minutes = rtc.getMinutes();
    uint8_t seconds = rtc.getSeconds();

    // Print date and time
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(year);
    lcd.print("-");
    printDigits(month);
    lcd.print("-");
    printDigits(day);

    lcd.setCursor(0, 1);    
    printDigits(hours);
    lcd.print(":");
    printDigits(minutes);
    lcd.print(":");
    printDigits(seconds);
    lcd.print("Z");
        

    delay(1000); // Update every second
}
