# 1 "delay.S"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "delay.S"
# 1 "io.h" 1
# 2 "delay.S" 2
;void delay(int tim);

.extern sys_clk16

.global delay_int16 
.func delay_int16
delay_int16:
delay_start:
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
	ret
.endfunc
