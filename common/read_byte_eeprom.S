#include "io.h"


.global	read_byte_eeprom
.func	read_byte_eeprom	
read_byte_eeprom:
// set eeprom address
// lower r24
// upper r25
// return data pointer
// lower r22
// upper r23
	push	ZL
	push	ZH
	movw	r22, ZL
check_write:
#if __AVR_ARCH__ == 2
	sbic	EECR,EEPE	// check the write access occured
	rjmp	check_write
	out	EEAR,r24
	sbi	EECR,EERE
	in	r25,EEDR
	st	Z,r25
#elif __AVR_ARCH__ == 4
	sbic	EECR,EEPE	// check write access if occure
	rjmp	check_write
	out	EEARL, r24
	out	EEARH, r25
	sbi	EECR,EERE
	in	r25, EEDR
	st	Z,r25
#endif
	pop	ZH
	pop	ZL
	ret
.endfunc
