/*
 *  avr_main.c
 *  device = ATtiny13/A
 *
 *  used interrupts
 *  TIM0
 *  
 *  coded by H.Takenobu
 *  2010.11.3 rev.0
 *
 */


#include "tn13def.h"
#include "avr.h"

/* 
 * user defined constant
 */
#define CLK_PR 0x01	// clock prescalse register
#define CLK_PE 0x80	// clock prescalse change enable

#define T0_OVF -48	// Timer 0 overflow value -> 10mS
#define PB_OM  0x03	// 0000 0011 Port B output bit mask
#define PB_PULLUP 0x3b	// 0011 1011 Port B input pull-up bit and 
			// 	     Port B source output

#define TF_1ms		0	// 1 m second timer flag = 0 bit
#define TF_10ms		1	// 10 m second timer flag = 1 bit
#define TF_100ms	2	// 100 m second timer flag = 2 bit
#define TF_1s		3	// 1 second timer flag = 3 bit
#define TF_1min		4	// 1 minute timer flag = 4 bit
#define TF_1h		5	// 1 hour timer flag = 5 bit
#define TF_1d		6	// 1 day timer flag = 6 bit
#define TF_1m		7	// 1 month timer flag = 7 bit


#define BLINK_T 100 		// LED Blink cycle 5sec
#define BLINK_T2 100		// LCD Blink cycle

#define SW_ALL_IN     0x38	// 0011 l000 

/*
 * user defined functions
 */
//void interrupt_ini(void) NAKED;
//void timer_ini(void) NAKED;
//void port_ini(void) NAKED;
//void parameter_ini(void) NAKED;

//void read_byte_eeprom(byte *eeprom_addr, byte *ret_data) NAKED;

/*
 * interrupt handlers
 */
extern void RESET(void) NAKED;
void int_INT0(void) NAKED;
void int_PCINT1(void) NAKED;
void int_TIM0_OVF(void) SIGNAL_INT;
void int_EE_RDY(void) NAKED;
void int_ANA_COMP(void) NAKED;
void int_TIM0_COMPA(void) NAKED;
void int_TIM0_COMPB(void) NAKED;
void int_WDT(void) NAKED;
void int_ADC(void) NAKED;

/*
 * sram static values
 */
static word sys_clk;

static word blink_cyc;
static byte blink_cyc2;
static word blink_t;		/* blink count */

static byte output_data;	/* output data for pio */
//static byte sw_input;		/* switch input */
//static byte sw_input_pre;		/* pre switch input */

/* .eeprom section data */
byte mess_dec[] EEPROM = "0123456789";

/* main routine for avr */
void app_main(void){
	/* disable interrupt */
	cli();

	/* initialize register, io port */
	//port_ini();
	io_register(DDRB) = PB_OM;
	io_register(PORTB) = PB_PULLUP;
	/* clock prescaler initialize */
	io_register(CLKPR) = CLK_PE;
	io_register(CLKPR) = CLK_PR;

	//parameter_ini();
	blink_t = BLINK_T;
	blink_cyc = sys_clk + BLINK_T;
	blink_cyc2 = (byte) sys_clk + BLINK_T2;
	
	
	//interrupt_ini(); io_register(GIMSK) = 0x00; io_register(MCUCR) = 0x00; 
	//timer_ini();
	io_register(TCCR0A) = NULL;
	io_register(TCCR0B) = (1<<CS02); /* set prescaler 1/256 */
	io_register(TCNT0) = T0_OVF; /* set Overflow count */
	io_register(TIMSK0) = (1<<TOIE0);

	/* test function */
	output_data = 0xff;

	byte m;
	for(m = 0; m < 6;m++){
		wait_5m();
		wait_5m();
		wait_5m();
		wait_5m();
		wait_5m();
		output_data = ~output_data;
		io_register(PORTB) = output_data;
	}

	output_data = 0xff;


	/* enable interrupt */
	sei();

	/* main loop */
	while(1)
	{
		if( (byte) sys_clk == blink_cyc2){
			blink_cyc2 = (byte) sys_clk + BLINK_T2;
			//output_data = ~output_data;
		}
		/* port output */
		if( sys_clk == blink_cyc){
			blink_cyc = sys_clk + blink_t;
			output_data = ~output_data;
		}
		io_register(PORTB) = output_data & PB_OM;
	}

	/* end of main routine */
}

/* follows are Sub routine */


/* interrupt handlers */
void int_INT0(void){
	asm("rjmp RESET");
}
void int_PCINT1(void){
	asm("rjmp RESET");
}
void int_TIM0_OVF(void){
	io_register(TCNT0) = T0_OVF; /* set Overflow count */
	sys_clk++;
}
void int_EE_RDY(void){
	asm("rjmp RESET");
}
void int_ANA_COMP(void){
	asm("rjmp RESET");
}

void int_TIM0_COMPA(void){
	asm("rjmp RESET");
}
void int_TIM0_COMPB(void){
	asm("rjmp RESET");
}
void int_WDT(void){
	asm("rjmp RESET");
}
void int_ADC(void){
	asm("rjmp RESET");
}
