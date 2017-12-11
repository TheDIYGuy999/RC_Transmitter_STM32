#ifndef readVCC_h
#define readVCC_h

#include "Arduino.h"

//
// =======================================================================================================
// SETUP ADC1 TO READ VCC (= PIN PA1 NOT USABLE FOR ANALOG READ!)
// =======================================================================================================
//

void setup_vcc_sensor() {
  adc_reg_map *regs = ADC1->regs;
  regs->CR2 |= ADC_CR2_TSVREFE;    // enable VREFINT and temp sensor
  regs->SMPR1 =  ADC_SMPR1_SMP17;  // sample rate for VREFINT ADC channel
}

//
// =======================================================================================================
// READ VCC VOLTAGE
// =======================================================================================================
//

long readVcc() {
  long result = 1200 * 4096 / adc_read(ADC1, 17);  // ADC sample to millivolts
  return result; // Vcc in millivolts
}

#endif
