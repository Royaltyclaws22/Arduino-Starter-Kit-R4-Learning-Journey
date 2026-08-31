# 🔒 Knock Lock

In this project, I built an Arduino Knock Lock that uses a *piezo capsule* to detect valid knocks and a *servo motor* to simulate a simple locking mechanism.

This project is based on Project 11 from the Arduino Starter Kit R4.

---

## 🔎 Circuit Demo

<img src="images/knock_lock_circuit.gif" height="800" width="100%">

---

## 🎯 Objective

The purpose of this project is to understand how a *piezo element* can also be used as an input and to practice writing my own functions.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 3 x 220 Ω Resistors
- 1 x 10 kΩ Resistor
- 1 x 1 MΩ Resistor
- 1 x 100 µF Capacitor
- 1 x Red LED
- 1 x Green LED
- 1 x Yellow LED
- 1 x Pushbutton (Switch)
- 1 x Piezo Capsule
- 1 x Small Servo Motor
- 1 x Motor Arm
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project implements a knock-detecting lock mechanism using an *Arduino UNO R4 WiFi Board*. It utilizes a *Piezo Element* as an analog vibration/knock sensor, a *Pushbutton* for manual locking, three status *LEDs* *(Red, Green, Yellow)* to indicate the system state, and a *Servo Motor* to actuate the lock mechanism.

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) power rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) ground rail of the *breadboard* (Black wire)
* Jumper wires connect the power and ground rails between both sides of the *breadboard* to provide common power throughout the circuit.

### 🔘 Input Section: Pushbutton & Piezo Sensor
* **Pushbutton (Lock Trigger):**
  * One terminal connects directly to the positive ($+$) 5V power rail.
  * The opposite terminal connects to Arduino digital pin `2`.
  * The signal terminal is also connected to the common ground ($-$) rail through a *10kΩ pull-down resistor*.
* **Piezo Element (Vibration / Knock Detector):**
  * One leg connects directly to the positive ($+$) 5V power rail.
  * The other leg connects to Arduino analog input pin `A0`.
  * A *1MΩ resistor* is connected across the signal terminal and common ground ($-$) rail in parallel to establish the baseline voltage and define knock sensitivity.

### 🚦 Output Section: Status LEDs & Servo Motor
* **Status LEDs:**
  * **Cathodes (Short legs):** All connected directly to the common ground ($-$) rail.
  * **Anodes (Long legs):** Connected through *220Ω current-limiting resistors* to their respective Arduino digital pins:
    * **Yellow LED:** Arduino digital pin `3`
    * **Green LED:** Arduino digital pin `4`
    * **Red LED:** Arduino digital pin `5`
* **Servo Motor (Lock Actuator):**
  * **Power (Red wire):** Connects to the positive ($+$) 5V power rail.
  * **Ground (Black wire):** Connects to the common ground ($-$) rail.
  * **Control Signal (White wire):** Connects to Arduino digital (PWM) pin `9` .
  * **Decoupling Capacitor:** A *100µF capacitor* is placed across the power ($+$) and ground ($-$) rails near the *servo motor* connections (observing proper polarity) to smooth out voltage dips caused by *motor* movement.

### ⚠️ Safety Tip
To ensure hardware safety, the *Arduino board* is strictly kept disconnected from any power source (via the *USB-C cable*) throughout the circuit assembly process. The board is only connected to the computer via the *USB-C cable* once all physical connections and circuit designs are fully completed and verified.

---

## 📤 Setup & Upload

1. Connect your *Arduino Board* to your computer using the *USB-C Cable*.
2. Open the `.ino` file in the Arduino IDE.
3. Select the correct `Board` and `Port` from the `Tools` menu.
4. Click `Upload` to compile and upload the sketch to the board.
5. Once the upload is complete, click the `Serial Monitor` icon and the program will start running automatically.

---
