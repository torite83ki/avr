#include "io.h"


.global	write_byte_eeprom
.func	wrtie_byte_eeprom	
wrtie_byte_eeprom:
// eeprom address
// lower r24
// upper r25
// write data
// r23
check_busy:
#if __AVR_ARCH__ == 2
	sbic	EECR, EEPE	// check the write access if occure
	rjmp	check_busy
	out	EEAR, r24	// set address
	out	EEDR, r23	// set data
	sbi	EECR, EEPM1	// write only
	sbi	EECR, EERIE	// program master enable
	sbi	EECR, EEPE	// program enable
#elif __AVR_ARCH__ == 4
	sbic	EECR, EEPE	// check write access if occure
	rjmp	check_busy
	out	EEARL, r24	// set address
	out	EEARH, r25	// set address
	out	EEDR,  r23	// set data
	sbi	EECR, EEPM1	// write only
	sbi	EECR, EERIE	// program master enable
	sbi	EECR, EEPE	// program enable
#endif
	ret
.endfunc
