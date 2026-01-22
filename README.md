# Temperature.Sensor.Monitor-

## Overview
This project is an Arduino-based temperature monitoring system using an LM35 analog temperature sensor.
The system reads ambient temperature, converts analog values into degrees Celsius, and provides
visual feedback through a 16×2 LCD and an RGB LED.

The project was developed to build foundational skills in embedded systems, including sensor
interfacing, analog-to-digital conversion, and hardware-software integration.

---

## Hardware Used
- Arduino Uno
- LM35 temperature sensor
- 16×2 LCD (parallel interface)
- RGB LED
- Breadboard and jumper wires

---

## How It Works
- The LM35 outputs an analog voltage proportional to temperature (10 mV per °C).
- The Arduino reads this voltage using its ADC (0–1023 range).
- The ADC value is converted into voltage and then into temperature (°C).
- Temperature ranges determine the system state:
  - **Cool**: below 20 °C (blue LED)
  - **Warm**: 20–25 °C (green LED)
  - **Hot**: above 25 °C (red LED)
- The current temperature and system state are displayed on the LCD.
- Serial output is used for debugging and validation.

---

## Key Learning Outcomes
- Analog-to-digital conversion (ADC) and resolution
- Sensor scaling and unit conversion
- Conditional logic and state-based behaviour
- LCD interfacing using the LiquidCrystal library
- Embedded system structuring and debugging

---

## Code
The full Arduino sketch for this project can be found in:
- `Temperature_Monitor.ino`

The code is written in Embedded C/C++ and is structured to separate:
- Sensor reading and conversion
- Decision logic
- Output handling (LCD and RGB LED)

---

## Future Improvements
- Replace blocking delays with non-blocking timing using `millis()`
- Add PWM-based fan control for thermal management
- Implement basic filtering or averaging to reduce sensor noise

---

## Project Status
Completed — Phase 1 (Embedded Systems Fundamentals)
