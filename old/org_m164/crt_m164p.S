#include "m164pdef.h"

.extern _main

.extern int_RESET		// Vec.1	Reset
//.extern	int_INT0	// Vec.2	External Interrupt0
//.extern	int_INT1	// Vec.3	External Interrupt1
//.extern	int_PCINT0	// Vec.4	Pin Change Interrupt0
//.extern	int_PCINT1	// Vec.5	Pin Change Interrupt1
//.extern	int_PCINT2	// Vec.6	Pin Change Interrupt2
//.extern	int_WDT		// Vec.7	Watchdog Time-out
//.extern	int_TIM2_COMPA	// Vec.8	Timer/Counter2 Compare Match A
//.extern	int_TIM2_COMPB	// Vec.9	Timer/Counter2 Compare Match B
//.extern	int_TIM2_OVF	// Vec.10	Timer/Counter2 Overflow 
//.extern	int_TIM1_CAPT	// Vec.11	Timer/Counter1 Capture Event 
//.extern	int_TIM1_COMPA	// Vec.12	Timer/Counter1 Compare Match A
//.extern	int_TIM1_COMPB	// Vec.13	Timer/Counter1 Compare Match B
//.extern	int_TIM1_OVF	// Vec.14	Timer/Counter1 Overflow 
//.extern	int_TIM0_COMPA	// Vec.15	Timer/Counter0 Compare Match A
//.extern	int_TIM0_COMPB	// Vec.16	Timer/Counter0 Compare Match B
.extern	int_TIM0_OVF		// Vec.17	Timer/Counter0 Overflow
//.extern	int_SPI_CMP	// Vec.18	SPI Serial Transfer Complete
//.extern	int_USART_RXCMP	// Vec.19	USART Rx Complete
//.extern	int_USART_DEMP	// Vec.20	USART, Data Register Empty
//.extern	int_USART_TXCMP	// Vec.21	USART Rx Complete
//.extern	int_ADC_CMP	// Vec.22	ADC conversion Complete
//.extern	int_EE_RDY	// Vec.23	EEPROM Ready
//.extern	int_ANA_COMP	// Vec.24	Analog Comparator
//.extern	int_TWI		// Vec.25	2-wire Serial Interface
//.extern	int_SPM_RDY	// Vec.26	Store Program Memory Ready

.extern clear_sram

.text
/*
	jmp	int_RESET		// Vec.1	jump to Reset	
	jmp	int_INT0		// Vec.2	External Interrupt0
	jmp	int_INT1		// Vec.3	External Interrupt1
	jmp	int_PCINT0	// Vec.4	Pin Change Interrupt0
	jmp	int_PCINT1	// Vec.5	Pin Change Interrupt1
	jmp	int_PCINT2	// Vec.6	Pin Change Interrupt2
	jmp	int_WDT		// Vec.7	Watchdog Time-out
	jmp	int_TIM2_COMPA	// Vec.8	Timer/Counter2 Compare Match A
	jmp	int_TIM2_COMPB	// Vec.9	Timer/Counter2 Compare Match B
	jmp	int_TIM2_OVF	// Vec.10	Timer/Counter2 Overflow 
	jmp	int_TIM1_CAPT	// Vec.11	Timer/Counter1 Capture Event 
	jmp	int_TIM1_COMPA	// Vec.12	Timer/Counter1 Compare Match A
	jmp	int_TIM1_COMPB	// Vec.13	Timer/Counter1 Compare Match B
	jmp	int_TIM1_OVF	// Vec.14	Timer/Counter1 Overflow 
	jmp	int_TIM0_COMPA	// Vec.15	Timer/Counter0 Compare Match A
	jmp	int_TIM0_COMPB	// Vec.16	Timer/Counter0 Compare Match B
	jmp	int_TIM0_OVF	// Vec.17	Timer/Counter0 Overflow
	jmp	int_SPI_CMP	// Vec.18	SPI Serial Transfer Complete
	jmp	int_USART_RXCMP	// Vec.19	USART Rx Complete
	jmp	int_USART_DEMP	// Vec.20	USART, Data Register Empty
	jmp	int_USART_TXCMP	// Vec.21	USART Rx Complete
	jmp	int_ADC_CMP	// Vec.22	ADC conversion Complete
	jmp	int_EE_RDY	// Vec.23	EEPROM Ready
	jmp	int_ANA_COMP	// Vec.24	Analog Comparator
	jmp	int_TWI		// Vec.25	2-wire Serial Interface
	jmp	int_SPM_RDY	// Vec.26	Store Program Memory Ready
*/	

	jmp	int_RESET	// Vec.1	jump to Reset	
	jmp	DUMMY_TRAP	// Vec.2	
	jmp	DUMMY_TRAP	// Vec.3	External Interrupt1
	jmp	DUMMY_TRAP	// Vec.4	Pin Change Interrupt0
	jmp	DUMMY_TRAP	// Vec.5
	jmp	DUMMY_TRAP	// Vec.6
	jmp	DUMMY_TRAP	// Vec.7
	jmp	DUMMY_TRAP	// Vec.8
	jmp	DUMMY_TRAP	// Vec.9
	jmp	DUMMY_TRAP	// Vec.10
	jmp	DUMMY_TRAP	// Vec.11
	jmp	DUMMY_TRAP	// Vec.12
	jmp	DUMMY_TRAP	// Vec.13
	jmp	DUMMY_TRAP	// Vec.14
	jmp	DUMMY_TRAP	// Vec.15
	jmp	DUMMY_TRAP	// Vec.16
	jmp	int_TIM0_OVF	// Vec.17	Timer/Counter0 Overflow
	jmp	DUMMY_TRAP	// Vec.18
	jmp	DUMMY_TRAP	// Vec.19
	jmp	DUMMY_TRAP	// Vec.20
	jmp	DUMMY_TRAP	// Vec.21
	jmp	DUMMY_TRAP	// Vec.22
	jmp	DUMMY_TRAP	// Vec.23
	jmp	DUMMY_TRAP	// Vec.24
	jmp	DUMMY_TRAP	// Vec.25
	jmp	DUMMY_TRAP	// Vec.26


.global int_RESET	
int_RESET:
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
	rjmp	_main		// jump to Main routine	

DUMMY_TRAP:
	rjmp	_main		// jump to Main
