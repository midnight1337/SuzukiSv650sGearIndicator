# Suzuki SV650S Gear Indicator

## Overview

Suzuki Gear Indicator module is a project designed especially for my motorbike Suzuki SV650S K8 that displays:
- Current gear
- Ambient temperature
- Motorbike battery voltage

It also contains a:
- TRE modification (Transmission Retard Elimination) that can be switched on and off
- Phone charger module

Circuit is designed to be surface mounted on single side PCB. Module is basicaly plug&play as it contains plugs that can be attached to Motorbike ECU.

### Technologies and Development
- Atmega328P
- C++
- Google Test

## Used parts

### Integrated Circuits
1. Microcontroller Atmega 328P 
2. Temperature sensor DS18B20
3. OLED Display SSD1306

### Passive components
1. Resistors:
    - 4.7K
    - 10K
2. Capacitors:
    - None
    - None

### Others

1. Japanese Sumitomo 4 way Connector
2. SPST switch

## Schematic

Coming soon




## Project documentation

### First working prototype
![Prototype](/pictures/prototype.jpeg)

Gaer voltage measured directly from ECU pinout

1st: 1.36V <br />
2nd: 1.77V <br />
3rd: 2.49V <br />
4th: 3.23V <br />
5th: 4.10V <br />
6th: 4.55V <br />
N: 5.00V <br />

### How does a TRE works

Here is explenation
