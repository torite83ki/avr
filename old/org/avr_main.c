#include "2313def.h"
#include "avr.h"


//#define io_register(p) *( (byte*)p + 0x20)
#define DIGIT1 0xf7 	// 1111 0111
#define DIGIT2 0xfb 	// 1111 1011
#define DIGIT3 0xfd 	// 1111 1101
#define DIGIT4 0xfe 	// 1111 1110

#define OUT_EN 0x08 	// 0000 1000
#define L0_CLK 0x10 	// 0001 0000
#define L1_CLK 0x20 	// 0010 0000
#define L2_CLK 0x40 	// 0100 0000

#define D1_MSK 0x1f 	// 0001 1111
#define D2_MSK 0xe0 	// 1110 0000
#define D3_MSK 0x03 	// 0000 0011
#define D4_MSK 0x7c 	// 0111 1100
#define D5_MSK 0x80 	// 1000 0000
#define D6_MSK 0x07 	// 0000 1111

#define ON     0x01
#define OFF    0x00


void timer_ini(void) __attribute__((naked));
void port_ini(void) __attribute((naked));
void parameter_ini(void) __attribute((naked));


void int_INT0(void) __attribute__ ((naked));
void int_INT1(void) __attribute__ ((naked));
void int_TIM1_CAPT1(void) __attribute__ ((naked));
void int_TIM1_COMP1(void) __attribute__ ((naked));
void int_TIM1_OVF1(void) __attribute__ ((signal));
void int_TIM0_OVF0(void) __attribute__ ((signal));
void int_UART_RX(void) __attribute__ ((naked));
void int_UART_UDRE(void) __attribute__ ((naked));
void int_UART_TX(void) __attribute__ ((naked));
void int_ANA_COMP(void) __attribute__ ((naked));

volatile static byte state; /* state flag*/
volatile static byte m_sec; /* count 100msec*/
volatile static byte sec;   /* count 1sec*/
volatile static byte min;   /* count 1minutes */
volatile static byte hour;  /* count 10 minutes */
volatile static byte day;   /* count day */

volatile static word count;
volatile static byte interval; /* led off -> on interval */
volatile static byte interval_count; /* interval counter */


int main(void){

	byte m,n;
	
	/* disenable interrupt */
	//asm("cli");
	cli();
	/* initialize register, io port, timer0 */
  	port_ini();
	//load_char_data();
	parameter_ini();
	timer_ini();

	

		for( n = 1; n <= 5; n++){
			wait();
		}


	n = 0;
	m = 0;
	
	sei();
	
	while(1){
		if(m_sec == 0){
			count++;
			if(count >= 180)
				count = 0;
		}
			
		if(n >= interval_count  ){
			if(m == 0){
				m = 1;
			}
		}else {
			if(m == 1){
				m = 0;
			}
		}
		switch(count){
			case 0:
				n = 5;
				break;
			case 10:
				n = 5;
				break;
			case 20:
				n = 5;
				break;
			case 30:
				n = 5;
				break;
			case 40:
				n = 6;
				break;
			case 50:
				n = 6;
				break;
			case 60:
				n = 7;
				break;
			case 70:
				n = 7;
				break;
			case 80:
				n = 8;
				break;
			case 90:
				n = 8;
				break;
			case 100:
				n = 9;
				break;
			case 110:
				n = 9;
				break;
			case 120:
				n = 8;
				break;
			case 130:
				n = 8;
				break;
			case 140:
				n = 7;
				break;
			case 150:
				n = 7;
				break;
			case 160:
				n = 6;
				break;
			case 170:
				n = 6;
				break;
				

		}
	}
	return 0;
}


/* follows are Sub routine */

 




void timer_ini(void){
/**************************************
 * Timer/Counter0 Initialize
 * TCCR0	: Timer/Counter0 control register
 * TCNT0	: countting value setting
 *
 * 
 * Timer/Counter0 control register : TCCR0
 *  7 6 5 4 3 2 1 0 : bit
 *  * * * * * | | |
 *            | | +- CS0
 *            | +--- CS1
 *            +----- CS2
 *
 * CS0,1,2 are defined in 2313def.h file.
 *  CS	|  CS2	|  CS1	|  CS0	| Description
 *  ----+-------+-------+-------+---------
 *  	|   0	|   0	|   0	| Stop, the Timer/Counter0 is stopped.
 *  	+-------+-------+-------+---------
 *  	|   0	|   0	|   1	| CK
 *  	+-------+-------+-------+---------
 *  	|   0	|   1	|   0	| CK/8
 *  	+-------+-------+-------+---------
 *  	|   0	|   1	|   1	| CK/64
 *  	+-------+-------+-------+---------
 *  	|   1	|   0	|   0	| CK/256
 *  	+-------+-------+-------+---------
 *  	|   1	|   0	|   1	| CK/1024
 *  	+-------+-------+-------+---------
 *  	|   1	|   1	|   0	| External Pin T0, falling edge
 *  	+-------+-------+-------+---------
 *  	|   1	|   1	|   1	| External Pin To, rising edge
 *  	+-------+-------+-------+---------
 *
 * 
 * timer0 set for about 1m Sec timer
 * clock = 10.000 MHz
 * 10.000 MHz * (1/256) = 39.0625 kHz
 * 1 / 39.0625 kHz = 25.6 uSec
 * 39 * 25.6 uSec = 0.9984 mSec
 * 256 - 39 = 217 (0xd9)
 * -> TCCR0 = 0x08
 * -> TCNT0 = 0xd9
 *
 * clock = 8.000 MHz
 * 1 / 8.000 MHz = 	0.125 uSec
 * 8 / 8.000 MHz = 	1.000 uSec
 * 16 / 8.000 MHz =	2.000 uSec
 * 64 / 8.000 MHz = 	8.000 uSec
 * 256 / 8.000 MHz =	32.00 uSec
 * 1024 / 8.000 MHz = 	128.0 uSec
 *
 *
 * Timer/Counter1 Initialize
 * TCCR1A:	mode setting
 * TCCR1B:	clock setting
 * TCNT1H, L:	countting value setting
 * OCR1AH, L:	compare value setting
 *
 * TCCR1A:
 *  7 6 5 4 3 2 1 0 : bit
 *  | | * * * * | +-- PWM10
 *  | |         +---- PWM11
 *  | +-------------- COM1A0
 *  +---------------- COM1A1
 *
 * COM1A0,1 are defined in 2313def.h file.
 *  	| COM1A1| COM1A0| Descrption
 *  ----+-------+-------+---------
 *  	|   0	|   0	| Timer/Counter1 disconnected from output pin OC1
 *  	+-------+-------+---------
 *  	|   0	|   1	| Toggle the OC1 output line.
 *  	+-------+-------+---------
 *  	|   1	|   0	| Clear the OC1 output line (to zero).
 *  	+-------+-------+---------
 *  	|   1	|   1	| Set the OC1 output line (to one).
 *  	+-------+-------+---------
 *
 * 
 * PWM10,11 are defined in 2313def.h file.
 *  	| PWM11 | PWM10 | Description
 *  ----+-------+-------+---------
 *  	|   0	|   0	| PWM operation of Timer/Counter1 is disabled
 *  	+-------+-------+---------
 *  	|   0	|   1	| Timer/Counter1 is an 8-bit PWM
 *  	+-------+-------+---------
 *  	|   1	|   0	| Timer/Counter1 is a 9-bit PWM
 *  	+-------+-------+---------
 *  	|   1	|   1	| Timer/Counter1 is a 10-bit PWM
 *  	+-------+-------+---------
 *
 *
 * On the  PWM mode, COM1A0,1 bits are different function as follows  
 * COM1A0,1 are defined in 2313def.h file.
 *  	| COM1A1| COM1A0| Effect on OC1
 *  ----+-------+-------+---------
 *  	|   0	|   0	| Not connected
 *  	+-------+-------+---------
 *  	|   0	|   1	| Not connected
 *  	+-------+-------+---------
 *  	|   1	|   0	| Cleard on compare match, up-counting.
 *  	|	|	| Set on compare match, down-counting
 *  	|	|	| (non-inverted PWM).
 *  	+-------+-------+---------
 *  	|   1	|   1	| Cleard on compare match, down-counting,
 *  	|	|	| Set on compare match, up-counting
 *  	|	|	| (inverted PWM).
 *  	+-------+-------+---------
 *  	
 * TCCR1B:
 *  7 6 5 4 3 2 1 0 : bit
 *  | | * * | | | +-- CS10
 *  | |     | | +---- CS11
 *  | |     | +------ CS12
 *  | |     +-------- CTC1
 *  | +-------------- ICES1
 *  +---------------- ICNC1
 *
 * ICES1,ICNC1 are defined in 2313def.h file.
 *  ICNC1	: Input Capture1 Noise Canceler(4 CKs)
 *  ICES1	: Input Capture1 Edge Select
 *  CTC1	: Clear Timer/Counter1 on Compare Match
 * 
 * CS10,11,12 are defined in 2313def.h file.
 *  CS	|  CS12	|  CS11	|  CS10	| Description
 *  ----+-------+-------+-------+---------
 *  	|   0	|   0	|   0	| Stop, the Timer/Counter1 is stopped.
 *  	+-------+-------+-------+---------
 *  	|   0	|   0	|   1	| CK
 *  	+-------+-------+-------+---------
 *  	|   0	|   1	|   0	| CK/8
 *  	+-------+-------+-------+---------
 *  	|   0	|   1	|   1	| CK/64
 *  	+-------+-------+-------+---------
 *  	|   1	|   0	|   0	| CK/256
 *  	+-------+-------+-------+---------
 *  	|   1	|   0	|   1	| CK/1024
 *  	+-------+-------+-------+---------
 *  	|   1	|   1	|   0	| External Pin T1, falling edge
 *  	+-------+-------+-------+---------
 *  	|   1	|   1	|   1	| External Pin T1, rising edge
 *  	+-------+-------+-------+---------
 *
 * Timer TOP Values and PWM Frequency
 *
 *	| PWM Resolution|    Timer TOP Value	|   Frequency	|
 *  ----+---------------+-----------------------+---------------+
 * 	|     8-bit	|	0x00ff(255)	|  f(TC)/510	|
 *      +---------------+-----------------------+---------------+
 * 	|     9-bit 	|	0x01ff(511)	|  f(TC)/1022	|
 *      +---------------+-----------------------+---------------+
 * 	|    10-bit	|	0x03ff(1023)	|  f(TC)/2046	|
 *      +---------------+-----------------------+---------------+
 * 
 * 
 * 
 * 
 *  
 ***************************************/

	/* set clock 10 MHz */
	/* set Timer/Counter0 prescaler 8 */
	io_register(TCCR0) = BIT_CS01; /* set prescaler 1/8 */
	//io_register(TCNT0) = 0x64; /* set Overflow count 100 */
	io_register(TCNT0) = 1;
	
	/* set PWM mode
	 * 8-bitPWM 
	 * set up-counting, clear down-counting
	 * Timer/Counter1 Prescaler :	 1/1024
	 * counter value :		 0x00ff = 255 
	 * compare match value :	 0x7f = 127 
	 *
	 * */
	io_register(TCCR1A) = BIT_COM1A1 | BIT_PWM10; /* set PWM mode */
	io_register(TCCR1B) = BIT_CS12 | BIT_CS10; /* set prescaler 1/1024 */
	io_register(TCNT1H) = 0x00; /* set high byte 0x00 */
	io_register(TCNT1L) = 0xff; /* set low byte 0xff */
	io_register(OCR1AH) = 0x00; /* set high byte */
	io_register(OCR1AL) = 0x7f; /* set low byte 0x7f */

	/* 
	 * 
	 * enable Timer/Counter0 Overflow Interrupt : BIT_TOIE0 = 0x02
	 * enable Timer/Counter1 Overflow Interrupt : BIT_TOIE1 = 0x80
	 * 
	 */	
	//io_register(TIMSK) = BIT_TOIE1 | BIT_TOIE0;
	//io_register(TIMSK) = 0x02;
	
	asm("ret");

}




void port_ini(void){
	/* PORTB set all output */
	/* PWM mode set DDRB3 set one */
	
	io_register(DDRB) = POUT7 | POUT6 | POUT5 | POUT4 | POUT3 | POUT2 | POUT1 | POUT0;
	/* PORTD set all output */
	io_register(DDRD) = POUT6 | POUT5 | POUT4 | POUT3 | POUT2 | POUT1 | POUT0;
	asm("ret");
}


void parameter_ini(void){
	m_sec = 0; /* count 100 msec */
	sec = 0;   /* count 1 sec */
	min = 0;   /* count 1 minutes */
	hour = 0;  /* count 10 minutes */
	day = 0;   /* count day */

	count = 0;
	
	interval = 10;
	interval_count = 0;
	
	asm("ret");
}




void int_TIM0_OVF0(void){
 
	io_register(TCNT0) = 0x64; /* set Overflow count */
	state++;	
	interval_count++;
	if(interval_count >= interval)
		interval_count = 0;
	if (state >= 10){
		state = 0;
		m_sec++; // 1mSec
		if(m_sec == 10){
			m_sec = 0;
			sec++; // 10mSec
			if(sec == 10){
				sec = 0;
				min++; // 100 msec
				if(min == 10){
					min = 0;
					hour++;
					if(hour == 10){
						hour = 0; // 1Sec
					}
				}
			}
		}
	}
  
}



void int_INT0(void){
	asm("rjmp main");
}
void int_INT1(void){
	asm("rjmp main");
}
void int_TIM1_CAPT1(void){
	asm("rjmp main");
}
void int_TIM1_COMP1(void){
asm("rjmp main");
}
void int_TIM1_OVF1(void){
	io_register(TCNT1H) = 0x03; /* set high byte 0x03 */
	io_register(TCNT1L) = 0xE8; /* set low byte 0xE8 */
}

void int_UART_RX(void){
asm("rjmp main");
}
void int_UART_UDRE(void){
asm("rjmp main");
}
void int_UART_TX(void){
asm("rjmp main");
}
void int_ANA_COMP(void){
asm("rjmp main");
}


