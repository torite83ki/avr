#include "2313def.h"


.global	putc
.func	putc
putc:
	sbis	USR,UDRE
	rjmp	putc
	out	UDR,r24
	ret
.endfunc
