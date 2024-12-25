#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (change the address 0x27 to your I2C LCD address)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
int soilSensorPin = A0;  // Soil moisture sensor pin
int pirPin = 7;          // PIR sensor pin
int buzzerPin = 8;       // Buzzer pin

// Variables
int soilValue = 0;       // Variable to store soil moisture value
int pirState = LOW;      // Variable to store PIR state

void setup() {
  // LCD setup
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000); // Wait for LCD to initialize

  // Serial monitor setup (optional)
  Serial.begin(9600);

  // PIR and buzzer setup
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil & Motion");
  delay(500); // Give PIR sensor time to stabilize
}

void loop() {
  // Read soil moisture
  soilValue = analogRead(soilSensorPin);
  int moisturePercent = map(soilValue, 0, 1023, 0, 100);

  // Read PIR sensor
  pirState = digitalRead(pirPin);

  // Debugging: Print PIR state to Serial Monitor
  Serial.print("PIR State: ");
  Serial.println(pirState);

  // Control buzzer based on motion
  if (pirState == HIGH) {
    digitalWrite(buzzerPin, HIGH); // Turn buzzer on
    delay(500);                    // Keep buzzer on for 500ms
    digitalWrite(buzzerPin, LOW);  // Turn buzzer off
  }

  // Display data on LCD only if motion state has changed
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   "); // Clear extra characters

  lcd.setCursor(0, 1);
  if (pirState == HIGH) {
    lcd.print("Motion Detected ");
  } else {
    lcd.print("No Motion       ");
  }

  // Print soil moisture to Serial Monitor (optional)
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(500); // Update every 0.5 seconds
}
