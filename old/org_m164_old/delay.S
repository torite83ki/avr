# 1 "delay.S"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "delay.S"
# 1 "t13def.h" 1
# 2 "delay.S" 2
;void delay(word tim);

.extern sys_clk1
.extern nw_count

.global delay 
.func delay
delay:
	sei
delay_start:
	lds	r18,sys_clk1	; word value
	lds	r19,sys_clk1+1	; word value
	add	r24,r18		; sys_clk1 + tim -> r24,25
	adc	r25,r19		;
	sts	nw_count,r24
	sts	nw_count+1,r25
load_sys_clk:
	nop
	lds	r24,nw_count
	lds	r25,nw_count+1
	lds	r18,sys_clk1	; word value
	lds	r19,sys_clk1+1	; word value
	cp	r18,r24
	cpc	r19,r25
	brlt	load_sys_clk
	ret
.endfunc
