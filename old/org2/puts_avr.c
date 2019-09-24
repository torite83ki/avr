#include "avr.h"

extern void putc(byte ch);
extern void puts_avr(byte *string) NAKED;

void puts_avr(byte *string){
	byte n = 0;
	while(string[n] != '\0')
		putc(string[n++]);
	ret();
} 
