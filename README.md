# ESP32 Touch Sensor Controlled LED Effects System

## Overview

This project demonstrates a multi-mode LED effects system using an ESP32 microcontroller and a TTP223 capacitive touch sensor. A single touch sensor is used to switch between different LED animation patterns. Each touch changes the operating mode, allowing users to experience multiple LED effects without using multiple buttons.

The project showcases GPIO control, touch sensor interfacing, state machine implementation, LED pattern generation, and embedded programming concepts.

---

## Features

* Touch-based mode selection
* 6 LED control using ESP32
* Multiple LED animation patterns
* Capacitive touch sensing
* Debounce implementation
* State machine based operation

### LED Effects

| Touch Count | Effect                   |
| ----------- | ------------------------ |
| 1           | All LEDs ON              |
| 2           | Left-to-Right LED Chaser |
| 3           | Right-to-Left LED Chaser |
| 4           | Converging LEDs          |
| 5           | Diverging LEDs           |
| 6           | All LEDs Blink           |
| 7           | All LEDs OFF             |
| 8           | Repeat from Mode 1       |

---

## Components Required

* ESP32 Development Board
* TTP223 Capacitive Touch Sensor
* 6 LEDs
* 6 × 220Ω Resistors/optional
* Breadboard
* Jumper Wires
* USB Cable

---

## Circuit Connections

### Touch Sensor

| TTP223 Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 3.3V      |
| GND        | GND       |
| OUT        | GPIO15    |

### LEDs

| LED  | ESP32 GPIO |
| ---- | ---------- |
| LED1 | GPIO2      |
| LED2 | GPIO4      |
| LED3 | GPIO5      |
| LED4 | GPIO18     |
| LED5 | GPIO19     |
| LED6 | GPIO21     |

---

## Working Principle

The TTP223 capacitive touch sensor detects finger touch and generates a digital output signal. The ESP32 continuously monitors the touch sensor output.

When a touch is detected:

1. The operating mode is incremented.
2. The corresponding LED effect is selected.
3. The selected effect runs until the next touch event.
4. After the final mode, the sequence repeats from the beginning.

This approach uses edge detection to ensure a single touch is counted only once.

---

## Software Features

* GPIO configuration
* Touch event detection
* Debouncing
* LED pattern generation
* State machine design
* Modular programming

---



## Applications

* Smart Lighting Systems
* Human Machine Interface (HMI)
* Touch-Based Control Panels
* Interactive LED Displays
* Educational Embedded Systems Projects
* Home Automation Prototypes

---

## Learning Outcomes

Through this project, the following embedded systems concepts can be learned:

* ESP32 GPIO Programming
* Capacitive Touch Sensor Interfacing
* Digital Input Handling
* Event Detection
* State Machine Implementation
* LED Pattern Design
* Embedded C/C++ Programming

---

## Future Enhancements

* OLED Display Integration
* Blynk IoT Control
* Bluetooth-Based Configuration
* RGB LED Effects
* FreeRTOS Task-Based Implementation
* Mobile Application Control

---

## Author

Shaik Rizwan Basha

Embedded Systems and Firmware Development Enthusiast
