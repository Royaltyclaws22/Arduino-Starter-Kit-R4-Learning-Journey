/* 
Arduino Starter Kit R4
Project 13: Hacking Buttons
*/

// Define the optocoupler output pin
const int OPTOCOUPLER_PIN = 2;

void setup() {

  // Configure the optocoupler pin as an output
  pinMode(OPTOCOUPLER_PIN, OUTPUT);
}

void loop() {

  // Turn the optocoupler on
  digitalWrite(OPTOCOUPLER_PIN, HIGH);

  // Keep it on for 30 milliseconds
  delay(30);

  // Turn the optocoupler off
  digitalWrite(OPTOCOUPLER_PIN, LOW);

  // Wait 10 seconds before repeating
  delay(10000);
}