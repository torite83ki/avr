/*******************************************************
 * avr.h
 * header file for avr devices
 * This file contains typedef and some definitions for avr 
 * This file is for C source file.
 *
 * 2006.08.06
 * coded by H.Takenobu
 *
 * rev 0.1	2007.12.23 added NULL constant
 * 		This file is divided to avr.h and avr_func.c.
 * rev 0.2	2008.03.11 added wait routines 
 * 		           and lcd routines 
 *
 * rev 0.3	2012.01.20 added watchdog_reset() 
 *			   and typedefs
 * 
 * rev 1.0	2012.01.21 all revised
 *		           - all subroutines
 *		           + some section names, resetvec, vector, flash
 *
 *******************************************************/

//#define DEBUG 1					// if you need debug code then enable
							// 2008.02.04 added by tak

#ifndef _AVR_H_
#define _AVR_H_



/*
 * SECTION attribute definitions
 */
#define TEXT   		__attribute__((section(".text")))
#define EEPROM 		__attribute__((section(".eeprom")))
#define DATA   		__attribute__((section(".data")))
#define BBS		__attribute__((section(".bbs")))
#define	RESETVEC	__attribute__((section(".resetvec")))
#define	VECTORS		__attribute__((section(".vectors")))

/* NAKED_INT means no stack, and it's not with ret and reti
 * SIGNAL_INT means stack the status , interrupt will be disenabled inside 
 * with reti
 * INTERRUPT_INT will be enabled inside the function and with reti
 */
#define NAKED 		__attribute__((naked, used))
#define SIGNAL_INT 	__attribute__((signal, used, externally_visible))
#define INTERRUPT_INT 	__attribute__((interrupt, used, externally_visible))

#define ISR(vector, ...) void vector(void) SIGNAL_INT;\
	void vector(void)
#define ISR_JUMP_DUMMY_TRAP(vector) void vector(void) NAKED;\
	void vector(void){\
		__asm__ __volatile__("rjmp DUMMY_TRAP"::);\
	}
#define ISR_JUMP_RESET(vector) void vector(void) NAKED;\
	void vector(void){\
		__asm__ __volatile__("rjmp RESET"::);\
	}
#define _VECTOR(n)	__vector_ ##n


/*
 * special register pointer  macros
 */
#define _SFR_OFFSET	0x20
#define io_register(p) *( (byte*)p + _SFR_OFFSET) 		// set a io address
#define eeprom_register(p) *( (byte*)p + _SFR_OFFSET) 		// set a eeprom address
								// above is correct?

/*
 * inline function macros
 */
#define cli()    __asm__ __volatile__ ("cli"::)			// disenable interrupt
#define sei()    __asm__ __volatile__ ("sei"::)			// enable interrupt
#define ret()    __asm__ __volatile__ ("ret"::)			// set ret 
#define nop()    __asm__ __volatile__ ("nop"::)			// nop
#define out(a,b) __asm__ __volatile__ ("out %0,%1"    \
					:	      \
					:"I"(a),"r"(b));
#define watchdog_reset()	__asm__ __volatile__ ("wdr"::)	// watchdog reset

/*
 * register macro
 */

#define __tmp_reg__	r0
#define __zero_reg__	r1

/*
 * constant definitions
 */
#define NULL	0x00
#define TRUE	0x01
#define FALSE	0x00


#endif
