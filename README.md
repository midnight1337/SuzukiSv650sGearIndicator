# Suzuki SV650S Gear Indicator

## Overview

Suzuki Gear Indicator module is a project designed especially for my motorbike Suzuki SV650S K8 that is able to display:
- Current gear
- Ambient temperature
- Motorbike battery voltage

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

## Schematic
...


## Project documentation

### 1. Reading current gear
Microcontroller module is connected into motorbike GPS (Gear Posistion System) plug, which is capable to read current gear by measuring voltage read on GPS. Then by using simple algorithms, voltage is converted into readable data so gear is displayed.

schematic here <-->

### 2. Reading battery voltage
Battery voltage is read simply via voltage divider, not using this approach would damage microcontroller as battery working voltage is more than 14V. Simmilar as above, using simple algorithms we can read our source voltage and display it.

Gaer voltage measured directly from GPS pinout: <br />
1st: 1.36V <br />
2nd: 1.77V <br />
3rd: 2.49V <br />
4th: 3.23V <br />
5th: 4.10V <br />
6th: 4.55V <br />
N: 5.00V <br />

schematic here <-->

### 3. Reading temperature
Not much to add here, I use simple DS18B20 temperature sensor.


### 4. How does microcontroller reads data?
My program uses a registers to read Analog data for gears and battery.
I manipulate ADMUX and ADCSRA registers in order to read particular data.

schematic here <-->


### First working prototype
![Prototype](/pictures/prototype.jpeg)

When voltage goes below threshold, there is yellow notification displayed. Simmilar with temperature, if it goes below temperature considered as safe to ride, then it displays warning.

photo here <-->
