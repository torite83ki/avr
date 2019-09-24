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

#define DEBUG 1						// if you need debug code then enable
							// 2008.02.04 added by tak

#ifndef _AVR_H_
#define _AVR_H_

#define io_register(p) *( (byte*)p + 0x20) 		// set a io address
#define eeprom_register(p) *( (byte*)p + 0x20) 		// set a eeprom address
#define cli()    asm("cli")				// disenable interrupt
#define sei()    asm("sei")				// enable interrupt
#define ret()    asm("ret")				// set ret 
#define nop()    asm volatile ("nop")			// nop
#define out(a,b) asm volatile ( "out %0,%1"	\
				:		\
				:"I" (a),"r" (b)); 	// 2007.07.16 added

#define TEXT   __attribute__((section(".text")))	// set a section of TEXT
#define EEPROM __attribute__((section(".eeprom")))	// set a section of EEPROM
#define DATA   __attribute__((section(".data")))	// set a section of DATA


/* NAKED_INT means no stack, and it's not with ret and reti
 * SIGNAL_INT means stack the status , interrupt will be disenabled inside 
 * with reti
 * INTERRUPT_INT will be enabled inside the function and with reti
 */
#define NAKED 		__attribute__((naked))
#define SIGNAL_INT 	__attribute__((signal))
#define INTERRUPT_INT 	__attribute((interrupt))

/* 2008.01.02 
 * change the typedef byte definition 
 * 2012.01.08 added new typedef
 */
typedef unsigned char byte;     			// 8bit data size
typedef unsigned int  word;     			// 16bit data size
typedef	unsigned char uchar_8;				// 8bit unsigned char
typedef unsigned int  uint_16;				// 16bit unsigned int
typedef unsigned long uint_32;				// 32bit unsigned int
typedef char	      char_8;				// 8bit signed char
typedef int	      int_16;				// 16bit signed int
typedef long int      int_32;				// 32bit signed int

#define NULL	0x00					// 2007.12.23 added 
#define TRUE	0x01					// added 2012.01.08
#define FALSE	0x00					// added 2012.01.08

void clear_sram(void) NAKED;				// 2007.12.31 added
void wait_1m(void) NAKED;				// 2008.03.11 added
void wait_5m(void) NAKED;
void wait_5u(void) NAKED;

volatile int sys_clk16;					// system clock 15bit long

#endif
