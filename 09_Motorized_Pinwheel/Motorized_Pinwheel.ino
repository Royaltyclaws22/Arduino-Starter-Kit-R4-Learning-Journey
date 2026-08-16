/* 
Arduino Starter Kit R4
Project 09: Motorized Pinwheel
*/

// Pin Definitions
const int SWITCH_PIN = 2;
const int MOTOR_PIN = 9;

// Stores the current state of the pushbutton
int switchState = LOW;

void setup() {
  // Configure the motor pin as an output
  pinMode(MOTOR_PIN, OUTPUT);

  // Configure the pushbutton pin as an input
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {

  // Read the current state of the pushbutton
  switchState = digitalRead(SWITCH_PIN);

  // Turn the motor on while the switch is pressed
  if (switchState == HIGH) {
    digitalWrite(MOTOR_PIN, HIGH);
  }
  // Otherwise, turn the motor off
  else {
    digitalWrite(MOTOR_PIN, LOW);
  }
}