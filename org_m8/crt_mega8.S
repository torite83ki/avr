#include "io.h"

	.section .resetvec, "ax", @progbits
	.global	_resetvec
_resetvec:
	rjmp	RESET		// 		Reset

	.section .vectors, "ax", @progbits
	.global	_vectors
_vectors:
	rjmp	__vector_1	// Vec.2	External Interrupt0
	rjmp	__vector_2	// Vec.3	External Interrupt1
	rjmp	__vector_3	// Vec.4	Pin Change Interrupt0
	rjmp	__vector_4	// Vec.5	Pin Change Interrupt1
	rjmp	__vector_5	// Vec.6	Pin Change Interrupt2
	rjmp	__vector_6	// Vec.7	Watchdog Time-out
	rjmp	__vector_7	// Vec.8	Timer/Counter2 Compare Match A
	rjmp	__vector_8	// Vec.9	Timer/Counter2 Compare Match B
	rjmp	__vector_9	// Vec.10	Timer/Counter2 Overflow 
	rjmp	__vector_10	// Vec.11	Timer/Counter1 Capture Event 
	rjmp	__vector_11	// Vec.12	Timer/Counter1 Compare Match A
	rjmp	__vector_12	// Vec.13	Timer/Counter1 Compare Match B
	rjmp	__vector_13	// Vec.14	Timer/Counter1 Overflow 
	rjmp	__vector_14	// Vec.15	Timer/Counter0 Compare Match A
	rjmp	__vector_15	// Vec.16	Timer/Counter0 Compare Match B
	rjmp	__vector_16	// Vec.17	Timer/Counter0 Overflow
	rjmp	__vector_17	// Vec.18	SPI Serial Transfer Complete
	rjmp	__vector_18	// Vec.19	USART Rx Complete
	rjmp	__vector_19	// Vec.20	USART, Data Register Empty
	rjmp	__vector_20	// Vec.21	USART Rx Complete
	rjmp	__vector_21	// Vec.22	ADC conversion Complete
	rjmp	__vector_22	// Vec.23	EEPROM Ready
	rjmp	__vector_23	// Vec.24	Analog Comparator
	rjmp	__vector_24	// Vec.25	2-wire Serial Interface
	rjmp	__vector_25	// Vec.26	Store Program Memory Ready

	.section .text
	
	.global DUMMY_TRAP
DUMMY_TRAP:
	rjmp	main		// jump to Main

	.global RESET
RESET:
	clr	r0
	clr	r1
clear_sram:
	ldi	XH,(RAMTOP & 0xff00) >> 8
	ldi	XL,(RAMTOP & 0xff)
start_clear:
	st	X+,r0
	cpi	XH,(RAMEND & 0xff00) >> 8 
	brne	start_clear
	cpi	XL,(RAMEND & 0xff)
	brne	start_clear
clear_reg:
	ldi	YH,0x00
	ldi	YL,0x00
reg_clear_start:
	st	Y+,r0
	cpi	YL,0x1a		// less than r26
	brne	reg_clear_start
sreg_clear:
	out	SREG,r0
end_clear:
jmp_to_main:	
	rjmp	main		// jump to Main routine	
