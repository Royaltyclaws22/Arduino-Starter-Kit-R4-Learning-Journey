/* 
Arduino Starter Kit R4
Project 07: Keyboard Instrument
*/

// Note Frequencies (Hz)
const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;

const int notes[] = {
  NOTE_C4,
  NOTE_D4,
  NOTE_E4,
  NOTE_F4
};

// Pin Definitions
const int BUTTONS_PIN = A0;
const int PIEZO_PIN = 8;

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {

  // Read the analog value from the button resistor ladder
  int keyValue = analogRead(BUTTONS_PIN);

  // Print the measured value to the Serial Monitor
  Serial.println(keyValue);

  // Play a different note depending on the measured value
  if (keyValue >= 1021 && keyValue <= 1023) {
    tone(PIEZO_PIN, notes[0]);  // C4
  } else if (keyValue >= 990 && keyValue <= 1022) {
    tone(PIEZO_PIN, notes[1]);  // D4
  } else if (keyValue >= 495 && keyValue <= 515) {
    tone(PIEZO_PIN, notes[2]);  // E4
  } else if ((keyValue >= 1 && keyValue <= 8) || (keyValue >= 13 && keyValue <= 25)) {
    tone(PIEZO_PIN, notes[3]);  // F4
  } else {
    // No valid button detected
    noTone(PIEZO_PIN);
  }
}