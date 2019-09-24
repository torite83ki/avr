#include "io.h"


.global	putc
.func	putc
putc:
#if __AVR_ARCH__ == 2
	sbis	USR,UDRE
	rjmp	putc
	out	UDR,r24
#elif __AVR_ARCH__ == 4
	sbis	UCSRA,UDRE
	rjmp	putc
	out	UDR,r24
#endif
	ret
.endfunc
