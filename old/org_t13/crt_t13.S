#include "tn13def.h"

.extern RESET
.extern main
.extern int_INT0
.extern int_TIM0_COMPA
.extern int_TIM0_COMPB
.extern	int_TIM0_OVF
.extern int_ANA_COMP
.extern int_PCINT1
.extern int_EE_RDY
.extern int_WDT
.extern int_ADC

.extern clear_sram

.text
	rjmp	RESET		// jump to Reset	
	rjmp	int_INT0	// Interrupt0
	rjmp	int_PCINT1	// Interrupt1
	rjmp	int_TIM0_OVF	// Timer/Counter1 Capture Event 
	rjmp	int_EE_RDY	// Timer/Counter1 Compare Match
	rjmp	int_ANA_COMP	// Analog Comparator
	rjmp	int_TIM0_COMPA	// Timer/Counter1 Compare Match A
	rjmp	int_TIM0_COMPB	// Timer/Counter0 Compare Match B
	rjmp	int_WDT		// Watchdog Time-out
	rjmp	int_ADC		// ADC Conversion Complete 

	
.global RESET	
RESET:
clear_sram:
	ldi	XH,0x00
	ldi	XL,RAMTOP
	clr	temp
start_clear:
	st	X+,temp
	brne	start_clear
end_clear:
jmp_to_main:	
	rjmp	main		// jump to Main routine	
