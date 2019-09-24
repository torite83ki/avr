#include "2313def.h"


.global	read_byte_eeprom
.func	read_byte_eeprom	
read_byte_eeprom:
// eeprom address
// lower r24
// upper r25
	mov	ZH,r23		// read data storring buffer address
	mov	ZL,r22
check_write:
	sbic	EECR,EEWE	// check the write access occured
	rjmp	check_write
	out	EEAR,r24
	sbi	EECR,EERE
	in	r25,EEDR
	st	Z,r25
	ret
.endfunc
