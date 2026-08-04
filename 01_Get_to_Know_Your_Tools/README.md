# 💡 Get to Know Your Tools

In this project I built simple circuits using an LED, switches, and a resistor.

This project is based on Project 01 from the Arduino Starter Kit R4. 

---

## 🔎 Circuit Demo

Presented below in the first column is the main circuit where a single switch is used, and in the second column are circuits where two switches are used in series and parallel connections, respectively.

<table>
  <tr>
    <td width="50%">
      <img src="images/main_circuit.gif" height="700">
    </td>
    <td width="35%">
      <img src="images/series_circuit.gif" height="350"><br><br>
      <img src="images/parallel_circuit.gif" height="350">
    </td>
  </tr>
</table>

---

## 🎯 Objective

The purpose of this project is to understand the basic theory of electrical circuits, specifically, the connection of electrical components in series and parallel, as well as to become familiar with the Arduino board and the breadboard.

---

## 🔋 Components

List of hardware components used:
- Arduino UNO R4 WiFi Board
- USB-C Cable
- Breadboard
- 220 Ohm Resistor
- LED
- Pushbuttons (Switches)
- Solid Core Jumber Wires
- Stranded Jumper Wires

---

## 🛠️ Circuit Implementation

This project demonstrates three different hardware-controlled circuit configurations using an *Arduino UNO R4 WiFi* strictly as a 5V power supply. None of the configurations require digital I/O programming.

### 🔌 Power Source (Common for all circuits)
* **5V** on Arduino $\rightarrow$ Positive ($+$) rail of the *breadboard* (Red wire)
* **GND** on Arduino $\rightarrow$ Negative ($-$) rail of the *breadboard* (Black wire)

### 1. Main Circuit
* Only a single tactile *pushbutton* (acting as a simple *switch*) is used.

### 2. Series Circuit
* Two tactile *pushbuttons* are connected in series (one after the other) using jumper wires. The electrical path is split across the buttons such that the output of the first button feeds directly into the input of the second.

### 3. Parallel Circuit
* Two tactile *pushbuttons* are connected in parallel using jumper wires. Both buttons share the same input voltage source and their outputs are tied together to feed into the *LED* anode. 

### ⚡ Signal Path (Similar for all circuits)
The current flows from the positive rail of the *breadboard*, through a current-limiting *resistor*, through the *switch(es)*, through the anode (long leg) of the red *LED*, and returns to the negative rail via the cathode (short leg) of the *LED*.

### ⚠️ Safety Tip
To ensure hardware safety, the *Arduino board* is strictly kept disconnected from any power source (via the *USB-C cable*) throughout the circuit assembly process. The board is only connected to the computer via the *USB-C cable* once all physical connections and circuit designs are fully completed and verified.

---

## ⚙️ How it Works

This project demonstrates hardware logic using basic electrical circuits. The Arduino does not execute any program logic or conditional statements. Instead, the circuit behavior is determined entirely by the wiring of the pushbuttons.

### Inputs
* Physical presses of the tactile *pushbuttons*.
* No software inputs are processed by the microcontroller.

### Hardware Logic & Output
* **Main Circuit (Direct Buffer):** *LED* turns ON when the single *pushbutton* is pressed.
* **Series Circuit (AND Logic):** *LED* turns ON only when both *pushbuttons* are pressed.
* **Parallel Circuit (OR Logic):** *LED* turns ON when either *pushbutton* (or both) is pressed.

---

## 🎓 What I Learned

Through building these circuits, I gained a lot of hands-on experience and solid practical knowledge:

* **Arduino Basics**
  * Learned how to safely power and connect the *Arduino board* to my computer using a *USB-C cable*.

* **Using a Breadboard**
  * Understood how a *breadboard* works internally (how the power rails and component rows are connected) and how to use *jumper wires* to build clean circuits.

* **Circuit Theory** 
  * Got a clear understanding of what a closed circuit is and what role each component plays.
  * Learned the difference between series and parallel connections, and how they physically act like AND / OR logic gates.
  * Applied Ohm’s Law ($V = I \cdot R$) to understand how voltage, current, and resistance work together.

* **Component Identification**
  * Learned to identify components in real life (*resistors*, *switches*, *LEDs*) and how to find the anode (positive) and cathode (negative) of an *LED* by looking at its legs.

* **Protecting Components**
  * Understood why we always need a *resistor* in series with an *LED* to prevent it from drawing too much current and burning out.

* **Switch Pinout**
  * Figured out how 4-pin tactile *pushbuttons* are connected internally so I don't accidentally short-circuit them on the breadboard.

* **Resistor Color Codes**
  * Learned how to read the colored bands on a *resistor* to calculate its value in Ohms.

* **Using a Multimeter**
  * Learned how to use a digital multimeter to measure voltage and resistance directly on my circuit.

---

## 🚀 Future Improvements

Possible extensions for this project include:

* Implement additional logic gates, such as NAND, NOR, XOR, and XNOR, using simple hardware circuits.
* Replace the LED with other output devices (e.g., a buzzer or relay) to demonstrate how the same hardware logic can control different components.
* Combine multiple logic gates to create more complex digital circuits, such as a Half Adder or Full Adder.
* Add more LEDs to visualize the output of different logic stages simultaneously.
* Implement the same logic using Arduino code and compare the differences between hardware-based and software-based logic.
