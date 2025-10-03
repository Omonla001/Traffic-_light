# AVR 7-Segment Display Driver

This project demonstrates how to control a common-anode 3-digit 7-segment display using an ATmega microcontroller. It cycles digits 0–9 across three digits with multiplexing.

The project is for embedded systems learners who want to practice bit manipulation, port configuration, and timing control on AVR microcontrollers.

A brief description of what this project does and who it's for


## Abdulrasheed Olumide (Omonla001)

https://github.com/Omonla001
## 🚀 About Me
I’m Abdulrasheed Olumide, a passionate embedded systems and desktop application developer, working on blending C/C++ system-level programming with real hardware control.

## ⚡ How to Run
Requirements

AVR Microcontroller (e.g., ATmega16/32/328P)

avr-gcc (compiler)

avrdude (flashing tool)

USBasp or Arduino-as-ISP programmer

A 3-digit common anode 7-segment display with current-limiting resistors

Build and Flash

Compile the code

avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf main.c


Generate HEX file

avr-objcopy -O ihex -R .eeprom main.elf main.hex


Flash to MCU (USBasp example)

avrdude -c usbasp -p m328p -U flash:w:main.hex


