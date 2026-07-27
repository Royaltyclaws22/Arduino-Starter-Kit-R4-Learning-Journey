/* 
Arduino Starter Kit R4
Project 02: Spaceship Interface 
*/

// Pin definitions
const int BUTTON_PIN = 2;
const int GREEN_LED = 3;
const int RED_LED_1 = 4;
const int RED_LED_2 = 5;

// Blink interval (milliseconds)
const int BLINK_DELAY = 250;

// Variable to store the current button state
int buttonState = LOW;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED_1, OUTPUT);
  pinMode(RED_LED_2, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {

  // Read the pushbutton state
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {

    // Button not pressed
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED_1, LOW);
    digitalWrite(RED_LED_2, LOW);

  } else {

    // Button pressed
    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RED_LED_1, LOW);
    digitalWrite(RED_LED_2, HIGH);
    delay(BLINK_DELAY);

    digitalWrite(RED_LED_1, HIGH);
    digitalWrite(RED_LED_2, LOW);
    delay(BLINK_DELAY);
  }
}