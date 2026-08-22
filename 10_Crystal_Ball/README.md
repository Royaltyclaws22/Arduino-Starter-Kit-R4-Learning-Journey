# 🔮 Crystal Ball

In this project, I built an Arduino crystal ball that tells the future using a *tilt sensor* and displays predictions on an *LCD screen*.

This project is based on Project 10 from the Arduino Starter Kit R4.

---

## 🔎 Circuit Demo

<img src="images/crystal_ball_circuit.gif" height="800" width="100%">

---

## 🎯 Objective

The purpose of this project is to learn how to display text on an *LCD screen* and practice using `switch`/`case` statements and the `random()` function when writing code.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 1 x 220 Ω Resistor
- 1 x 10 kΩ Resistor
- 1 x Tilt Sensor
- 1 x 10k ohm Potentiometer
- 1 x LCD Display (16x2 Characters)
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project demonstrates an interactive crystal ball system using an *Arduino UNO R4 WiFi Board* to detect physical orientation/shake inputs via a *Tilt Sensor (Tilt Switch)* and display text responses on a *16x2 LCD (Liquid Crystal Display)*.

### 🔌 Power Source
* **5V** on Arduino $\rightarrow$ Positive ($+$) power rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) ground rail of the *breadboard* (Black wire)

### 🔃 Input Section: Tilt Sensor
A *tilt switch* acts as the digital input component to detect movement or shaking.

* **Power Connection:** Pins 1 & 2 (one side of the *switch*) connect directly to the positive ($+$) 5V power rail.
* **Signal & Pull-Down Connection:** 
  * Pins 3 & 4 (the opposite side of the *switch*) connect directly to Arduino digital pin `6`.
  * The same leg is also connected to the common ground ($-$) rail through a *10kΩ pull-down resistor* to ensure a clean `LOW` signal when the *switch* is open.

### 📟 Output Section: 16x2 LCD Display & Potentiometer
An *16x2 LCD screen* is used in 4-bit data mode to display text, accompanied by a *10k ohm potentiometer* for screen contrast adjustment.

* **Power & Control Pins:**
  * **VSS (Pin 1):** Connects to the common ground ($-$) rail.
  * **VDD / VCC (Pin 2):** Connects directly to the positive ($+$) 5V rail.
  * **V0 (Pin 3 - Contrast):** Connects to the center wiper pin of the *potentiometer* (the outer pins of the *potentiometer* connect to the positive ($+$) 5V rail and common ground ($-$) rail).
  * **RS (Pin 4 - Register Select):** Connects to Arduino digital pin `12`.
  * **R/W (Pin 5 - Read/Write):** Connects to the common ground ($-$) rail to permanently enable write mode.
  * **E (Pin 6 - Enable):** Connects to Arduino digital pin `11`.
* **Data Bus Pins (4-bit mode):**
  * **D4 (Pin 11):** Connects to Arduino digital pin `5`.
  * **D5 (Pin 12):** Connects to Arduino digital pin `4`.
  * **D6 (Pin 13):** Connects to Arduino digital pin `3`.
  * **D7 (Pin 14):** Connects to Arduino digital pin `2`.
* **Backlight Connections:**
  * **LED+ / A (Pin 15 - Anode):** Connects to the positive ($+$) 5V rail through a *220Ω current-limiting resistor*.
  * **LED- / K (Pin 16 - Cathode):** Connects directly to the common ground ($-$) rail.

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

The circuit operates as an interactive digital fortune-teller (crystal ball) that detects physical movement or orientation changes via a *tilt switch* and dynamically displays randomized answers on a *16x2 Liquid Crystal Display (LCD)*:

* **System Initialization (Setup Phase):**
  * Upon power-up, the *Arduino UNO R4 WiFi* initializes the *16x2 LCD* in 4-bit communication mode using the `LiquidCrystal` library.
  * Digital pin `6` is configured as an input to read the state of the *tilt switch*.
  * The *LCD* immediately displays the initial greeting message across two lines: `"Ask the"` on the first row and `"Crystal Ball!"` on the second row.

* **Digital Input Sensing (Inputs):**
  * The *tilt sensor* acts as a digital *switch* connected to digital pin `6`.
  * The *sensor* outputs a `HIGH` logic level when the internal metal ball closes the circuit, and a `LOW` logic level when tilted/shaken (pulled down to ground via the *10kΩ resistor*).

* **State Change Detection & Random Decision Logic (Program Logic):**
  * The *microcontroller* continuously monitors the state of digital pin `6` on every cycle and compares it with its previous reading.
  * When a state transition is detected and the *switch* transitions to `LOW` (indicating that the *breadboard* has been tilted or shaken), the program triggers a response event.
  * The system then randomly selects one outcome out of eight predefined responses: `"Yes"`, `"Most likely"`, `"Certainly"`, `"Outlook good"`, `"Unsure"`, `"Ask again"`, `"Doubtful"`, or `"No"`.
  * The system keeps track of the last recorded state to avoid repeatedly regenerating answers while the *board* is held still in the new position.

* **Visual Output Generation (Output):**
  * Upon a valid shake/tilt event, the *LCD screen* is cleared of previous text.
  * The prompt `"The ball says:"` is written to the top line (row 0).
  * The randomly selected prediction string is printed directly on the second line (row 1).

* **Interactive User Behavior:**
  * **Power On & Contrast Adjustment:** Once powered on, verify that the *LCD screen* displays `"Ask the Crystal Ball!"`. If the characters are faint or not visible, adjust the *potentiometer* knob until the display contrast is clear and readable.
  * **Asking the Crystal Ball:** Ask a yes-or-no question out loud, then tilt the entire circuit/*breadboard* upside down and back upright. The *screen* will immediately update to reveal your fortune (e.g., `"The ball says: Most likely"`). If the answer does not suit you, simply ask again and tilt the *board* once more for a new prediction!

---

## 💻 Code

The program is organized into two main functions:

- `setup()` – Initializes the *LCD screen*, configures the *tilt sensor* pin as an input, and displays the welcome message.
- `loop()` – Continuously reads the *tilt sensor* state, detects when its state changes, generates a random prediction, clears the *LCD screen*, and displays one of eight possible responses using a `switch`/`case` statement.

### Key Functions Used

- `lcd.begin()` – Initializes the *LCD screen*.
- `pinMode()` – Configures the *tilt sensor* pin as an input.
- `lcd.print()` – Displays text on the *LCD screen*.
- `lcd.setCursor()` – Positions the cursor before printing text on the *LCD screen*.
- `digitalRead()` – Reads the current state of the *tilt sensor*.
- `random()` – Generates a random number to select one of the predefined predictions.
- `lcd.clear()` – Clears the *LCD screen* before displaying a new prediction.

---
