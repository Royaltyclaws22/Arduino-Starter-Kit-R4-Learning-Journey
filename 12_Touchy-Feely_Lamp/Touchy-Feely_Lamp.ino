/* 
Arduino Starter Kit R4
Project 12: Touchy-Feely Lamp
*/

#include <Arduino_CapacitiveTouch.h>

// Pin Definitions
const int TOUCH_PIN = 2;
const int LED_PIN = 12;

// Capacitive Touch Settings
const int TOUCH_THRESHOLD = 4000;

// Create the capacitive touch sensor object
CapacitiveTouch touchSensor(TOUCH_PIN);

void setup() {

  Serial.begin(9600);

  // Configure the LED output pin
  pinMode(LED_PIN, OUTPUT);

  // Initialize the capacitive touch sensor
  touchSensor.begin();
  touchSensor.setThreshold(TOUCH_THRESHOLD);

  // Display the configured threshold
  Serial.print("Touch Threshold: ");
  Serial.println(touchSensor.getThreshold());
}

void loop() {

  // Read the raw capacitive touch value
  int touchValue = touchSensor.read();

  // Print the sensor reading to the Serial Monitor
  Serial.println(touchValue);

  // Turn the LED on when the sensor is touched
  if (touchSensor.isTouched()) {

    Serial.println("Touched!");
    digitalWrite(LED_PIN, HIGH);

  } else {

    digitalWrite(LED_PIN, LOW);
  }

  // Small delay for stable readings
  delay(10);
}