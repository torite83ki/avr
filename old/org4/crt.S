#include "2313def.h"

.extern reset
.extern main
.extern int_INT1
.extern int_INT0
.extern int_TIM1_CAPT1
.extern int_TIM1_COMP1
.extern	int_TIM1_OVF1
.extern int_TIM0_OVF0
.extern int_UART_RX
.extern int_UART_UDRE
.extern int_UART_TX
.extern int_ANA_COMP

.extern clear_sram

.text
	rjmp	reset		// jump to Reset	
	rjmp	int_INT0	// Interrupt0
	rjmp	int_INT1	// Interrupt1
	rjmp	int_TIM1_CAPT1	// Timer/Counter1 Capture Event 
	rjmp	int_TIM1_COMP1	// Timer/Counter1 Compare Match
	rjmp	int_TIM1_OVF1	// Timer/Counter1 Overflow
	rjmp	int_TIM0_OVF0	// Timer/Counter0 Overflow
	rjmp	int_UART_RX	// UART, RX Complete
	rjmp	int_UART_UDRE	// UART Data Register Empty
	rjmp	int_UART_TX	// UART, TX Complete
	rjmp	int_ANA_COMP	// Analog Comparator
.global	reset
reset:
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
