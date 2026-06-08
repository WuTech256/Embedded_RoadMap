# Overview of ARM Cortex-M GPIO Module

## 1. General Purpose Input/Output (GPIO)

- MCU pins are grouped into **ports**
  - Example: `PA1` = Port A, Pin 1

---

## 2. GPIO Interfacing

### 2.1 General Purpose Input/Output
- Basic functionality of a pin
- Can be configured as:
  - Input (read signal)
  - Output (write signal)

### 2.2 Special Purpose Input/Output
- Pins can have alternate (special) functions
- Examples:
  - UART
  - SPI
  - I2C

---

## 3. Common GPIO Registers

Most GPIO modules have at least two key registers:

### 3.1 Direction Register
- Configures pin direction:
  - Input
  - Output

### 3.2 Data Register
- Used to:
  - Write data to output pins
  - Read data from input pins

---

## 4. MCU Buses

MCUs typically use two types of buses:

### 4.1 AHB (Advanced High-Performance Bus)
- Peripheral access in **1 clock cycle**
- High-speed bus

### 4.2 APB (Advanced Peripheral Bus)
- Requires at least **2 clock cycles**
- Lower speed but more power-efficient

---

## 5. MCU Clock Sources

### 5.1 On-Chip RC Oscillator
- Built into the MCU
- Least accurate

### 5.2 External Crystal Oscillator
- Uses an external crystal
- Most accurate

### 5.3 Phase-Locked Loop (PLL)
- Programmable clock source
- Generates desired frequencies from a base clock

---
``
