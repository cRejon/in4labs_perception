/*
  Sketch name: Temperature & Humidity
  UNED In4Labs - Perception Lab.

  Basic code that demonstrates the usage of the DHT sensor library,
  readings will be obtained from DHT22 every 2 seconds and
  displayed on the LCD.


  Circuit:
    - DHT22_PIN (pin 2) connected to sensor data line.

  Humidity is read as relative humidiy 5% - 99%
  Temperature is read in Celsius (or Fahrenheit if selected) -40ºC to 80ºC
  Sensor values can be read into float or String variables.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHT22_PIN 12                // Define the type data pin
#define DHTType DHT22               // Define the DHT sensor (DHT11, DHT21, or DHT22)

DHT dht = DHT(DHT22_PIN, DHTType);  // Instantiate the dht class with our data pin and DHT type.
float temperature;                  // Variables to store the temperature and humidity values
float humidity;        

// LCD
LiquidCrystal_I2C lcd(0x3F,16,2);   // address, columns, rows


void setup()
{
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear(); 

  // Init DHT22 
  dht.begin();  
}

void loop()
{
  temperature = dht.readTemperature();  // read temperature
  humidity = dht.readHumidity();        // read humidity

  // Print temperature and humidity
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(1, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);
}
