/* 
Arduino Starter Kit R4
Project 08: Digital Hourglass
*/

const int SWITCH_PIN = 8;

// LED configuration
const int FIRST_LED = 2;
const int LAST_LED = 7;

// Timer interval (milliseconds)
// 600000 ms = 10 minutes
const unsigned long INTERVAL = 600000;

unsigned long previousTime = 0;

int currentLed = FIRST_LED;

int switchState = LOW;
int previousSwitchState = LOW;

// Turn all LEDs ON or OFF
void setAllLeds(int state) {
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    digitalWrite(pin, state);
  }
}

// Flash all LEDs twice after the timer expires
void flashAllLeds() {
  delay(1000);
  setAllLeds(LOW);

  delay(1000);
  setAllLeds(HIGH);

  delay(1000);
  setAllLeds(LOW);

  delay(1000);
  setAllLeds(HIGH);
}

void setup() {

  // Configure LED pins as outputs
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    pinMode(pin, OUTPUT);
  }

  // Configure switch pin as input
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {

  unsigned long currentTime = millis();

  // Turn on one LED after every interval
  if (currentTime - previousTime > INTERVAL) {
    previousTime = currentTime;

    digitalWrite(currentLed, HIGH);
    currentLed++;

    // Flash all LEDs when the timer reaches the end
    if (currentLed == LAST_LED + 1) {
      flashAllLeds();
    }
  }

  // Read tilt switch state
  switchState = digitalRead(SWITCH_PIN);

  // Reset the timer whenever the switch changes state
  if (switchState != previousSwitchState) {
    setAllLeds(LOW);

    currentLed = FIRST_LED;
    previousTime = currentTime;
  }

  previousSwitchState = switchState;
}
