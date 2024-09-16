# STM32_Smart_Lighting_System
This repository is part of a project I have worked on for the "Progettazione di Sistemi Operativi" course
at University of Milan during my master degree in CyberSecurity.

The project I have implemented is a *proof of concept* of a smart lighting system.
In particular the device features:
- Remote communication via LoRa implemented inside [this repository](https://github.com/sioel0/pico_lora)
- Automatic light intensity regulation based on ambient light level
- Nearby people detection to automatically increment light intensity
- Panic button and buzzer in order to create a more secure environment and faster interventions
