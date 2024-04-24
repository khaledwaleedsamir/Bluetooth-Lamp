# Bluetooth-Lamp
 Using ARM Cortex-M3 based microcontroller STM32F103C8 on the bluepill to control a desk lamp via Bluetooth using the Bluetooth module HC-05, this repo contains only .c and .h files for the drivers created and the main app file.

## Project Overview

The main target of this project is to practice writing low level drivers and interfacing with an ARM based microcontroller. The project architecture consists of the following layers:

### MCAL (Microcontroller Abstraction Layer)

- **GPIO Driver**: Provides functions for configuring and controlling GPIO (General-Purpose Input/Output) pins on the microcontroller.
- **NVIC Driver**: Handles interrupts and manages the NVIC (Nested Vectored Interrupt Controller) to enable interrupt-driven operations.
- **SysTick Driver**: Implements the SysTick timer for system timing and delays.
- **RCC Driver**: Manages the microcontroller's clock settings and system clock configuration.

### HAL (Hardware Abstraction Layer)

- **LCD Driver**: Abstracts the interaction with an LCD display for showing system status or messages.
- **LEDs Driver**: Controls LEDs connected to GPIO pins, used for visual feedback or indication.
- **Relay Driver**: Manages the control of a relay module to switch the lamp on or off.
- **Bluetooth Module Driver**: Provides an interface to communicate with a Bluetooth module (e.g., HC-05) for wireless control.

### Application Layer

- **main.c**: Main application file that initializes the system, configures peripherals, and orchestrates the lamp control logic.

## Functionality

The application allows users to control a lamp wirelessly using Bluetooth:
- The Bluetooth module driver handles communication between the microcontroller and the Bluetooth module.
- Upon receiving commands via Bluetooth, the application toggles the relay to turn the lamp on or off.
- Lamp status is displayed on the LCD screen using the LCD driver.
- LED indicators provide visual feedback on the system's state (lamp status).

