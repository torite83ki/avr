#include "2313def.h"


.global	putc
.func	putc
putc:
	sbis	USR,UDRE	; check the UDRE(UDR Empty) bit 
				; that can be written to the UDR
	rjmp	putc		;
	out	UDR,r24		; transferres the Data to the UDR
	ret
.endfunc
