# 🌡️ Chill-o-Meter

In this project, I built a simple Arduino-based temperature monitoring system that uses a TMP36 sensor to measure temperature and three LEDs to visually indicate changes relative to a predefined baseline.

This project is based on Project 03 from the Arduino Starter Kit R4. 

---

## 🔎 Circuit Demo
<img src="images/chill-o-meter_circuit.gif" height="800" width="100%">

---

## 🎯 Objective

The purpose of this project is to learn how to read and process analog sensor data using the Arduino board's built-in Analog-to-Digital Converter (ADC), display the measurements in the Serial Monitor, and control LEDs based on temperature.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 3x 220 Ohm Resistor
- 3x Red LED
- 1x TMP36 Temperature Seensor 
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project demonstrates a temperature monitoring system using an *Arduino UNO R4 WiFi Board* to measure temperature changes via a *TMP36 Temperature Sensor* and display temperature levels using three *LED* indicators.

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) rail of the *breadboard* (Black wire)

### 💡 Output Section: LED Indicators
Three *red LEDs* are placed on the *breadboard* to serve as visual threshold indicators.

* **Ground Connections:** For every individual *LED*, a *220Ω resistor* connects its cathode (short leg) directly to the common ground ($-$) rail of the *breadboard*.
* **Signal Lines (Digital Pins):**
  * The anodes (long legs) of the three *LEDs* connect to Arduino digital pins 2, 3, and 4, respectively.

### 🌡️ Input Section: TMP36 Temperature Sensor 
A *TMP36 Temperature Sensor* acts as the primary analog input component.

* **Orientation:** Inserted into the *breadboard* with its flat side facing forward / toward the user (rounded side facing away from the board).
* **Power Connection:** The left pin (with the flat side facing the user) connects directly to the positive ($+$) power rail.
* **Ground Connection:** The right pin connects directly to the common ground ($-$) rail.
* **Signal Connection:** The middle pin connects directly to Arduino analog input pin *A0* (Analog Pin 0) via a signal jumper wire.

### ⚠️ Safety Tip
To ensure hardware safety, the *Arduino board* is strictly kept disconnected from any power source (via the *USB-C cable*) throughout the circuit assembly process. The board is only connected to the computer via the *USB-C cable* once all physical connections and circuit designs are fully completed and verified.

---

## 📤 Setup & Upload

1. Connect your *Arduino Board* to your computer using the *USB-C Cable*.
2. Open the `.ino` file in the Arduino IDE.
3. Select the correct `Board` and `Port` from the `Tools` menu.
4. Click `Upload` to compile and upload the sketch to the board.
5. Once the upload is complete, click the `Serial Monitor` icon and the program will start running automatically.

You can update the `BASELINE_TEMPERATURE` constant in your sketch with the ambient temperature value you observe.

---

## ⚙️ How it Works

The circuit operates as a dynamic temperature-sensing indicator based on the analog voltage reading from the TMP36 sensor:

* **Idle / Baseline State (Sensor Un-touched):** 
  * The sensor measures the baseline ambient room temperature.
  * When the temperature is low (at or near ambient temperature), all three *LEDs* (pins 2, 3 & 4) remain turned `OFF`.

* **Low Temperature Rise (1 LED ON):**
  * When you touch the sensor and the detected temperature slightly increases past the first threshold:
  * The first *LED* (pin 2) turns `ON`, indicating a mild temperature rise.
  * The remaining two *LEDs* stay `OFF`.

* **Moderate Temperature Rise (2 LEDs ON):**
  * As heat transfers from your fingers and the temperature reaches a second higher threshold:
  * Two *LEDs* (pins 2 & 3) light up simultaneously.

* **High Temperature Rise (3 LEDs ON):**
  * When the detected temperature exceeds the maximum defined threshold:
  * All three *LEDs* (pins 2, 3 & 4) turn `ON` simultaneously, indicating peak temperature.




