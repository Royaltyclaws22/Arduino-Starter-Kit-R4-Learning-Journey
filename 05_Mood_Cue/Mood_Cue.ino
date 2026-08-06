/* 
Arduino Starter Kit R4
Project 05: Mood Cue
*/

#include <Servo.h>

// Create a Servo object
Servo myServo;

// Pin configuration
const int POTENTIOMETER_PIN = A0;
const int SERVO_PIN = 9;

// Servo angle limits
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 179;

// Variables
int potentiometerValue = 0;
int servoAngle = 0;

void setup() {
  // Configure the ADC to use 12-bit resolution (0-4095)
  analogReadResolution(12);

  // Attach the servo to the selected pin
  myServo.attach(SERVO_PIN);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value
  potentiometerValue = analogRead(POTENTIOMETER_PIN);

  // Map the potentiometer reading to the servo angle range
  servoAngle = map(potentiometerValue, 0, 4095, MIN_ANGLE, MAX_ANGLE);

  // Display values in the Serial Monitor
  Serial.print("Potentiometer:  ");
  Serial.print(potentiometerValue);
  Serial.print(" | Servo Angle:  ");
  Serial.println(servoAngle);

  // Move the servo to the calculated position
  myServo.write(servoAngle);

  // Small delay to allow the servo to reach the new position
  delay(15);
}