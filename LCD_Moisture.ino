#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;  // Soil moisture sensor pin
int sensorValue = 0; // Variable to store sensor value

void setup() {
  lcd.begin();
  lcd.backlight(); // Turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
  delay(1000); 
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin); // Read sensor value (0-1023)
  
  // Convert to percentage (assuming 0 = dry, 1023 = wet)
  int moisturePercent = map(sensorValue, 0, 1023, 0, 100);
  
  // Display on LCD
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   "); // Clear extra characters

  // Print to Serial Monitor
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(1000); // Update every second
}
