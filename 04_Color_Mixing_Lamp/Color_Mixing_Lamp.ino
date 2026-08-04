/* 
Arduino Starter Kit R4
Project 04: Color Mixing Lamp
*/

// RGB LED pins (PWM capable)
const int RED_LED_PIN = 10;
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 11;

// Analog sensor input pins
const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A1;
const int BLUE_SENSOR_PIN = A2;

// Sensor values (0-1023)
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

// LED brightness values (0-255)
int redBrightness = 0;
int greenBrightness = 0;
int blueBrightness = 0;


void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Configure RGB LED pins as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}


void loop() {
  // Read analog sensor values
  redSensorValue = analogRead(RED_SENSOR_PIN);
  delay(5);

  greenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(5);

  blueSensorValue = analogRead(BLUE_SENSOR_PIN);

  // Display raw sensor values
  Serial.print("Raw Sensor Values\tRed:   ");
  Serial.print(redSensorValue);

  Serial.print("\t\tGreen:   ");
  Serial.print(greenSensorValue);

  Serial.print("\t\tBlue:   ");
  Serial.println(blueSensorValue);


  // Convert ADC values (0-1023) to PWM values (0-255)
  redBrightness = redSensorValue / 4;
  greenBrightness = greenSensorValue / 4;
  blueBrightness = blueSensorValue / 4;


  // Display mapped PWM values
  Serial.print("PWM Values\t\tRed:   ");
  Serial.print(redBrightness);

  Serial.print("\t\tGreen:   ");
  Serial.print(greenBrightness);

  Serial.print("\t\tBlue:   ");
  Serial.println(blueBrightness);


  // Control RGB LED brightness using PWM
  analogWrite(RED_LED_PIN, redBrightness);
  analogWrite(GREEN_LED_PIN, greenBrightness);
  analogWrite(BLUE_LED_PIN, blueBrightness);
}