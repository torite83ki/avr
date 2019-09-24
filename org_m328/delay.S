#include "avr.h"
.extern sys_clk16

.global delay_int16 
.func delay_int16
delay_int16:
	push	r18
	push	r19
	lds	r18,sys_clk16	; word value
	lds	r19,sys_clk16+1	; word value
	add	r24,r18		; sys_clk1 + tim -> r24,25
	adc	r25,r19		;
	andi	r25,0x7f	; mask MSB
load_sys_clk16:
	lds	r18,sys_clk16	; word value
	lds	r19,sys_clk16+1	; word value
	cp	r18,r24
	cpc	r19,r25
	brne	load_sys_clk16
	pop	r19
	pop	r18
	ret
.endfunc

.global delay_cycles
.func delay_cycles
delay_cycles:
	clr	__tmp_reg__
delay_cycles_loop:
	inc	__tmp_reg__	
	cp	r24, __tmp_reg__
	brcc	delay_cycles_loop
	ret
.endfunc
