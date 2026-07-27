# 🎛️ Spaceship Interface

In this project, I built a simple Arduino circuit where a pushbutton is used as an input to control the behavior of multiple LEDs through embedded programming.

This project is based on Project 02 from the Arduino Starter Kit R4. 

---

## 🔎 Circuit Demo


---


## 🎯 Objective

The purpose of this project is to understand how the board's digital pins can act as both inputs and outputs, as well as to become familiar with variables and main functions in Arduino programming.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 3x 220 Ohm Resistor
- 1x 10K Ohm Resistor
- 2x Red LED
- 1x Green LED
- 1x Pushbutton (Switch)
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project demonstrates a control panel simulation for a spaceship using an *Arduino UNO R4 WiFi Board* to monitor a *pushbutton* (*switch*) and control three *LED* indicators (one green, two red) which represent different system states (e.g., "Ready to Launch" vs. "Warning").

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) rail of the *breadboard* (Black wire)

### 💡 Output Section: LED Indicators
Two *red LEDs* and one *Green LED* are placed on the *breadboard*.

* **Ground Connections:** For every individual *LED*, a *220Ω resistor* connects its cathode (short leg) directly to the common ground ($-$) rail of the *breadboard*.
* **Signal Lines (Digital Pins):**
  * The anodes (long legs) of the two *Red LEDs* connect to Arduino pins 5 and 4, respectively.
  * The anode (long leg) of the *Green LED* connects to Arduino pin 3.
  
### 🔘 Input Section: Control Switch
A single tactile *pushbutton* acts as the primary "launch" or system trigger.

* **Power Connection:** One terminal of the *switch* is connected to the positive ($+$) power rail.
* **Signal Connection:** The opposite terminal of the *switch* connects directly to Arduino digital pin 2.
* **Pull-down Resistor:** From this same switch-pin-to-Arduino connection point, a *10kΩ resistor* is added to the common ground ($-$) rail. This pull-down *resistor* ensures the Arduino pin reads a clean `LOW` state when the *switch* is unpressed by referencing it to ground.

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

The circuit operates as an interactive system indicator based on the state of the pushbutton switch:

* **Idle State (Button Released):** 
  * Arduino reads `LOW` on pin 2.
  * The *Green LED* (pin 3) stays continuously turned `ON`, indicating system readiness.
  * Both *Red LEDs* (pins 4 & 5) remain `OFF`.

* **Single Press:** 
  * When the button is pressed once, the system executes one cycle: the *Green LED* turns off, and the two *Red LEDs* alternate blinking once (`Pin 5 HIGH` $\rightarrow$ `Pin 4 HIGH` with a 250ms delay each).
  * Immediately after, control returns to the loop, turning the *Green LED* back `ON`.

* **Continuous Press (Held Down):** 
  * As long as the button remains pressed, Arduino constantly reads `HIGH` on pin 2.
  * The system repeatedly toggles between the two *Red LEDs* (creating a continuous alternating warning effect) until the button is released.

---

## 💻 Code

The program is organized into two main functions:

- `setup()` – Configures the *LED* pins as outputs and the *pushbutton* pin as an input.
- `loop()` – Continuously reads the *pushbutton* state and controls the *LEDs*. When the button is not pressed, the *Green LED* remains on. When the button is pressed, the *Green LED* turns off and the two *Red LEDs* blink alternately.

### Key Functions Used

- `pinMode()` – Configures the mode of a pin as an input or output.
- `digitalRead()` – Reads the current state of the *pushbutton*.
- `digitalWrite()` – Turns the *LEDs* on or off.
- `delay()` – Creates the blinking effect by pausing the program for a short time.

---

## 🎓 What I Learned

Through building this project, I gained hands-on experience and practical knowledge about Arduino programming and digital electronics:

* **Arduino Inputs and Outputs**
  * Learned how to configure and use Arduino pins as inputs and outputs to interact with external components such as *pushbuttons* and *LEDs*.
* **Arduino Programming Basics**
  * Learned how to structure a simple Arduino program using variables, functions, and comments to create clean and understandable code.
  * Gained experience using essential Arduino functions such as `setup()`, `loop()`, `pinMode()`, `digitalRead()`, `digitalWrite()` and `delay()`.
* **Digital Input and Output Logic**
  * Understood how Arduino reads digital signals (`HIGH` and `LOW`) from input devices and controls output devices based on these values.
* **Uploading Code to the Arduino Board**
  * Learned how to connect the Arduino board to my computer and upload sketches using the Arduino IDE.

---

## 🚀 Future Improvements

Possible extensions for this project include:

* Add a buzzer to provide an additional audio warning when the button is pressed, creating a more realistic alarm system.
* Implement button debouncing to improve the reliability of button input readings and prevent unwanted multiple detections.
* Replace the `delay()` function with `millis()` to allow the Arduino to control the LEDs without blocking the execution of other tasks.
