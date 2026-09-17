# 🕹️ Hacking Buttons

In this project, I used an *Arduino board* and an *optocoupler* to electronically control the buttons of an *external device*, such as a *TV remote*.

This project is based on Project 13 from the Arduino Starter Kit R4.

---

## 🔎 Circuit Demo

<img src="images/hacking_buttons_circuit.gif" height="800" width="100%">

---

## 🎯 Objective

The purpose of this project is to understand how an *optocoupler* works and learn how to use it to control *external devices* that operate on a separate circuit.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 1 x 220 Ω Resistor
- 1 x Optocoupler
- External Device (e.g. TV Remote)
- Solid Core Jumber Wires
- Stranded Jumper Wire

---

## 🛠️ Circuit Implementation

This project demonstrates how to hack and control an *external device*—such as a *TV remote*—using an *Arduino UNO R4 WiFi board* and an *optocoupler (4N35)* to electrically isolate the Arduino while triggering button presses digitally.

### 🔌 Ground Connection
* **GND** on Arduino $\rightarrow$ Negative ($-$) ground rail of the *breadboard* (Black wire)

### ⚡ Control Section: Optocoupler (Input Side)
An *optocoupler* bridges the Arduino and the *remote's* circuit without establishing direct electrical contact, safeguarding the *microcontroller*.

* **Control Signal:** Arduino digital pin `2` connects to pin 1 (anode) of the *optocoupler* via a *220Ω current-limiting resistor*.
* **Optocoupler Ground:** Pin 2 (cathode) of the *optocoupler* connects directly to the negative ($-$) ground rail.

### 📺 External Device Interface: TV Remote (Output Side)
The *optocoupler's* internal phototransistor acts as a switch across the target button contacts on the disassembled *TV remote's* PCB.

* **Collector Connection (Pin 5):** Pin 5 of the *optocoupler* connects to one side of the *TV remote's* button contact trace.
* **Emitter Connection (Pin 4):** Pin 4 of the *optocoupler* connects to the corresponding ground/return side of the *TV remote's* button contact trace.
* **Note:** The wires routed to the *TV remote's* PCB can either be soldered or simply connected using tape.

### ⚠️ Safety Tips
* To ensure hardware safety, the *Arduino board* is strictly kept disconnected from any power source (via the *USB-C cable*) throughout the circuit assembly process. The board is only connected to the computer via the *USB-C cable* once all physical connections and circuit designs are fully completed and verified.
* During the disassembly of the *external device* to expose its internal PCB, the batteries should be kept removed. The wires soldered/connected to the target button contacts should not touch any neighboring traces or components on the PCB to prevent accidental short circuits.

---

## 📤 Setup & Upload

1. Connect your *Arduino Board* to your computer using the *USB-C Cable*.
2. Open the `.ino` file in the Arduino IDE.
3. Select the correct `Board` and `Port` from the `Tools` menu.
4. Click `Upload` to compile and upload the sketch to the board.
5. Once the upload is complete, the program will start running automatically.

---

## ⚙️ How it Works

The circuit operates as an automated button-pressing interface that uses an *optocoupler* to optically and electrically isolate the *Arduino UNO R4 WiFi* while simulating physical key presses on the *TV remote's* circuit board:

* **Hardware Initialization (Setup Phase):**
  * Upon startup, the sketch sets digital pin `2` as an `OUTPUT`.
  * This initializes the control line that drives the internal LED of the *optocoupler*.

* **Trigger Signal Generation (Program Logic):**
  * The program enters an automated cycle where it toggles pin `2` between `HIGH` and `LOW` states to simulate a momentary push button action.
  * Setting pin `2` to `HIGH` activates the *optocoupler* for `30ms`—a duration sufficient to register as a solid key press on the *remote's microcontroller* without causing multiple unintended inputs.
  * After `30ms`, pin `2` transitions back to `LOW`, releasing the virtual button, followed by a `10000ms` (`10-second`) resting delay before the next trigger.

* **Optical Switching & Circuit Closure (Output & Optocoupler Action):**
  * When pin `2` goes `HIGH`, current flows through the *220Ω resistor* and illuminates the internal LED inside the *optocoupler*.
  * The light hits the internal *phototransistor* (acting as an optical light detector), causing it to conduct and effectively closing the switch between pin 5 (`Collector`) and pin 4 (`Emitter`).
  * This bridges the two target traces on the *TV remote's* PCB, completing the circuit just like pressing the physical rubber button on the *remote* would.

* **Interactive User Behavior:**
  * **Target Button Selection:** You can solder or tape the wires from the *optocoupler's* output pins (4 and 5) across any button contacts on the *remote* or *external device* that you wish to automate. In this project, the Power button was chosen, which automatically toggles the TV between turning `ON` and turning `OFF` every cycle.
  * **Timing Customization:** You can easily customize the behavior in code by tweaking the `delay()` values—adjusting the active pulse duration (`30ms`) to match the responsiveness of different *devices*, or changing the sleep interval (`10000ms`) to control how frequently the automated action repeats.

---

## 💻 Code

The program is organized into two main functions:

- `setup()` – Configures the *optocoupler* pin as an `OUTPUT`.
- `loop()` – Continuously turns the *optocoupler* `ON` for `30ms`, turns it `OFF`, waits `10000ms`, and repeats the cycle.

### Key Functions Used

- `pinMode()` – Configures the *optocoupler* pin as an `OUTPUT`.
- `digitalWrite()` – Turns the *optocoupler* `ON` and `OFF` by setting the output pin to `HIGH` or `LOW`.
- `delay()` – Controls how long the *optocoupler* remains `ON` and how long the program waits before repeating the cycle.

---

## 🎓 What I Learned

Through building this project, I gained hands-on experience and practical knowledge about *optocouplers*, integrated circuits, and safely controlling *external electronic devices*:

- **Understanding Optocouplers**
  - Learned that an *optocoupler* is an integrated circuit (IC) used to control one circuit from another without any direct electrical connection.
  - Learned that an *optocoupler* contains an internal LED and a phototransistor that acts as a light detector.
  - Understood that when the Arduino turns `ON` the internal LED, the phototransistor is activated and internally closes a switch by connecting pins 4 and 5.
  - Learned that this electrical isolation makes *optocouplers* a safe way to interface two different circuits.
  - Learned how to correctly identify and connect the six pins of an *optocoupler*:
    - **Pin 1** – Anode of the internal LED.
    - **Pin 2** – Cathode of the internal LED.
    - **Pin 3** – No Connection (NC). 
    - **Pin 4** – `Emitter` of the phototransistor.
    - **Pin 5** – `Collector` of the phototransistor.
    - **Pin 6** – `Base` of the phototransistor.
  - Practiced wiring the *optocoupler* correctly in an Arduino circuit to control an *external device*.

- **Controlling External Devices**
  - Understood how an optocoupler can electronically "press" buttons on *battery-powered devices* without directly connecting the Arduino to their circuitry.
  - Learned that this technique can be used with almost any *battery-powered device* that uses common household batteries (like AA, AAA, or 9V batteries), such as battery-powered toys, portable radios and *remote controls*.
  - Understood why electrical isolation is important when controlling external circuits, helping protect both the Arduino and the target *device*.

- **Exploring the Inside of a TV Remote**
  - Practiced opening a simple electronic *device*, such as a *TV remote*, and observing its printed circuit board (PCB).
  - Learned how the *remote's* pushbuttons are constructed, with each button consisting of two conductive sides (forks), one of which is connected to the *device's* GND.
  - Understood that pressing a button causes a small metal disc inside the pushbutton to connect the two forks, completing the circuit.
  - Learned that a button can be electronically activated by creating a short circuit between its two forks.
  - Understood the importance of safely making this connection without touching any other PCB traces or components, since unwanted short circuits can interfere with the normal operation of the *device*.

- **Learning About Integrated Circuits**
  - Understood that integrated circuits (ICs) are found in virtually every electronic *device*.
  - Learned that the large chip on the *Arduino board* is an integrated circuit containing the board's main processor, while other ICs are responsible for functions such as communication and power management.
  - Learned that both the *optocoupler* and the Arduino's main chip are available in Dual In-line Package (DIP) form, making them easy to insert into a *breadboard* without permanent soldering.
  - Gained a better understanding of why DIP packages are widely used by electronics hobbyists for prototyping and experimentation.

---

## 🚀 Future Improvements

Possible extensions for this project include:

- Controlling multiple buttons on the same device by using additional *optocouplers*, allowing the Arduino to perform more complex actions.
- Integrating wireless communication modules (e.g. Bluetooth or Wi-Fi) to allow remote control of *external devices* through a smartphone or a web interface.
- Replacing the fixed delays with sensors or user inputs to create a more interactive and responsive control system.

---
