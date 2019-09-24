	.file	"avr_main.c"
	.arch avr2
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__tmp_reg__ = 0
__zero_reg__ = 1
	.global __do_copy_data
	.global __do_clear_bss
	.text
.global	prologue
	.type	prologue, @function
prologue:
/* prologue: frame size=0 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue end (size=4) */
/* #APP */
	nop
	nop
/* #NOAPP */
/* epilogue: frame size=0 */
	pop r29
	pop r28
	ret
/* epilogue end (size=3) */
/* function prologue size 11 (4) */
	.size	prologue, .-prologue
.global	app_main
	.type	app_main, @function
app_main:
/* prologue: frame size=2 */
/* prologue: naked */
/* prologue end (size=0) */
/* #APP */
	cli
/* #NOAPP */
	ldi r30,lo8(94)
	ldi r31,hi8(94)
	ldi r24,lo8(4)
	st Z,r24
	ldi r30,lo8(93)
	ldi r31,hi8(93)
	ldi r24,lo8(-1)
	st Z,r24
	rcall init_timer
	rcall init_port
/* #APP */
	nop
	nop
	nop
/* #NOAPP */
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	st Z,__zero_reg__
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	st Z,__zero_reg__
	rcall wait_5m
	rcall wait_5m
	rcall wait_5m
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(-1)
	st Z,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ldi r24,lo8(31)
	st Z,r24
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldi r24,lo8(-1)
	st Z,r24
	rcall wait_5m
	rcall wait_5m
	rcall wait_5m
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	st Z,__zero_reg__
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	st Z,__zero_reg__
/* #APP */
	sei
/* #NOAPP */
	ldi r22,lo8(5)
	ldi r23,hi8(5)
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall set_utimer
	std Y+1,r24
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(-1)
	st Z,r24
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall start_utimer
	std Y+1,r24
.L4:
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall check_running_utimer
	std Y+1,r24
	ldd r24,Y+1
	cpi r24,lo8(1)
	brne .L5
	rjmp .L4
.L5:
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall start_utimer
	std Y+1,r24
.L7:
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall check_running_utimer
	std Y+1,r24
	ldd r24,Y+1
	cpi r24,lo8(1)
	brne .L8
	rjmp .L7
.L8:
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(-1)
	st Z,r24
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall start_utimer
	std Y+1,r24
.L10:
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall check_running_utimer
	std Y+1,r24
	ldd r24,Y+1
	cpi r24,lo8(1)
	brne .L11
	rjmp .L10
.L11:
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall start_utimer
	std Y+1,r24
.L13:
	ldi r24,lo8(0)
	ldi r25,hi8(0)
	rcall check_running_utimer
	std Y+1,r24
	ldd r24,Y+1
	cpi r24,lo8(1)
	brne .L14
	rjmp .L13
.L14:
/* #APP */
	nop
/* #NOAPP */
	lds r24,test_bb
	clr r25
	mov r24,r25
	clr r25
	andi r24,lo8(1)
	andi r25,hi8(1)
	tst r24
	breq .L16
	ldi r24,lo8(-1)
	std Y+2,r24
.L16:
	ldi r24,lo8(100)
	ldi r25,hi8(100)
	rcall delay
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(-1)
	st Z,r24
	ldi r24,lo8(100)
	ldi r25,hi8(100)
	rcall delay
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	rjmp .L14
/* epilogue: frame size=2 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function app_main size 151 (151) */
	.size	app_main, .-app_main
.global	init_interrupt_cpumode
	.type	init_interrupt_cpumode, @function
init_interrupt_cpumode:
/* prologue: frame size=0 */
/* prologue: naked */
/* prologue end (size=0) */
/* #APP */
	cli
/* #NOAPP */
	ldi r30,lo8(61)
	ldi r31,hi8(61)
	st Z,__zero_reg__
/* #APP */
	ret
/* #NOAPP */
/* epilogue: frame size=0 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function init_interrupt_cpumode size 7 (7) */
	.size	init_interrupt_cpumode, .-init_interrupt_cpumode
.global	init_timer
	.type	init_timer, @function
init_timer:
/* prologue: frame size=0 */
/* prologue: naked */
/* prologue end (size=0) */
	ldi r30,lo8(97)
	ldi r31,hi8(97)
	ldi r24,lo8(-128)
	st Z,r24
	ldi r30,lo8(97)
	ldi r31,hi8(97)
	st Z,__zero_reg__
	ldi r30,lo8(68)
	ldi r31,hi8(68)
	st Z,__zero_reg__
	ldi r30,lo8(69)
	ldi r31,hi8(69)
	ldi r24,lo8(5)
	st Z,r24
	ldi r30,lo8(70)
	ldi r31,hi8(70)
	ldi r24,lo8(-9)
	st Z,r24
	ldi r30,lo8(110)
	ldi r31,hi8(110)
	ldi r24,lo8(1)
	st Z,r24
/* #APP */
	ret
/* #NOAPP */
/* epilogue: frame size=0 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function init_timer size 24 (24) */
	.size	init_timer, .-init_timer
.global	init_port
	.type	init_port, @function
init_port:
/* prologue: frame size=0 */
/* prologue: naked */
/* prologue end (size=0) */
	ldi r30,lo8(36)
	ldi r31,hi8(36)
	ldi r24,lo8(127)
	st Z,r24
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(-128)
	st Z,r24
/* #APP */
	nop
/* #NOAPP */
	ldi r30,lo8(39)
	ldi r31,hi8(39)
	ldi r24,lo8(31)
	st Z,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ldi r24,lo8(63)
	st Z,r24
/* #APP */
	nop
/* #NOAPP */
	ldi r30,lo8(42)
	ldi r31,hi8(42)
	ldi r24,lo8(127)
	st Z,r24
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldi r24,lo8(-128)
	st Z,r24
/* #APP */
	nop
	ret
/* #NOAPP */
/* epilogue: frame size=0 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function init_port size 32 (32) */
	.size	init_port, .-init_port
.global	init_parameter
	.type	init_parameter, @function
init_parameter:
/* prologue: frame size=0 */
/* prologue: naked */
/* prologue end (size=0) */
	sts state,__zero_reg__
	sts (sys_clk0)+1,__zero_reg__
	sts sys_clk0,__zero_reg__
	sts (sys_clk1)+1,__zero_reg__
	sts sys_clk1,__zero_reg__
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	st Z,__zero_reg__
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	st Z,__zero_reg__
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	st Z,__zero_reg__
/* #APP */
	ret
/* #NOAPP */
/* epilogue: frame size=0 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function init_parameter size 21 (21) */
	.size	init_parameter, .-init_parameter
.global	blink_led
	.type	blink_led, @function
blink_led:
/* prologue: frame size=5 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,5
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+3,r24
	std Y+5,r23
	std Y+4,r22
	std Y+2,__zero_reg__
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ld r24,Z
	std Y+1,r24
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(127)
	st Z,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	st Z,__zero_reg__
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldi r24,lo8(127)
	st Z,r24
.L28:
	ldd r25,Y+2
	ldd r24,Y+3
	cp r25,r24
	brsh .L31
	ldd r24,Y+4
	ldd r25,Y+5
	rcall delay
	ldd r24,Y+4
	ldd r25,Y+5
	rcall delay
	ldd r24,Y+2
	subi r24,lo8(-(1))
	std Y+2,r24
	rjmp .L28
.L31:
/* epilogue: frame size=5 */
	adiw r28,5
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function blink_led size 52 (33) */
	.size	blink_led, .-blink_led
.global	read_port
	.type	read_port, @function
read_port:
/* prologue: frame size=2 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+2,r25
	std Y+1,r24
	ldd r24,Y+1
	ldd r25,Y+2
	mov r31,r25
	mov r30,r24
	adiw r30,32
	ld r24,Z
	clr r25
/* epilogue: frame size=2 */
	adiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function read_port size 28 (9) */
	.size	read_port, .-read_port
.global	write_port
	.type	write_port, @function
write_port:
/* prologue: frame size=3 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,3
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+2,r25
	std Y+1,r24
	std Y+3,r22
	ldd r24,Y+1
	ldd r25,Y+2
	mov r31,r25
	mov r30,r24
	adiw r30,32
	ldd r24,Y+3
	st Z,r24
/* epilogue: frame size=3 */
	adiw r28,3
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function write_port size 29 (10) */
	.size	write_port, .-write_port
.global	read_sw
	.type	read_sw, @function
read_sw:
/* prologue: frame size=1 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,1
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	ldi r24,lo8(3)
	ldi r25,hi8(3)
	rcall read_port
	std Y+1,r24
	lds r24,sw_in
	clr r25
	sbrc r24,7
	com r25
	andi r24,lo8(24)
	andi r25,hi8(24)
	asr r25
	ror r24
	asr r25
	ror r24
	asr r25
	ror r24
	sts sw_in,r24
	ldd r24,Y+1
	mov r18,r24
	clr r19
	lds r24,sw_in_pre
	clr r25
	sbrc r24,7
	com r25
	cp r18,r24
	cpc r19,r25
	brne .L37
	ldd r24,Y+1
	sts sw_in,r24
.L37:
	ldd r24,Y+1
	sts sw_in_pre,r24
/* epilogue: frame size=1 */
	adiw r28,1
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function read_sw size 55 (36) */
	.size	read_sw, .-read_sw
.global	set_mode
	.type	set_mode, @function
set_mode:
/* prologue: frame size=3 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,3
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+2,r25
	std Y+1,r24
	std Y+3,r22
	ldd r24,Y+3
	tst r24
	breq .L41
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	cpi r24,lo8(1)
	brne .L43
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ori r24,lo8(2)
	ldd r30,Y+1
	ldd r31,Y+2
	st Z,r24
	rjmp .L47
.L43:
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	andi r24,lo8(-3)
	ldd r30,Y+1
	ldd r31,Y+2
	st Z,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ori r24,lo8(4)
	ldd r30,Y+1
	ldd r31,Y+2
	st Z,r24
	rjmp .L47
.L41:
	ldd r30,Y+1
	ldd r31,Y+2
	ldi r24,lo8(1)
	st Z,r24
.L47:
/* epilogue: frame size=3 */
	adiw r28,3
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function set_mode size 57 (38) */
	.size	set_mode, .-set_mode
.global	set_shutter_cycle
	.type	set_shutter_cycle, @function
set_shutter_cycle:
/* prologue: frame size=2 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	lds r24,sw_in
	mov r18,r24
	clr r19
	sbrc r18,7
	com r19
	std Y+2,r19
	std Y+1,r18
	ldd r24,Y+1
	ldd r25,Y+2
	cpi r24,1
	cpc r25,__zero_reg__
	breq .L51
	ldd r18,Y+1
	ldd r19,Y+2
	cpi r18,2
	cpc r19,__zero_reg__
	brge .L54
	ldd r24,Y+1
	ldd r25,Y+2
	sbiw r24,0
	breq .L50
	rjmp .L49
.L54:
	ldd r18,Y+1
	ldd r19,Y+2
	cpi r18,2
	cpc r19,__zero_reg__
	breq .L52
	ldd r24,Y+1
	ldd r25,Y+2
	cpi r24,3
	cpc r25,__zero_reg__
	breq .L53
	rjmp .L49
.L51:
	ldi r24,lo8(300)
	ldi r25,hi8(300)
	sts (shutter_cyc1)+1,r25
	sts shutter_cyc1,r24
	rjmp .L56
.L52:
	ldi r24,lo8(1000)
	ldi r25,hi8(1000)
	sts (shutter_cyc1)+1,r25
	sts shutter_cyc1,r24
	rjmp .L56
.L53:
	ldi r24,lo8(6000)
	ldi r25,hi8(6000)
	sts (shutter_cyc1)+1,r25
	sts shutter_cyc1,r24
	rjmp .L56
.L50:
	ldi r24,lo8(6000)
	ldi r25,hi8(6000)
	sts (shutter_cyc1)+1,r25
	sts shutter_cyc1,r24
	rjmp .L56
.L49:
	ldi r24,lo8(300)
	ldi r25,hi8(300)
	sts (shutter_cyc1)+1,r25
	sts shutter_cyc1,r24
.L56:
/* epilogue: frame size=2 */
	adiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function set_shutter_cycle size 87 (68) */
	.size	set_shutter_cycle, .-set_shutter_cycle
.global	reset_shutter_count
	.type	reset_shutter_count, @function
reset_shutter_count:
/* prologue: frame size=0 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue end (size=4) */
	lds r24,state
	clr r25
	lsr r25
	ror r24
	andi r24,lo8(1)
	andi r25,hi8(1)
	tst r24
	breq .L60
	lds r24,sys_clk1
	lds r25,(sys_clk1)+1
	lds r18,shutter_cyc1
	lds r19,(shutter_cyc1)+1
	add r24,r18
	adc r25,r19
	sts (shutter_count1)+1,r25
	sts shutter_count1,r24
.L60:
/* epilogue: frame size=0 */
	pop r29
	pop r28
	ret
/* epilogue end (size=3) */
/* function reset_shutter_count size 30 (23) */
	.size	reset_shutter_count, .-reset_shutter_count
.global	pset0
	.type	pset0, @function
pset0:
/* prologue: frame size=2 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+1,r24
	std Y+2,r22
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldd r24,Y+2
	mov r18,r24
	clr r19
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	st Z,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ldd r24,Y+1
	mov r18,r24
	clr r19
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	st Z,r24
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldi r24,lo8(127)
	st Z,r24
/* epilogue: frame size=2 */
	adiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function pset0 size 54 (35) */
	.size	pset0, .-pset0
.global	pset1
	.type	pset1, @function
pset1:
/* prologue: frame size=2 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+1,r24
	std Y+2,r22
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(127)
	st Z,r24
	ldd r24,Y+1
	cpi r24,lo8(5)
	brsh .L64
	ldi r24,lo8(5)
	std Y+1,r24
.L64:
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ldd r24,Y+1
	clr r25
	mov r18,r24
	mov r19,r25
	subi r18,lo8(-(-5))
	sbci r19,hi8(-(-5))
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	st Z,r24
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldd r24,Y+2
	mov r18,r24
	clr r19
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	rjmp 2f
1:	lsl r24
	rol r25
2:	dec r18
	brpl 1b
	com r24
	st Z,r24
/* epilogue: frame size=2 */
	adiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function pset1 size 62 (43) */
	.size	pset1, .-pset1
.global	pset
	.type	pset, @function
pset:
/* prologue: frame size=2 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+1,r24
	std Y+2,r22
	ldd r24,Y+1
	cpi r24,lo8(5)
	brsh .L68
	ldd r22,Y+2
	ldd r24,Y+1
	rcall pset0
	rjmp .L71
.L68:
	ldd r22,Y+2
	ldd r24,Y+1
	rcall pset1
.L71:
/* epilogue: frame size=2 */
	adiw r28,2
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function pset size 31 (12) */
	.size	pset, .-pset
.global	clear
	.type	clear, @function
clear:
/* prologue: frame size=0 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue end (size=4) */
	ldi r30,lo8(37)
	ldi r31,hi8(37)
	ldi r24,lo8(127)
	st Z,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	st Z,__zero_reg__
	ldi r30,lo8(43)
	ldi r31,hi8(43)
	ldi r24,lo8(127)
	st Z,r24
/* epilogue: frame size=0 */
	pop r29
	pop r28
	ret
/* epilogue end (size=3) */
/* function clear size 18 (11) */
	.size	clear, .-clear
.global	start_utimer
	.type	start_utimer, @function
start_utimer:
/* prologue: frame size=6 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L75
	std Y+6,__zero_reg__
	std Y+5,__zero_reg__
	rjmp .L77
.L75:
/* #APP */
	cli
/* #NOAPP */
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ldd r18,Z+4
	ldd r19,Z+5
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	add r24,r18
	adc r25,r19
	andi r25,hi8(32767)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+3,r25
	std Z+2,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Z+1,r25
	st Z,r24
/* #APP */
	sei
/* #NOAPP */
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+6,r25
	std Y+5,r24
.L77:
	ldd r24,Y+5
	ldd r25,Y+6
/* epilogue: frame size=6 */
	adiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function start_utimer size 75 (56) */
	.size	start_utimer, .-start_utimer
.global	stop_utimer
	.type	stop_utimer, @function
stop_utimer:
/* prologue: frame size=6 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L80
	std Y+6,__zero_reg__
	std Y+5,__zero_reg__
	rjmp .L82
.L80:
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	andi r24,lo8(-14)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+1,r25
	st Z,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+6,r25
	std Y+5,r24
.L82:
	ldd r24,Y+5
	ldd r25,Y+6
/* epilogue: frame size=6 */
	adiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function stop_utimer size 59 (40) */
	.size	stop_utimer, .-stop_utimer
.global	restart_utimer
	.type	restart_utimer, @function
restart_utimer:
/* prologue: frame size=6 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L85
	std Y+6,__zero_reg__
	std Y+5,__zero_reg__
	rjmp .L87
.L85:
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ldd r18,Z+4
	ldd r19,Z+5
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	add r24,r18
	adc r25,r19
	andi r25,hi8(32767)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+3,r25
	std Z+2,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	andi r24,lo8(-13)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+1,r25
	st Z,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	ori r24,lo8(1)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+1,r25
	st Z,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+6,r25
	std Y+5,r24
.L87:
	ldd r24,Y+5
	ldd r25,Y+6
/* epilogue: frame size=6 */
	adiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function restart_utimer size 84 (65) */
	.size	restart_utimer, .-restart_utimer
.global	set_utimer
	.type	set_utimer, @function
set_utimer:
/* prologue: frame size=8 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	std Y+6,r23
	std Y+5,r22
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L90
	std Y+8,__zero_reg__
	std Y+7,__zero_reg__
	rjmp .L92
.L90:
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ldd r24,Y+5
	ldd r25,Y+6
	std Z+5,r25
	std Z+4,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+8,r25
	std Y+7,r24
.L92:
	ldd r24,Y+7
	ldd r25,Y+8
/* epilogue: frame size=8 */
	adiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function set_utimer size 57 (38) */
	.size	set_utimer, .-set_utimer
.global	check_running_utimer
	.type	check_running_utimer, @function
check_running_utimer:
/* prologue: frame size=8 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+6,r25
	std Y+5,r24
	ldd r24,Y+5
	ldd r25,Y+6
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L95
	std Y+8,__zero_reg__
	std Y+7,__zero_reg__
	rjmp .L97
.L95:
	ldd r18,Y+5
	ldd r19,Y+6
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	andi r24,lo8(1)
	andi r25,hi8(1)
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,1
	cpc r25,__zero_reg__
	brne .L98
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+8,r25
	std Y+7,r24
	rjmp .L97
.L98:
	std Y+8,__zero_reg__
	std Y+7,__zero_reg__
.L97:
	ldd r24,Y+7
	ldd r25,Y+8
/* epilogue: frame size=8 */
	adiw r28,8
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function check_running_utimer size 65 (46) */
	.size	check_running_utimer, .-check_running_utimer
.global	set_autostart_utimer
	.type	set_autostart_utimer, @function
set_autostart_utimer:
/* prologue: frame size=6 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L102
	std Y+6,__zero_reg__
	std Y+5,__zero_reg__
	rjmp .L104
.L102:
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	ori r25,hi8(256)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+1,r25
	st Z,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+6,r25
	std Y+5,r24
.L104:
	ldd r24,Y+5
	ldd r25,Y+6
/* epilogue: frame size=6 */
	adiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function set_autostart_utimer size 58 (39) */
	.size	set_autostart_utimer, .-set_autostart_utimer
.global	reset_autostart_utimer
	.type	reset_autostart_utimer, @function
reset_autostart_utimer:
/* prologue: frame size=6 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+4,r25
	std Y+3,r24
	ldd r24,Y+3
	ldd r25,Y+4
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L107
	std Y+6,__zero_reg__
	std Y+5,__zero_reg__
	rjmp .L109
.L107:
	ldd r18,Y+3
	ldd r19,Y+4
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+2,r25
	std Y+1,r24
	ldd r30,Y+1
	ldd r31,Y+2
	ld r24,Z
	ldd r25,Z+1
	andi r25,hi8(-257)
	ldd r30,Y+1
	ldd r31,Y+2
	std Z+1,r25
	st Z,r24
	ldi r24,lo8(1)
	ldi r25,hi8(1)
	std Y+6,r25
	std Y+5,r24
.L109:
	ldd r24,Y+5
	ldd r25,Y+6
/* epilogue: frame size=6 */
	adiw r28,6
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function reset_autostart_utimer size 59 (40) */
	.size	reset_autostart_utimer, .-reset_autostart_utimer
.global	count_utimer
	.type	count_utimer, @function
count_utimer:
/* prologue: frame size=4 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,4
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue end (size=10) */
	std Y+2,__zero_reg__
	std Y+1,__zero_reg__
	rjmp .L112
.L113:
	ldd r18,Y+1
	ldd r19,Y+2
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+4,r25
	std Y+3,r24
	ldd r30,Y+3
	ldd r31,Y+4
	ld r24,Z
	ldd r25,Z+1
	andi r24,lo8(1)
	andi r25,hi8(1)
	tst r24
	breq .L114
	ldd r30,Y+3
	ldd r31,Y+4
	ldd r18,Z+2
	ldd r19,Z+3
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	cp r18,r24
	cpc r19,r25
	brne .L114
	ldd r30,Y+3
	ldd r31,Y+4
	ld r24,Z
	ldd r25,Z+1
	ori r24,lo8(12)
	ldd r30,Y+3
	ldd r31,Y+4
	std Z+1,r25
	st Z,r24
	ldd r24,Y+1
	ldd r25,Y+2
	rcall stop_utimer
.L114:
	ldd r24,Y+1
	ldd r25,Y+2
	adiw r24,1
	std Y+2,r25
	std Y+1,r24
.L112:
	ldd r24,Y+1
	ldd r25,Y+2
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L113
/* epilogue: frame size=4 */
	adiw r28,4
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
	pop r29
	pop r28
	ret
/* epilogue end (size=9) */
/* function count_utimer size 77 (58) */
	.size	count_utimer, .-count_utimer
.global	int_TIM0_OVF
	.type	int_TIM0_OVF, @function
int_TIM0_OVF:
/* prologue: frame size=5 */
	push __zero_reg__
	push __tmp_reg__
	in __tmp_reg__,__SREG__
	push __tmp_reg__
	clr __zero_reg__
	push r18
	push r19
	push r20
	push r21
	push r22
	push r23
	push r24
	push r25
	push r26
	push r27
	push r30
	push r31
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,5
	out __SP_H__,r29
	out __SP_L__,r28
/* prologue end (size=24) */
	ldi r30,lo8(70)
	ldi r31,hi8(70)
	ldi r24,lo8(-9)
	st Z,r24
	lds r24,sys_clk1
	lds r25,(sys_clk1)+1
	adiw r24,1
	sts (sys_clk1)+1,r25
	sts sys_clk1,r24
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	adiw r24,1
	sts (sys_clk0)+1,r25
	sts sys_clk0,r24
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	andi r25,hi8(32767)
	sts (sys_clk0)+1,r25
	sts sys_clk0,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ld r24,Z
	std Y+5,r24
	ldd r24,Y+5
	com r24
	std Y+5,r24
	ldi r30,lo8(40)
	ldi r31,hi8(40)
	ldd r24,Y+5
	st Z,r24
	rcall wait_5m
	std Y+2,__zero_reg__
	std Y+1,__zero_reg__
	rjmp .L120
.L121:
	ldd r18,Y+1
	ldd r19,Y+2
	mov r25,r19
	mov r24,r18
	lsl r24
	rol r25
	add r24,r18
	adc r25,r19
	lsl r24
	rol r25
	subi r24,lo8(-(utim_table))
	sbci r25,hi8(-(utim_table))
	std Y+4,r25
	std Y+3,r24
	ldd r30,Y+3
	ldd r31,Y+4
	ld r24,Z
	ldd r25,Z+1
	andi r24,lo8(1)
	andi r25,hi8(1)
	tst r24
	breq .L122
	ldd r30,Y+3
	ldd r31,Y+4
	ldd r18,Z+2
	ldd r19,Z+3
	lds r24,sys_clk0
	lds r25,(sys_clk0)+1
	cp r18,r24
	cpc r19,r25
	brne .L122
	ldd r30,Y+3
	ldd r31,Y+4
	ld r24,Z
	ldd r25,Z+1
	ori r24,lo8(12)
	ldd r30,Y+3
	ldd r31,Y+4
	std Z+1,r25
	st Z,r24
	ldd r24,Y+1
	ldd r25,Y+2
	rcall stop_utimer
.L122:
	ldd r24,Y+1
	ldd r25,Y+2
	adiw r24,1
	std Y+2,r25
	std Y+1,r24
.L120:
	ldd r24,Y+1
	ldd r25,Y+2
	cpi r24,5
	cpc r25,__zero_reg__
	brlo .L121
/* epilogue: frame size=5 */
	adiw r28,5
	cli
	out __SP_H__,r29
	out __SP_L__,r28
	pop r29
	pop r28
	pop r31
	pop r30
	pop r27
	pop r26
	pop r25
	pop r24
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop __tmp_reg__
	out __SREG__,__tmp_reg__
	pop __tmp_reg__
	pop __zero_reg__
	reti
/* epilogue end (size=23) */
/* function int_TIM0_OVF size 149 (102) */
	.size	int_TIM0_OVF, .-int_TIM0_OVF
	.lcomm sys_cyc_60s,2
	.lcomm state,1
	.lcomm shutter_cyc1,2
	.lcomm shutter_count1,2
	.lcomm sw_in,1
	.lcomm sw_in_pre,1
	.comm sys_clk0,2,1
	.comm sys_clk1,2,1
	.comm nw_count,2,1
	.comm test_bb,1,1
	.comm utim_table,30,1
/* File "avr_main.c": code 1432 = 0x0598 (1041), prologues 206, epilogues 185 */
