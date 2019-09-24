#include "avr.h"
#include <io.h>
#include "avr_typedef.h"
#include "avr_time.h"
#include "lcd_lib.h"

int main(void)
{

	volatile uint8_t a, b;
	volatile uint8_t test = 0xaa;

	lcd_ini();
	for(a = 1; a < 10; a++)
		b++;

	while(1){
		b++;

		test++;
	}
	return 0;
}

ISR_JUMP_DUMMY_TRAP(INT0_vect)
//ISR(INT0_vect) { nop(); }
ISR_JUMP_RESET(INT1_vect)
//ISR(INT1_vect) { nop(); }
ISR(PCINT0_vect) { nop(); }
ISR(PCINT1_vect) { nop(); }
ISR(PCINT2_vect) { nop(); } 
ISR(WDT_vect) { nop(); }
ISR(TIM2COMPA_vect) { nop(); } 
ISR(TIM2COMPB_vect) { nop(); }
ISR(TIM2OVF_vect) { nop(); } 
ISR(TIM1CAPT_vect) { nop(); } 
ISR(TIM1COMPA_vect) { nop(); }
ISR(TIM1COMPB_vect) { nop(); } 
ISR(TIM1OVF_vect) { nop(); } 
ISR(TIM0COMPA_vect) { nop(); }
ISR(TIM0COMPB_vect) { nop(); } 
ISR(TIM0OVF_vect) { nop(); } 
ISR(SPICMP_vect) { nop(); } 
ISR(USARTRXCMP_vect) { nop(); } 
ISR(USARTDEMP_vect) { nop(); } 
ISR(USARTTXCMP_vect) { nop(); } 
ISR(ADCCMP_vect) { nop(); } 
ISR(EERDY_vect) { nop(); } 
ISR(ANACMP_vect) { nop(); } 
ISR(TWI_vect) { nop(); } 
ISR(SPMRDY_vect) { nop(); } 

