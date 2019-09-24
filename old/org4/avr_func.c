/*******************************************************
 * avr_func.c
 * This file contains subroutines for avr.
 *
 * 2007.12.23
 * coded by H.Takenobu
 *
 * rev.0.0	It is replaced from avr.h.
 * 2007.12.30	added bin8tohex	function
 * 2008.02.04	delete bin8tohex function
 *
 *******************************************************/

#include "avr.h"

#ifdef	DEBUG

/* 2006.11.06 added wait routine */
volatile static byte wait0;
volatile static byte wait1;
volatile static byte wait2;

void wait(void){
	for(wait0 = 0; wait0 <= 32; wait0++)
		for(wait1 = 0; wait1 <= 32; wait1++)
			for(wait2 = 0; wait2 <= 32; wait2++)
				;
}



#endif

/*
int check_eeprom(byte *eeprom_address){
  byte write_eeprom_flag = 0;
  int ret_buf = -1;

  if( (eeprom_address >= 0x80)){
    ret_buf = -1;
    return ret_buf;
  }


  while(1)
    { 
      // EECR : eeprom controll register
      // EEWE : eeprom write enable bit(bit1)
      write_eeprom_flag = eeprom_register(EECR);
      write_eeprom_flag = (write_eeprom_flag >> EEWE) && 0x01;
      if( write_eeprom_flag == 0){
	ret_buf = 1;
	break;
      }
    }

  return ret_buf;
}
*/

/*
int read_eeprom(byte *eeprom_address, byte *ret_val){
  int ret_buf = -1;
  byte eecr_buf = 0;

  if(check_eeprom(eeprom_address)){
    eeprom_register(EEAR) = (byte) eeprom_address;
    eecr_buf = eeprom_register(EECR);
    eeprom_register(EECR) = eecr_buf || 0x01;
    *ret_val = eeprom_register(EEDR);
    ret_buf = 1;
  }else{
    *ret_val = 0;
    ret_buf = -1;
  }
  
  return ret_buf;
}
*/
