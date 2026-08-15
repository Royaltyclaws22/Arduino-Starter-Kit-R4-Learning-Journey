# ⌛ Digital Hourglass

In this project, I built an Arduino digital hourglass that lights up an *LED* every ten minutes and resets when flipped using a *tilt sensor*.

This project is based on Project 08 from the Arduino Starter Kit R4.

---

## 🔎 Circuit Demo

<img src="images/digital_hourglass_circuit.gif" height="800" width="100%">

---

## 🎯 Objective

The purpose of this project is to learn how to create a timer and understand the use of the long data type in Arduino programming.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 6 x 220 Ω Resistors
- 1 x 10 kΩ Resistor
- 6 x Red LEDs
- 1 x Tilt Sensor
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project implements a digital hourglass system using an *Arduino UNO R4 WiFi Board* to track elapsed time with a visual display of six *LEDs*, utilizing a *Tilt Sensor* to detect orientation changes and reset the timer.

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) power rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) ground rail of the *breadboard* (Black wire)

### 🔃 Input Section: Tilt Sensor
A 4-pin *tilt sensor* acts as the primary digital input mechanism to detect motion and physical orientation.

* **Power Connection:** Pins 1 & 2 (one side of the *switch*) connect directly to the positive ($+$) 5V power rail.
* **Signal & Pull-Down Connection:** 
  * Pins 3 & 4 (the opposite side of the *switch*) connect directly to Arduino digital pin `8`.
  * The same junction is also connected to the common ground ($-$) rail through a *10kΩ resistor* (acting as a pull-down *resistor* to prevent a floating state and avoid short circuits when the switch closes).

### 💡 Output Section: LED Indicators
Six *red LEDs* serve as the visual display, turning on progressively over time to represent an hourglass.

* **Signal Lines (Anodes):** The longer legs (anodes) of the six *LEDs* connect directly to Arduino digital pins `2`, `3`, `4`, `5`, `6`, and `7` respectively.
* **Ground & Current Limiting (Cathodes):** The shorter legs (cathodes) of each *LED* connect to the common ground ($-$) rail through individual *220Ω current-limiting resistors*.

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

The circuit operates as an interactive digital hourglass system that tracks elapsed time in fixed `10-minute` intervals using six *red LEDs* and allows the user to reset the cycle by physically tilting or turning over the *breadboard*:

* **Hardware Initialization (Setup Phase):**
  * Upon uploading the code and powering the board, digital pins `2` through `7` are initialized as outputs to drive the six *LEDs*.
  * Digital pin `8` is configured as an input to read the status of the *tilt sensor*.
  * The system initializes with all *LEDs* turned `OFF` and the internal timer set to start counting from zero.

* **Digital Input Sensing (Inputs):**
  * The *tilt sensor* serves as the digital input component connected directly to digital pin `8`.
  * The *Arduino UNO R4 WiFi* continuously monitors pin `8` to detect whether the circuit orientation holds a `HIGH` or `LOW` logic level.

* **Time Tracking & State Detection (Program Logic):**
  * The program continuously tracks elapsed time in the background without halting execution.
  * Every `10 minutes` (`600,000 ms`), the system advances the sequence and powers on the next *LED* (from pin `2` up to pin `7`).
  * The program constantly tracks the current orientation at pin `8` and compares it to the previous state to detect any movement.
  * Whenever a state transition occurs at the *tilt sensor*, the system immediately resets: all *LEDs* on pins `2`–`7` turn `OFF`, the sequence pointer resets to pin `2`, and the countdown timer starts from the beginning.

* **Visual Output & Completion Alert (Outputs):**
  * **Progressive Lighting:** The six *LEDs* connected to pins `2` through `7` turn on one by one at each `10-minute` milestone to represent time accumulating.
  * **Timer Expiration Alert:** Once the 6th *LED* on pin `7` turns `ON` (at the end of `1 hour`), all six *LEDs* flash twice to notify the user, then remain fully lit until the board is tilted.

* **Interactive User Behavior:**
  * **Starting the Timer:** Once the board is programmed and powered, the timer begins immediately. Check a reference clock to monitor progress; after `10 minutes`, the first *LED* on pin `2` will illuminate.
  * **Progress Tracking:** Every subsequent `10 minutes`, another *LED* turns `ON` until all six *lights* are lit at the end of `1 hour`.
  * **Hourglass Reset:** Flipping or tilting the circuit changes the internal state of the *switch*, which immediately turns `OFF` all lights and restarts the `1 hour` countdown cycle.

---

## 💻 Code

The program is organized into four main functions:

- `setAllLeds()` – Turns all *LEDs* `ON` or `OFF` by setting the same state for every *LED*.
- `flashAllLeds()` – Flashes all *LEDs* twice after the timer reaches the end of the countdown.
- `setup()` – Configures the *LED* pins as outputs and the *tilt sensor* pin as an input.
- `loop()` – Continuously tracks the elapsed time using `millis()`, lights one *LED* every ten minutes, flashes all *LEDs* when the timer expires, monitors the *tilt sensor*, and resets the timer whenever the hourglass is flipped.

### Key Functions Used

- `digitalWrite()` – Turns individual *LEDs* `ON` or `OFF`.
- `delay()` – Creates short pauses during the *LED* flashing sequence.
- `pinMode()` – Configures the *LED* pins as outputs and the *tilt sensor* pin as an input.
- `millis()` – Measures the elapsed time without blocking the program, allowing the timer to run continuously.
- `digitalRead()` – Reads the current state of the *tilt sensor* to detect when the hourglass is flipped.

---

## 🎓 What I Learned

Through building this project, I gained hands-on experience and practical knowledge about Arduino timing, digital sensors, and code organization:

* **Working with a Tilt Sensor**
  * Learned that a *tilt sensor* works like a simple on/off switch. It contains a small metal ball that rolls inside the housing when the *sensor* is tilted, connecting two internal contacts and closing the circuit.
  * Learned how to correctly identify and connect the *tilt sensor* in a circuit. It is a 4-pin component, where pins 1 & 2 are internally connected, as are pins 3 & 4. Each pair can be connected to either power or ground (GND), allowing the sensor to function as a simple switch that opens or closes the circuit depending on its orientation.
  * Understood that a *tilt sensor* is a much simpler and less expensive alternative to an accelerometer. While a *tilt sensor* can only detect orientation changes, an accelerometer provides much more detailed information about an object's movement and orientation.

* **Working with Time in Arduino**
  * Practiced using the `millis()` function to measure elapsed time without stopping the execution of the program.
  * Understood the difference between `millis()` and `delay()`, learning that `millis()` enables non-blocking timing while `delay()` pauses the entire program.

* **Understanding Data Types**
  * Learned why the `int` datatype is not suitable for long timing intervals. On Arduino, `int` is a 16-bit signed integer with a range of `-32,768` to `32,767`, which is too limited for implementing timers based on milliseconds.
  * Practiced using the `unsigned long` datatype together with `millis()`. While a `long` is a 32-bit signed integer with a range of `-2,147,483,648` to `2,147,483,647`, `unsigned long` stores only positive values, providing a range of `0` to `4,294,967,295`. This makes it the standard and most suitable datatype for implementing timers in Arduino programs.

* **Programming and Code Organization**
  * Learned to organize and simplify my code by creating reusable functions such as `setAllLeds()` and `flashAllLeds()`, making the program easier to read, maintain, and extend.

---

## 🚀 Future Improvements

Possible extensions for this project include:

- Adding an LCD/OLED display to show the remaining time and the current state of the hourglass.
- Using adjustable timer settings with buttons or a potentiometer to allow the user to select different countdown durations.
- Replacing the *tilt sensor* with an accelerometer to detect more detailed orientation changes and enable more advanced motion-based controls.
