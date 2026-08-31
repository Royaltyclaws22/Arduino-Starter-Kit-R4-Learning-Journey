/* 
Arduino Starter Kit R4
Project 11: Knock Lock
*/

#include <Servo.h>

// Hardware Object
Servo lockServo;

// Pin Definitions
const int PIEZO_PIN = A0;
const int LOCK_BUTTON_PIN = 2;

const int YELLOW_LED_PIN = 3;
const int GREEN_LED_PIN = 4;
const int RED_LED_PIN = 5;

const int SERVO_PIN = 9;

// Knock Detection Thresholds
const int QUIET_KNOCK_THRESHOLD = 10;
const int LOUD_KNOCK_THRESHOLD = 100;

// Global Variables
int knockValue;
int lockButtonState;

bool isLocked = false;
int validKnockCount = 0;

// Function Prototype
bool checkForKnock(int knockStrength);

void setup() {

  // Attach the servo motor
  lockServo.attach(SERVO_PIN);

  // Configure LED pins
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Configure the lock button
  pinMode(LOCK_BUTTON_PIN, INPUT);

  // Initialize serial communication
  Serial.begin(9600);

  // Start with the box unlocked
  digitalWrite(GREEN_LED_PIN, HIGH);
  lockServo.write(0);

  Serial.println("The box is unlocked!");
}

void loop() {

  // Lock the box when the button is pressed
  if (!isLocked) {

    lockButtonState = digitalRead(LOCK_BUTTON_PIN);

    if (lockButtonState == HIGH) {

      isLocked = true;

      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);

      lockServo.write(90);

      Serial.println("The box is locked!");

      delay(1000);
    }
  }

  // Listen for knocks while the box is locked
  if (isLocked) {

    knockValue = analogRead(PIEZO_PIN);

    if (validKnockCount < 3 && knockValue > 0) {

      if (checkForKnock(knockValue)) {
        validKnockCount++;
      }

      Serial.print(3 - validKnockCount);
      Serial.println(" more knocks to go");
    }

    // Unlock after three valid knocks
    if (validKnockCount >= 3) {

      isLocked = false;

      lockServo.write(0);
      delay(20);

      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);

      Serial.println("The box is unlocked!");

      validKnockCount = 0;
    }
  }
}

// Validate the detected knock
bool checkForKnock(int knockStrength) {

  if (knockStrength > QUIET_KNOCK_THRESHOLD && knockStrength < LOUD_KNOCK_THRESHOLD) {

    // Flash the yellow LED for a valid knock
    digitalWrite(YELLOW_LED_PIN, HIGH);
    delay(50);
    digitalWrite(YELLOW_LED_PIN, LOW);

    Serial.print("Valid knock. Value: ");
    Serial.println(knockStrength);

    return true;
  } else {

    Serial.print("Invalid knock. Value: ");
    Serial.println(knockStrength);

    return false;
  }
}