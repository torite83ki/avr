.global wait_1m
.func wait_1m

.set	WAIT_CNT1, 133
.set	WAIT_CNT2, 50
.set	WAIT_CNT3, 250
.set	WAIT_CNT4, 100
wait_1m:
	push r24	// 2   cycle
	push r25	// 2   cycle
	ldi r25,WAIT_CNT2	// 1   cycle
loop00:
	ldi r24,WAIT_CNT1	// 1   cycle
loop01:
	dec r24		// 1   cycle
	brne loop01	// 1/2 cycle
	dec r25		// 1   cycle
	brne loop00	// 1/2 cycle
	pop r25		// 2   cycle
	pop r24		// 2   cycle
	ret
.endfunc

.global wait_5m
.func wait_5m
	wait_5m:
	push r24
	push r25
	ldi r25,WAIT_CNT3
loop10:
	ldi r24,WAIT_CNT1
loop11:
	dec r24
	brne loop11
	dec r25
	brne loop10
	pop r25
	pop r24
	ret
.endfunc

.global wait_5u
.func wait_5u
wait_5u:
	nop
	nop
	nop
	nop
	ret
.endfunc
