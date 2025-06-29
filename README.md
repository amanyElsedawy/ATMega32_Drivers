# ATMega32_Drivers

## AVR Driver Layered Architecture

This repository contains AVR drivers organized in a layered architecture for the ATMega32 microcontroller.

### Folder Structure

- **mcal/** (Microcontroller Abstraction Layer):  
  Contains low-level drivers like DIO, Timer, ADC, Interrupts, and Communication Protocols.

- **hall/** (Hardware Abstraction Layer):  
  Contains higher-level drivers that interact with sensors, actuators, etc.

- **lib/** (Library Layer):  
  Contains shared utilities and helper functions (e.g., bit manipulation, standard types).

### Purpose

This project aims to implement modular, reusable, and well-structured AVR drivers for embedded systems development using the ATMega32.

### Author

Amany Elsedawy