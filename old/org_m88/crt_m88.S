#include "m88def.h"

.extern main

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
	rjmp	int_RESET		// Vec.1	jump to Reset	
	rjmp	int_INT0		// Vec.2	External Interrupt0
	rjmp	int_INT1		// Vec.3	External Interrupt1
	rjmp	int_PCINT0	// Vec.4	Pin Change Interrupt0
	rjmp	int_PCINT1	// Vec.5	Pin Change Interrupt1
	rjmp	int_PCINT2	// Vec.6	Pin Change Interrupt2
	rjmp	int_WDT		// Vec.7	Watchdog Time-out
	rjmp	int_TIM2_COMPA	// Vec.8	Timer/Counter2 Compare Match A
	rjmp	int_TIM2_COMPB	// Vec.9	Timer/Counter2 Compare Match B
	rjmp	int_TIM2_OVF	// Vec.10	Timer/Counter2 Overflow 
	rjmp	int_TIM1_CAPT	// Vec.11	Timer/Counter1 Capture Event 
	rjmp	int_TIM1_COMPA	// Vec.12	Timer/Counter1 Compare Match A
	rjmp	int_TIM1_COMPB	// Vec.13	Timer/Counter1 Compare Match B
	rjmp	int_TIM1_OVF	// Vec.14	Timer/Counter1 Overflow 
	rjmp	int_TIM0_COMPA	// Vec.15	Timer/Counter0 Compare Match A
	rjmp	int_TIM0_COMPB	// Vec.16	Timer/Counter0 Compare Match B
	rjmp	int_TIM0_OVF	// Vec.17	Timer/Counter0 Overflow
	rjmp	int_SPI_CMP	// Vec.18	SPI Serial Transfer Complete
	rjmp	int_USART_RXCMP	// Vec.19	USART Rx Complete
	rjmp	int_USART_DEMP	// Vec.20	USART, Data Register Empty
	rjmp	int_USART_TXCMP	// Vec.21	USART Rx Complete
	rjmp	int_ADC_CMP	// Vec.22	ADC conversion Complete
	rjmp	int_EE_RDY	// Vec.23	EEPROM Ready
	rjmp	int_ANA_COMP	// Vec.24	Analog Comparator
	rjmp	int_TWI		// Vec.25	2-wire Serial Interface
	rjmp	int_SPM_RDY	// Vec.26	Store Program Memory Ready
*/	

	rjmp	int_RESET	// Vec.1	jump to Reset	
	rjmp	DUMMY_TRAP	// Vec.2	
	rjmp	DUMMY_TRAP	// Vec.3	External Interrupt1
	rjmp	DUMMY_TRAP	// Vec.4	Pin Change Interrupt0
	rjmp	DUMMY_TRAP	// Vec.5
	rjmp	DUMMY_TRAP	// Vec.6
	rjmp	DUMMY_TRAP	// Vec.7
	rjmp	DUMMY_TRAP	// Vec.8
	rjmp	DUMMY_TRAP	// Vec.9
	rjmp	DUMMY_TRAP	// Vec.10
	rjmp	DUMMY_TRAP	// Vec.11
	rjmp	DUMMY_TRAP	// Vec.12
	rjmp	DUMMY_TRAP	// Vec.13
	rjmp	DUMMY_TRAP	// Vec.14
	rjmp	DUMMY_TRAP	// Vec.15
	rjmp	DUMMY_TRAP	// Vec.16
	rjmp	int_TIM0_OVF	// Vec.17	Timer/Counter0 Overflow
	rjmp	DUMMY_TRAP	// Vec.18
	rjmp	DUMMY_TRAP	// Vec.19
	rjmp	DUMMY_TRAP	// Vec.20
	rjmp	DUMMY_TRAP	// Vec.21
	rjmp	DUMMY_TRAP	// Vec.22
	rjmp	DUMMY_TRAP	// Vec.23
	rjmp	DUMMY_TRAP	// Vec.24
	rjmp	DUMMY_TRAP	// Vec.25
	rjmp	DUMMY_TRAP	// Vec.26


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
	rjmp	main		// jump to Main routine	

DUMMY_TRAP:
	rjmp	main		// jump to Main
