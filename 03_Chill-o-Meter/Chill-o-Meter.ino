/* 
Arduino Starter Kit R4
Project 03: Chill-o-Meter
*/

const int SENSOR_PIN = A0;

const int LED1_PIN = 2;
const int LED2_PIN = 3;
const int LED3_PIN = 4;

// Baseline temperature (°C) from which the LEDs start turning on
const float BASELINE_TEMPERATURE = 33.98;

void setup() {
  Serial.begin(9600);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
}

void loop() {

  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(SENSOR_PIN);

  // Convert the ADC reading to voltage
  float voltage = (sensorValue / 1024.0) * 5.0;

  // Convert the voltage to temperature (TMP36)
  float temperature = (voltage - 0.5) * 100.0;

  // Display the measured values
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print(" V");

  Serial.print(" | Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Turn LEDs on according to the measured temperature
  if (temperature < BASELINE_TEMPERATURE + 2) {

    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);

  } else if (temperature < BASELINE_TEMPERATURE + 4) {

    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);

  } else if (temperature < BASELINE_TEMPERATURE + 6) {

    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, LOW);

  } else {

    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
  }

  delay(1);
}