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

This project features a basic hardware-controlled circuit powered directly by the *Arduino UNO R4 WiFi Board*. It functions as a pure hardware loop without requiring any digital I/O programming.

* **Power Source:**
  * **5V** on Arduino -> Positive (+) rail of the breadboard (Red wire)
  * **GND** on Arduino -> Negative (-) rail of the breadboard (Black wire)
* **LED & Button Loop:**
  * **Pushbutton:** Placed in series to act as a physical switch for the current flow.
  * **Red LED:** Connected in series with the button to receive power when pressed.
  * **Resistor:** A current-limiting resistor connected in series to protect the LED and return the path to the negative (-) ground rail.

---

## How it Works

* **What inputs are read:** No microcontroller inputs are read. The input is entirely physical: the mechanical press of the tactile pushbutton.
* **What decisions does the program make:** The microcontroller does not make any software decisions, as the Arduino is utilized strictly as a stable 5V power supply. The "decision" to complete or break the electrical path is made mechanically by the state of the button.
* **What outputs are produced:** The physical output is the illumination of the red LED, which lights up when the button is pressed (closing the circuit) and turns off when released (opening the circuit).














