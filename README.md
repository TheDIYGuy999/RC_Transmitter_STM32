#This is an Arduino 2.4GHz radio and IR transmitter
## Features:
- IR transmitter for "LEGO" Powerfunctions and trains as well as for "MECCANO" motors
- 2.4GHz radio transmitter for RC cars, helicopters etc.
- 4 analog axes, 2 mode switches (joystick buttons)
- 4 push buttons for transmission mode and vehicle selection as well as menu navigation
- 5 seletcable vehicle addresses, so you can use it for more than one vehicle
- 3.3V, 72MHz STM32F103C8T6 ARM board
- Atmel AVR version see: https://github.com/TheDIYGuy999/RC_Transmitter
- 2.4GHz NRF24L01 radio module
- Support for 0.96" I2C OLED.
- Configuration menu for: Channel direction reversing, servo travel adjustment (independent for each vehicle)
- Configuration values are stored in EEPROM
- NRF24L01+PA+LNA SMA radio modules with power amplifier are supported from board version 1.1
- very compact
- Eagle schematic will follow
- PONG Game included (runs much faster than on the Atmel AVR version)

New in V 2.0:
- Initial commit starting with V2.0, because the features are the same as in V2.0 for Atmel ARM MCU's
- Pinout according to the software comments. An Eagle schematic will follow later
- Works together with my Atmel AVR based receivers or the transmitter in "Tester Mode"
- OLED now driven the u8g2 library in "full buffer" mode. This is much faster, but requires more RAM (no problem on the STM32)
- Lego IR ist tested
- Meccano IR should work in theory, but the signal was only tested with an oscilloscope
- The emulated STM32 EEPROM seems to work properly, but the required "eepromHandler.h" is entirely new
- This version may still contain bugs. It was only tested on a breadboard

## Usage

See pictures

The Atmel AVR version:
![](https://github.com/TheDIYGuy999/RC_Transmitter/blob/master/1.jpg)

The STM32 test rig on a breadboard:
![](https://github.com/TheDIYGuy999/RC_Transmitter_STM32/blob/master/STM32_Test_Rig.jpg)

(c) 2017 TheDIYGuy999
