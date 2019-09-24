/*******************************************************
 * avr.h
 * header file for avr
 * This file contains macros and subroutines for avr 
 *
 * 2006.08.06
 * coded by H.Takenobu
 *******************************************************/



#define io_register(p) *( (byte*)p + 0x20) // set a io address
#define eeprom_register(p) *( (byte*)p + 0x20) // set a eeprom address
#define cli() asm("cli")	// disenable interrupt
#define sei() asm("sei")	// enable interrupt
#define ret() asm("ret")	// set ret 
#define nop() asm("nop")	// nop


#define SEC_EEPROM __attribute__((section(".eeprom")))
// set a section of EEPROM
#define SEC_DATA  __attribute__((section(".data")))
// set a section of DATA


/* NAKED_INT means no stack, and it's not with ret and reti
 * SIGNAL_INT means stack the status , interrupt will be disenabled inside 
 * with reti
 * INTERRUPT_INT will be enabled inside the function and with reti
 */

#define NAKED __attribute__((naked))
#define SIGNAL_INT __attribute__((signal))
#define INTERRUPT_INT __attribute((interrupt))

typedef unsigned char byte;     // 8bit data size
typedef unsigned int  word;     // 16bit data size


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

/* 2007.07.16 added out operand */

#define out(a,b) asm volatile ( "out %0,%1"::"I" (a),"r" (b));

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

