/* 
Arduino Starter Kit R4
Project 10: Crystal Ball
*/

#include <LiquidCrystal.h>

// Create the LCD object and define its Arduino pin connections (RS, E, D4-D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin Definition
const int SWITCH_PIN = 6;

// Global Variables
int switchState = 0;
int previousSwitchState = 0;
int reply;

void setup() {

  // Initialize the LCD
  lcd.begin(16, 2);

  // Configure the switch pin
  pinMode(SWITCH_PIN, INPUT);

  // Display the welcome message
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {

  // Read the current tilt sensor state
  switchState = digitalRead(SWITCH_PIN);

  // Check if the switch state has changed
  if (switchState != previousSwitchState) {

    // Generate a random prediction when the tilt sensor is shaken
    if (switchState == LOW) {

      // Select one of eight possible responses
      reply = random(8);

      // Clear the display
      lcd.clear();

      // Print the header
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");

      // Print the selected response
      lcd.setCursor(0, 1);

      switch (reply) {
        case 0:
          lcd.print("Yes");
          break;

        case 1:
          lcd.print("Most likely");
          break;

        case 2:
          lcd.print("Certainly");
          break;

        case 3:
          lcd.print("Outlook good");
          break;

        case 4:
          lcd.print("Unsure");
          break;

        case 5:
          lcd.print("Ask again");
          break;

        case 6:
          lcd.print("Doubtful");
          break;

        case 7:
          lcd.print("No");
          break;
      }
    }
  }

  // Save the current switch state
  previousSwitchState = switchState;
}
