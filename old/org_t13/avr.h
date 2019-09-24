/*******************************************************
 * avr.h
 * header file for avr
 * This file contains macros and subroutines for avr 
 * This file is for C source file.
 *
 * 2006.08.06
 * coded by H.Takenobu
 *
 * rev 0.1	2007.12.23 added NULL constant
 * 		This file is divided to avr.h and avr_func.c.
 * rev 0.2	2008.03.11 added wait routines 
 * 		           and lcd routines 
 *******************************************************/

// 2008.02.04 added by tak
#define DEBUG

#ifndef _AVR_H_
#define _AVR_H_

#define io_register(p) *( (byte*)p + 0x20) // set a io address
#define eeprom_register(p) *( (byte*)p + 0x20) // set a eeprom address
#define cli() asm("cli")	// disenable interrupt
#define sei() asm("sei")	// enable interrupt
#define ret() asm("ret")	// set ret 
#define reti() asm("reti")	// set reti
#define nop() asm volatile ("nop")	// nop


#define EEPROM __attribute__((section(".eeprom")))
// set a section of EEPROM
#define DATA  __attribute__((section(".data")))
// set a section of DATA


/* NAKED_INT means no stack, and it's not with ret and reti
 * SIGNAL_INT means stack the status , interrupt will be disenabled inside 
 * with reti
 * INTERRUPT_INT will be enabled inside the function and with reti
 */

#define NAKED __attribute__((naked))
#define SIGNAL_INT __attribute__((signal))
#define INTERRUPT_INT __attribute((interrupt))

/* 2008.01.02 
 * change the typedef byte definition 
 */
typedef unsigned char byte;     // 8bit data size
//typedef char byte;     // 8bit data size
typedef unsigned int  word;     // 16bit data size

/* 2007.07.16 added out operand */
#define out(a,b) asm volatile ( "out %0,%1"::"I" (a),"r" (b));

/* 2007.12.23 added for constant definition */
#define NULL	0x00

/* 2007.12.31 added */
void clear_sram(void) NAKED;

/* 2008.03.11 added */
void wait_1m(void) NAKED;
void wait_5m(void) NAKED;
void wait_5u(void) NAKED;

/* 2010.12.04 added*/
void app_main(void) NAKED;

#endif
