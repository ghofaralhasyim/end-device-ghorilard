# End-Device-Ghorilard

End Device Ghorilard consists code, architecture, workflow of Ghorilard Project

For Frontend of Ghorilard Project, Github Link:

For Backend of Ghorilard Project, Github Link:

For Simulation and Description of Ghorilard Project, Youtube Link:

## Table of Contents

## Ghorilard Architecture
<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/Arsitektur1.png" width=900>
</p>
<p align="center">
  Figure 2. Node MCU - ESP8266
</p>

## Ghorilard Component
### Node MCU - ESP8266
Node MCU ESP8266 is a microcontroller for wireless communication to the internet gateway and control the input of both sensors (PH sensor and Temperature Sensor)

<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/ESP8266-NodeMCU-kit-12-E-pinout-gpio-pin.png" width=300>
</p>
<p align="center">
  Figure 2. Node MCU - ESP8266
</p>

### DS18B20
DS18B20 is Temperature sensor module to measure the temperature of the water which may be directly proportional to the oxygen level in the aquaculture pond.

<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/DS18B20.jpg" width=300>
</p>
<p align="center">
  Figure 3. DS18B20 Temperature Sensor Module
</p>

### PH-4502C
PH-4502C is PH sensor module to measure the PH of the culture pond.

<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/PH4502C.jpg" width=300>
</p>
<p align="center">
  Figure 4. PH-4502C PH sensor Module
</p>

### StepUp MT3608
StepUp MT3608 is stepUp module to increase the voltage and also stabilize the voltage. In the Ghorilard project, it is used to increase and stabilize voltage to 5V.

<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/StepUp%20MT3608.jpg" width=300>
</p>
<p align="center">
  Figure 4. StepUp MT3608 Module
</p>
  
### TP4056A
TP4056A a charging module that will charge power from the solar cells to the battery and also supply power to the stepUp module. Equipped with an IC that protects the overvoltage.

<p align="center">
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/TP4056A.jpg" width=300>
</p>
<p align="center">
  Figure 4. TP4056A Charging Module
</p>

## Ghorilard Software Module

## Ghorilard Workflow
- Device will turn on and start to get a sensor value
- The power source of the device comes from sunlight that will convert to power by solar cell
- TP4056A module will charge power to the battery 18650 and also give power to stepUp module
- StepUp module will step up voltage to 5V and give voltage to NodeMCU
- NodeMCU will give 3.3V to two sensor
- This product will sense water per 30 minutes
- The sense value of sensor will send by wifi router to the backend dan will store to the database
- Frontend give a UI/UX to user so user can see the water quality of their prawn cultivation in real-time

## Ghorilard Product Design
<div>
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/Ghorilard%201.jpg" display="inline" width=300>
  <img src="https://github.com/ghofaralhasyim/end-device-ghorilard/blob/main/assets/Ghorilard%202.jpg" display="inline" width=300>
</div>

  Ghorilard Product has already design product that can be seen in the picture above. We made our design by 3D print that provide by our univesity (Universitas Multimedia Nusantara). We also use TinkerCad to make our design. there is one drawback in our design that is not able to float.

