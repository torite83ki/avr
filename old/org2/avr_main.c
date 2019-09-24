/*
 *
 *  avr_relay11.c
 *  avr relay control program
 *   int0,1 : interrupt
 *   serial data output 
 *   puts_avr function
 *   btohex function test
 *   scan_time word constant 
 *
 *  used TIM0 interrupt
 *  
 *  coded by H.Takenobu
 *  2007.12.23 rev.0
 *
 */

//#define DEBUG	0x01

#include "2313def.h"
#include "avr.h"
//#include "avr_func.h"

/* 
 * user defined constant
 */
#define ON     0x01
#define OFF    0x00
#define T0_OVF 0xd9	// Timer 0 overflow value
#define PB_OM  0x03	// Port B output bit mask

#define TF_1ms	0x00	// 1msec timer flag = 0 bit
#define TF_10ms	0x01	// 10msec timer flag = 1 bit
#define TF_100ms 0x02	// 100msec timer flag = 2 bit
#define TF_1s	0x03	// 1sec timer flag = 3 bit
#define TF_1min	0x04	// 1min timer flag = 4 bit
#define TF_1h	0x05	// 1h timer flag = 5 bit

#define BAUD_P	0x40	// Constant for UART Baud Rate Register 

/*
 * user defined functions
 */
void timer_flag_check(void) NAKED;
void interrupt_ini(void) NAKED;
void timer_ini(void) NAKED;
void port_ini(void) NAKED;
void parameter_ini(void) NAKED;

void uart_ini(void) NAKED;
void putc(byte c) NAKED;
void puts_avr(byte *string) NAKED;
void btohex(byte *ch);

/*
 * interrupt handlers
 */
void int_INT0(void) SIGNAL_INT;
void int_INT1(void) SIGNAL_INT;
void int_TIM1_CAPT1(void) NAKED;
void int_TIM1_COMP1(void) NAKED;
void int_TIM1_OVF1(void) NAKED;
void int_TIM0_OVF0(void) SIGNAL_INT;
void int_UART_RX(void) NAKED;
void int_UART_UDRE(void) NAKED;
void int_UART_TX(void) NAKED;
void int_ANA_COMP(void) NAKED;

/*
 * sram static valuables
 */
volatile static byte state; /* state flag*/
volatile static byte m1_sec; /* count 10msec*/
volatile static byte m2_sec; /* count 100msec*/
volatile static byte sec;   /* count 1sec*/
volatile static byte min;   /* count 1minutes */
volatile static byte hour;  /* count 10 minutes */
volatile static byte day;   /* count day */
volatile static byte tf;	/* timer flag */
volatile static byte tf_up;	/* up-edge of the timer flag */

//volatile static word count;
//volatile static byte interval; /* led off -> on interval */
//volatile static byte interval_count; /* interval counter */

volatile static byte led_data;	/* led data 1:off,0:on*/
volatile static byte output_data;	/* output data for pio */
//volatile static byte message[8];
volatile static byte mess_byte[3];
volatile static byte mess_systime[3];
volatile static byte sys_clk;
volatile static byte cnt_1;
volatile static byte cnt_2;
volatile static word scan_time;


int main(void){
	byte buf = 0;
	/* disnable interrupt */
	cli();
	/* initialize register, io port, timer0 */
  	port_ini();
	parameter_ini();
	interrupt_ini();
	timer_ini();
	uart_ini();

	
	/* test function */
//	nop_f();
#ifdef	DEBUG
	/* It checks for parameters, definitions. */
	byte n;
	for(n = 0;n < 20; n++)
	{
		io_register(PORTB) = led_data;
		//io_register(PORTD) = led_data;
		wait();
		wait();
		wait();
		wait();
		led_data = ~led_data;
	}
#endif
	
	
	/* enable interrupt */
	sei();
	/* sending the message to serial console */	
				
			putc('H');
			putc('E');
			putc('L');
			putc('L');
			putc('O');
			putc('\n');
			putc('\r');
	
	/* main loop */
	while(1)
	{
		/* check the scan time */
		scan_time++;
		if((tf_up & (1<<TF_10ms)) == (1<<TF_10ms)){
			cnt_2++;
			putc('s');
			putc('c');
			putc('a');
			putc('n');
			putc('@');
			putc('=');
			buf = (byte) (scan_time >>8);
			*mess_systime = buf;
			btohex(mess_systime);
			puts_avr(mess_systime);
			buf = (byte) (scan_time & 0xff);
			*mess_systime = buf;
			btohex(mess_systime);
			puts_avr(mess_systime);
			
			putc('\t');
			mess_byte[0] = cnt_2;
			btohex(mess_byte);
			puts_avr(mess_byte);	
			putc('x');
			putc('0');
			putc('m');
			putc('s');
			putc('e');
			putc('c');
		
			putc('\t');
			putc('c');
			putc('n');
			putc('t');
			putc('=');
			mess_byte[0] = cnt_1;
			btohex(mess_byte);
			puts_avr(mess_byte);	

			putc('\n');
			putc('\r');

		}	
		
		//output_data = 0x00;	//upper 6bit mask
		io_register(PORTB) = output_data & PB_OM;
		
		timer_flag_check();	
	}
		return 0;
}

/* follows are Sub routine */
void btohex(byte *ch){
	byte buf1,buf2;

	buf1 = ch[0] & 0x0f;
	if(buf1 <= 0x09){
		buf1 = buf1 + 0x30;
	} else {
		buf1 = buf1 + 0x37;
	}
	buf2 = buf1;
	buf1 = ch[0];
	buf1 = buf1 >> 4;
	if(buf1 <= 0x09){
		buf1 = buf1 + 0x30;
	} else {
		buf1 = buf1 + 0x37;
	}
	ch[0] = buf1;
	ch[1] = buf2;
	//	ret();
}
	
void puts_avr(byte *string){
	byte n = 0;
	while(string[n] != '\0')
		putc(string[n++]);
	ret();
}

void uart_ini(void){
	io_register(UBRR) = BAUD_P;
	io_register(UCR) = (1 << TXEN);
	ret();
}

void timer_flag_check(void){ 

	tf_up = 0;
	/* reflesh the time flag*/
	if((tf & (1<<TF_1ms)) == (1<<TF_1ms)){
		state++;
		sys_clk++;
		if(state >= 10){
 			state = 0;
			m1_sec++; // 10mSec
			tf = tf | (1<<TF_10ms);
		}
		if(m1_sec >= 10){
			m1_sec = 0;
			m2_sec++; // 100mSec
			tf = tf | (1<<TF_100ms);
		}
		if(m2_sec >= 10){
			m2_sec = 0;
			sec++; // 1Sec
			tf = tf | (1<<TF_1s);
		}
		if(sec >= 60){
			sec = 0;
			min++; // 1min
			tf = tf | (1<<TF_1min);
		}
		if(min >= 60){
			min = 0;
			hour++;// 1hour
			tf = tf | (1<<TF_1h);
		}
		if(hour >= 24){
			hour = 0; // 1day
		}
	}
	/* reflesh the up-edgh of the time flag */
	if((tf & (1<<TF_1ms)) == (1<<TF_1ms))
	{
		tf = tf & ( ~(1<<TF_1ms));
		tf_up = tf_up | (1<<TF_1ms);
	}
	if((tf & (1<<TF_10ms)) == (1<<TF_10ms))
	{
		tf = tf & ( ~(1<<TF_10ms));
		tf_up = tf_up | (1<<TF_10ms);
	}
	if((tf & (1<<TF_100ms)) == (1<<TF_100ms))
	{
		tf = tf & (~(1<<TF_100ms));
		tf_up = tf_up | (1<<TF_100ms);
	}
	if((tf & (1<<TF_1s)) == (1<<TF_1s))
	{
		tf = tf & (~(1<<TF_1s));
		tf_up = tf_up | (1<<TF_1s);
	}
	if((tf & (1<<TF_1min)) == (1<<TF_1min))
	{
		tf = tf & (~(1<<TF_1min));
		tf_up = tf_up | (1<<TF_1min);
	}
	if((tf & (1<<TF_1h)) == (1<<TF_1h))
	{
		tf = tf & (~(1<<TF_1h));
		tf_up = tf_up | (1<<TF_1h);
	}
	ret();
}

void interrupt_ini(void){
	/*
	 * General interrupt Initialize
	 *
	 *  GIMSK register
	 *  7 6 5 4 3 2 1 0	
	 *  | |
	 *  | +----------------- INT0
	 *  +------------------- INT1
	 */
	io_register(GIMSK) = (1<<INT1) | (1<<INT0);
	/* low level trigger */
	io_register(MCUCR) = 0x00;
	ret();
}	

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
 * -> TCCR0 = 0x04
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
	io_register(TCCR0) = (1<<CS02); /* set prescaler 1/256 */
	io_register(TCNT0) = T0_OVF; /* set Overflow count 100 */
	//io_register(TCNT0) = 1;
	
	/* set PWM mode
	 * 8-bitPWM 
	 * set up-counting, clear down-counting
	 * Timer/Counter1 Prescaler :	 1/1024
	 * counter value :		 0x00ff = 255 
	 * compare match value :	 0x7f = 127 
	 *
	 * */
//	io_register(TCCR1A) = (1<<COM1A1) | (1<<PWM10); /* set PWM mode */
//	io_register(TCCR1B) = (1<<CS12) | (1<<CS10); /* set prescaler 1/1024 */
//	io_register(TCNT1H) = 0x00; /* set high byte 0x00 */
//	io_register(TCNT1L) = 0xff; /* set low byte 0xff */
//	io_register(OCR1AH) = 0x00; /* set high byte */
//	io_register(OCR1AL) = 0x10; /* set low byte 0x7f */

	/* 
	 * 
	 * enable Timer/Counter0 Overflow Interrupt : BIT_TOIE0 = 0x02
	 * enable Timer/Counter1 Overflow Interrupt : BIT_TOIE1 = 0x80
	 * 
	 */	
	io_register(TIMSK) = (1<<TOIE0);
	ret();
}

void port_ini(void){
	/* PORTB set all pull-up */
	io_register(PORTB) = POUT7 | POUT6 | POUT5 | POUT4 |\
	       		    POUT3 | POUT2 | POUT1 | POUT0;
	/* PORTB set all output */
	io_register(DDRB) = POUT7 | POUT6 | POUT5 | POUT4 |\
	       		    POUT3 | POUT2 | POUT1 | POUT0;
	/* PORTD PD6 set input */
	io_register(DDRD) = 0x00;
	ret();
}

void parameter_ini(void){
	state = 0;
	m1_sec = 0; /* count 10 msec */
	m2_sec = 0; /* count 100 msec */
	sec = 0;   /* count 1 sec */
	min = 0;   /* count 1 minutes */
	hour = 0;  /* count 10 minutes */
	day = 0;   /* count day */
	tf = 0;
	tf_up = 0;
	
//	count = 0;
	sys_clk = 0x00;
	cnt_1 = 0;
	cnt_2 = 0;	
	scan_time = 0;
	
	output_data = 0x00; /* all outputs are off */
	
	mess_byte[0] = NULL;
	mess_byte[1] = NULL;
	mess_byte[2] = NULL;

	mess_systime[0] = '0';
	mess_systime[1] = '0';
	mess_systime[2] = NULL;
	
	ret();
}

/* interrupt handlers */
void int_TIM0_OVF0(void){
	io_register(TCNT0) = T0_OVF; /* set Overflow count */
	tf = tf | (1<<TF_1ms);
}
void int_INT0(void){
	//asm("rjmp main");
	led_data = 0xff;
	cnt_1++;
}
void int_INT1(void){
	//asm("rjmp main");
	led_data = 0x01;
	cnt_1++;
}
void int_TIM1_CAPT1(void){
	asm("rjmp main");
}
void int_TIM1_COMP1(void){
	asm("rjmp main");
}
void int_TIM1_OVF1(void){
	asm("rjmp main");
	//io_register(TCNT1H) = 0x03; /* set high byte 0x03 */
	//io_register(TCNT1L) = 0xE8; /* set low byte 0xE8 */
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


