# 🔊 Light Theremin

In this project, I built an Arduino-based light theremin using a *phototransistor* and a *piezo element*.

This project is based on Project 06 from the Arduino Starter Kit R4.

---

## 🔎 Circuit Demo

<p align="center">
  <img src="images/light_theremin_circuit.gif" height="800" width="100%">
</p>

<p align="center">
  <a href="https://github.com/Royaltyclaws22/Arduino-Starter-Kit-R4-Learning-Journey/releases/download/v0.6/light_theremin_circuit.mp4">
    ▶ Watch Full Video (with sound)
  </a>
</p>

---

## 🎯 Objective

The purpose of this project is to learn how to calibrate analog sensors and generate sound using Arduino programming.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 1 x 10 kΩ Resistor
- 1 x Phototransistor
- 1 x Piezo Capsule
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project demonstrates a light theremin system using an *Arduino UNO R4 WiFi Board* to detect ambient light levels via a *Phototransistor* and generate corresponding audio tones using a *Piezo Element*.

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) power rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) ground rail of the *breadboard* (Black wire)

### ☀️ Input Section: Phototransistor
A *phototransistor* acts as the primary light-sensitive analog input component.

* **Power Connection:** The long leg (collector) of the *phototransistor* connects directly to the positive ($+$) power rail.
* **Signal & Pull-Down Connection:** 
  * The short leg connects directly to Arduino analog input pin `A0`.
  * The short leg is also connected to the common ground ($-$) rail through a *10kΩ resistor* to complete the voltage divider circuit.

### 🔊 Output Section: Piezo Element
A *piezo capsule* acts as the primary audio output component to produce sound based on light intensity.

* **Ground Connection:** One leg of the *piezo* connects directly to the common ground ($-$) rail.
* **Signal Line (Digital Pin):** The other leg of the *piezo* connects directly to Arduino digital pin `8`.

### ⚠️ Safety Tip
To ensure hardware safety, the *Arduino board* is strictly kept disconnected from any power source (via the *USB-C cable*) throughout the circuit assembly process. The board is only connected to the computer via the *USB-C cable* once all physical connections and circuit designs are fully completed and verified.

---

## 📤 Setup & Upload

1. Connect your *Arduino Board* to your computer using the *USB-C Cable*.
2. Open the `.ino` file in the Arduino IDE.
3. Select the correct `Board` and `Port` from the `Tools` menu.
4. Click `Upload` to compile and upload the sketch to the board.
5. Once the upload is complete, the program will start running automatically.

---

## ⚙️ How it Works

The circuit operates as an interactive light theremin system that continuously detects ambient light levels via a *phototransistor* and dynamically translates light intensity into corresponding musical pitches played through a *piezo capsule*:

* **Automatic Sensor Calibration (Setup Phase):**
  * Upon powering on, the built-in calibration LED (Pin `13`) turns `ON` to indicate that a `5-second` calibration window is active.
  * During the first `5 seconds`, the program continuously samples pin `A0` to automatically determine the minimum and maximum light thresholds in the current environment.
  * Once `5 seconds` elapse, the calibration LED turns `OFF`, signaling that calibration is complete and normal operation has started.

* **Analog Input Sensing (Inputs):** 
  * The *phototransistor* acts as an analog light sensor connected to pin `A0`.
  * The *Arduino UNO R4 WiFi* is configured for 12-bit Analog-to-Digital Conversion (ADC), reading raw light values ranging from `0` to `4095`.

* **Signal Processing & Frequency Mapping (Program Logic):**
  * During the main loop, the program continuously reads the raw light value from pin `A0`.
  * The program scales the raw light reading—bounded by the minimum and maximum light thresholds established during calibration—and translates it into an audible frequency pitch between `50 Hz` and `4000 Hz`.

* **Audio Output Generation (Output):**
  * The calculated pitch frequency is sent to the *piezo element* connected to digital pin `8` (duration set to `20ms`).
  * A small delay of `10ms` is executed at the end of each loop iteration to ensure continuous and stable tone generation.

* **Interactive User Behavior:**
  * **Calibration Phase:** Right after powering on the board, moving a hand (or an object) up and down over the *phototransistor* for `5 seconds` (while the board LED is ON) serves to register the high and low light extremes expected during play.
  * **Theremin Performance:** As soon as the calibration LED turns off, sound begins playing from the *piezo capsule*. Waving or positioning a hand above the *phototransistor* alters the amount of light hitting the sensor, dynamically changing the pitch and frequency produced in real time.

---

## 💻 Code

The program is organized into two main functions:

- `setup()` – Configures the ADC resolution, initializes the calibration LED, and calibrates the analog sensor by recording its minimum and maximum readings during the first `5 seconds`.
- `loop()` – Continuously reads the sensor value, maps it to an audible frequency, generates the corresponding tone, and adds a short delay between readings.

### Key Functions Used

- `analogReadResolution()` – Sets the ADC resolution to 12 bits, providing sensor readings from `0` to `4095`.
- `pinMode()` – Configures the calibration LED pin as an output.
- `digitalWrite()` – Turns the calibration LED on and off during sensor calibration.
- `millis()` – Measures the elapsed time since the Arduino program started.
- `analogRead()` – Reads the analog value from the *phototransistor*.
- `map()` – Maps the calibrated sensor range to an audible frequency range of `50–4000 Hz`.
- `tone()` – Generates a tone on the *piezo element* at the mapped frequency.
- `delay()` – Adds a short pause between consecutive sensor readings.

---

## 🎓 What I Learned

Through building this project, I gained hands-on experience and practical knowledge about analog sensors, sensor calibration, value mapping, and sound generation with Arduino:

* **Working with a Piezo Element**
  * Learned that a *piezo element* vibrates when an electrical signal is applied, producing sound waves by moving the surrounding air.
  * Learned how to identify a *piezo element* as a component and connect it correctly in an Arduino circuit.

* **Analog Inputs and Sensor Calibration**
  * Learned how to calibrate an analog sensor using `while` and `if` statements to automatically determine the minimum and maximum light levels in the current environment.
  * Understood why sensor calibration is useful, since a sensor may not naturally produce the full 12-bit ADC range (0–4095) under normal environmental conditions.

* **Mapping Sensor Values**
  * Gained further experience with the `map()` function by converting the calibrated light sensor readings into a usable range of audible frequencies.
  * Understood how calibration and value mapping allow raw sensor readings to be translated into meaningful output values.

* **Generating Sound with Arduino**
  * Practiced generating sound using the `tone()` function through the *piezo element*.
  * Learned how changes in the *phototransistor's* light readings can be translated into different audible pitches.

---

## 🚀 Future Improvements

Possible extensions for this project include:

- Using multiple *phototransistors* to control different aspects of the sound, such as pitch and volume.
- Adding an improved calibration process with visual feedback and an adjustable calibration time.
- Mapping the light sensor readings to specific musical notes to allow the theremin to play recognizable melodies.
