/* 
Arduino Starter Kit R4
Project 06: Light Theremin
*/

// Global Variables
int sensorValue;
int sensorLow = 4095;
int sensorHigh = 0;

// Pin Configuration
const int LED_PIN = 13;

void setup() {
  // Configure the ADC to use 12-bit resolution (0–4095)
  analogReadResolution(12);

  // Configure the calibration LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // Sensor Calibration (first 5 seconds)
  while (millis() < 5000) {
    sensorValue = analogRead(A0);

    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  // Turn off the calibration LED
  digitalWrite(LED_PIN), LOW);
}

void loop() {
  // Read the sensor value
  sensorValue = analogRead(A0);

  // Map the sensor reading to an audible frequency
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // Generate the corresponding tone
  tone(8, pitch, 20);

  // Small delay for stable operation
  delay(10);
}