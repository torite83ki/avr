/*
 * avr_func.h
 * header file for avr_func.c
 * This file contains some utilities for avr devices.
 *
 * 2007.12.30
 * coded by H.Takenobu
 *
 * rev 1.0	2012.01.21 all revised 
 */
#ifndef _AVR_FUNC_H_
#define _AVR_FUNC_H_

#include "avr.h"

void clear_sram(void) NAKED;
void read_byte_eeprom(uint8_t *eeprom_addr, uint8_t *ret_data);
void write_byte_eeprom(uint8_t *eeprom_addr, uint8_t data);



#endif
