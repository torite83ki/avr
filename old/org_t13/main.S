#include "tn13def.h"

.extern main

.global main 
main:
;	cli
;	ldi temp, 0x03
;	out DDRB, temp 
;	ldi temp, 0x38
;	out PORTB, temp 
;
;	ldi temp, 0x26
;	out CLKPR, temp 
;
;	ldi temp, ((1<<CS02) || (1<<CS00))
;	out TCCR0B, temp
;	ldi temp, 0x0a
;	out TCNT0, temp
;	ldi temp, (1<<TOIE0)
;	out TIMSK0, temp
;
;
;	ldi temp1, 0xff	;/output value
;	ldi temp2, 0x00 ;/count1
;	ldi temp3, 0x00 ;/count2
;loop0:
;	inc temp2
;	brvc loop0
;	inc temp3
;	brvc loop0
;	com temp1
;	out PORTB,temp1
;	rjmp loop0
;
;
;
	rjmp app_main
