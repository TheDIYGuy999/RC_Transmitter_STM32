/*
  A quick and dirty way to store and read our 2 dimensional transmitter configuration arrays in and from the
  emulated STM32 EEPROM
*/

#ifndef eepromHandler_h
#define eepromHandler_h

#include "Arduino.h"

//
// =======================================================================================================
// EEPROM WRITE
// =======================================================================================================
//

void writeEeprom() {
  int entry = 0;

  for (int address = 0; address <= maxVehicleNumber; address++) { // Address loop
    for (int channel = 0; channel < servos; channel++) { // Servo loop
      EEPROM.write(entry, joystickReversed[address][channel]);
      EEPROM.write(entry + entries, joystickPercentNegative[address][channel]);
      EEPROM.write(entry + entries + entries, joystickPercentPositive[address][channel]);
      entry++;
    }
  }
}

//
// =======================================================================================================
// EEPROM READ
// =======================================================================================================
//

void readEeprom() {
  int entry = 0;

  for (int address = 0; address <= maxVehicleNumber; address++) { // Address loop
    for (int channel = 0; channel < servos; channel++) { // Servo loop
      EEPROM.read(entry, &joystickReversed[address][channel]);
      EEPROM.read(entry + entries, &joystickPercentNegative[address][channel]);
      EEPROM.read(entry + entries + entries, &joystickPercentPositive[address][channel]);
      entry++;
    }
  }
}

//
// =======================================================================================================
// EEPROM WRITE DEFAULTS
// =======================================================================================================
//

void writeEepromDefaults() {

  for (int entry = 0; entry <= entries; entry++) { // Entry loop
    EEPROM.write(entry, 0);
    EEPROM.write(entry + entries, 100);
    EEPROM.write(entry + entries + entries, 100);
  }
}

//
// =======================================================================================================
// EEPROM SETUP
// =======================================================================================================
//

void setupEeprom() {
  EEPROM.init();
  EEPROM.PageBase0 = 0x801F000;
  EEPROM.PageBase1 = 0x801F800;
  EEPROM.PageSize  = 0x400; // 1024

  readEeprom(); // restore all arrays from the EEPROM
}

#endif
