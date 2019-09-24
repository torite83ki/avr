#include "2313def.h"


.global	r_eep
.func	r_eep	
r_eep:
// eeprom address
// lower r24
// upper r25
	mov	ZH,r23		// read data storing buffer address
	mov	ZL,r22
check_write:
	sbic	EECR,EEWE
	rjmp	check_write
	out	EEAR,r24
	sbi	EECR,EERE
	in	r25,EEDR
	st	Z,r25
	ret
.endfunc
