	.file	"nop_f.c"
	.arch at90s2313
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__tmp_reg__ = 0
__zero_reg__ = 1
	.global __do_copy_data
	.global __do_clear_bss
	.text
.global	wait
	.type	wait, @function
wait:
/* prologue: frame size=0 */
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue end (size=4) */
	sts wait0,__zero_reg__
.L2:
	lds r24,wait0
	cpi r24,lo8(33)
	brsh .L1
	sts wait1,__zero_reg__
.L5:
	lds r24,wait1
	cpi r24,lo8(33)
	brsh .L4
	sts wait2,__zero_reg__
.L8:
	lds r24,wait2
	cpi r24,lo8(33)
	brsh .L7
	lds r24,wait2
	subi r24,lo8(-(1))
	sts wait2,r24
	rjmp .L8
.L7:
	lds r24,wait1
	subi r24,lo8(-(1))
	sts wait1,r24
	rjmp .L5
.L4:
	lds r24,wait0
	subi r24,lo8(-(1))
	sts wait0,r24
	rjmp .L2
.L1:
/* epilogue: frame size=0 */
	pop r29
	pop r28
	ret
/* epilogue end (size=3) */
/* function wait size 43 (36) */
	.size	wait, .-wait
.global	nop_f
	.type	nop_f, @function
nop_f:
/* prologue: frame size=0 */
/* prologue: naked */
/* prologue end (size=0) */
/* #APP */
	nop
	nop
/* #NOAPP */
/* epilogue: frame size=0 */
/* epilogue: naked */
/* epilogue end (size=0) */
/* function nop_f size 4 (4) */
	.size	nop_f, .-nop_f
	.lcomm wait0,1
	.lcomm wait1,1
	.lcomm wait2,1
/* File "nop_f.c": code   47 = 0x002f (  40), prologues   4, epilogues   3 */
