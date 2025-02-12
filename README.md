# STM32 Cortex-M3 Drivers Implementation

Welcome to the STM32 Cortex-M3 Drivers Implementation repository! This project, developed collaboratively by our team, provides a collection of drivers for various peripherals of the STM32F3xx series microcontrollers, based on the ARM Cortex-M3 architecture.

## Overview

Our goal is to offer a comprehensive set of drivers to facilitate the development of embedded applications on STM32 microcontrollers. The repository is organized to support modularity and scalability, allowing for easy integration and future expansion.

## Repository Structure

- **STM32F3xx_Drivers/**: Contains all the implemented drivers.
  - **NVIC_Driver/**: Manages the Nested Vectored Interrupt Controller.
  - **Other_Drivers/**: Includes drivers for additional peripherals such as GPIO, RCC, EXTI, Flash, DMA, etc.

*Note*: The project was initially named `NVIC_Driver` in STM32IDE due to a naming oversight. However, the repository encompasses a wide range of drivers beyond the NVIC.

## Implemented Drivers

- **NVIC (Nested Vectored Interrupt Controller)**: Handles interrupt management and prioritization.
- **GPIO (General Purpose Input/Output)**: Manages digital input and output pins.
- **RCC (Reset and Clock Control)**: Manages the system clock and resets.
- **EXTI (External Interrupt/Event Controller)**: Handles external interrupt lines.
- **Flash Memory Controller**: Manages on-chip flash memory operations.
- **DMA (Direct Memory Access)**: Facilitates direct data transfers between memory and peripherals without CPU intervention.

## Example Application

The repository includes a blinking LED application demonstrating the use of the GPIO driver. This example serves as a starting point for understanding how to integrate and utilize the provided drivers in your projects.

## Getting Started

To utilize these drivers in your project:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Radwa4335/STM32-Cortex-M3-Drivers-Implementation.git
