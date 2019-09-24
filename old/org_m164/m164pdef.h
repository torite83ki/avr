
/***************************************************************************
 * Added and Modified for ATmega164p 
 * Date					: 21.09.2011
 * File Name				: m164pdef.h
 * Version				: 1.00
 * Coded by				: H.Takenobu
 * Target MCU				: ATmega164p
 *
 ***************************************************************************/



/* CAUTION !!!   FOLLOWINGS ARE ORIGINAL COMMENT FOR ASSEMBLER !!!! ********/
/***************************************************************************
 * A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
 *
 * Number				:AVR000
 * File Name				:"m16def.inc"
 * Title				:Register/Bit Definitions for the ATmega16
 * Date                			:07.09.2001
 * Version              		:1.00
 * Support telephone			:+47 72 88 87 20 (ATMEL Norway)
 * Support fax				:+47 72 88 87 18 (ATMEL Norway)
 * Support E-mail			:avr@atmel.no
 * Target MCU				:ATmega16
 *
 * DESCRIPTION
 * When including this file in the assembly program file, all I/O register	
 * names and I/O register bit names appearing in the data book can be used.
 * In addition, the six registers forming the three data pointers X, Y and
 * Z have been assigned names XL - ZH. Highest RAM address for Internal 
 * SRAM is also defined 
 *
 * The Register names are represented by their hexadecimal address.
 * 
 * The Register Bit names are represented by their bit number (0-7).
 * 
 * Please observe the difference in using the bit names with instructions
 * such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
 * (skip if bit in register set/cleared). The following example illustrates
 * this:
 * 
 * in	r16,PORTB				;read PORTB latch
 * sbr	r16,(1<<PB6)+(1<<PB5)			;set PB6 and PB5 (use masks, not bit#)
 * out  PORTB,r16				;output to PORTB
 *
 * in	r16,TIFR				;read the Timer Interrupt Flag Register
 * sbrc	r16,TOV0				;test the overflow flag (use bit#)
 * rjmp	TOV0_is_set				;jump if set
 * ...						;otherwise do something else
 ***************************************************************************/

/***** Specify Device *******/
//.device ATmega16

/****** I/O Register Definitions ******/
#define	SREG	0x3f
#define	SPH	0x3e
#define	SPL	0x3d 
#define	RAMPZ	0x3b
#define	SPMCSR	0x37
#define	MCUCR   0x35
#define	MCUSR   0x34
#define	SMCR	0x33
#define	OCDR	0x31
#define	ACSR	0x30
#define	SPDR	0x2e
#define	SPSR	0x2d
#define	SPCR	0x2c
#define	GPIOR2	0x2b
#define	GPIOR1	0x2a
#define	OCR0B	0x28
#define	OCR0A	0x27
#define	TCNT0	0x26
#define	TCCR0A	0x25
#define	TCNT0B	0x24
#define	GTCCR	0x23
#define	EEARH	0x22
#define	EEARL	0x21
#define	EEDR	0x20
#define	EECR	0x1f
#define	GPIOR0	0x1e
#define	EIMSK	0x1d
#define	EIFR	0x1c
#define	PCIFR	0x1b
#define	TIFR2	0x17
#define	TIFR1	0x16
#define	TIFR0	0x15
#define	PORTD	0x0b
#define	DDRD	0x0a
#define	PIND	0x09
#define	PORTC	0x08
#define	DDRC	0x07
#define	PINC	0x06
#define	PORTB	0x05
#define	DDRB	0x04
#define	PINB	0x03
#define	PORTA	0x02
#define	DDRA	0x01
#define	PINA	0x00

/****** Bit Definitions ******/
/* EIMSK */
#define	INT2	2
#define	INT1	1
#define	INT0	0

/* EICRA */
#define	ISC21	5
#define ISC20	4
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0

/* EIFR */
#define	INTF2	2
#define	INTF1	1
#define	INTF0	0

/* PCICR */
#define	PCIE3	3
#define	PCIE2	2
#define	PCIE1	1
#define	PCIE0	0

/* PCIFR */
#define	PCIF3	3
#define	PCIF2	2
#define	PCIF1	1
#define	PCIF0	0

/* PCMSK3 */
#define	PCINT31	7
#define	PCINT30	6
#define	PCINT29	5
#define	PCINT28	4
#define	PCINT27	3
#define	PCINT26	2
#define	PCINT25	1
#define	PCINT24	0

/* PCMSK2 */
#define	PCINT23	7
#define	PCINT22	6
#define	PCINT21	5
#define	PCINT20	4
#define	PCINT19	3
#define	PCINT18	2
#define	PCINT17	1
#define	PCINT16	0


/* PCMSK1 */
#define	PCINT15	7
#define	PCINT14	6
#define	PCINT13	5
#define	PCINT12	4
#define	PCINT11	3
#define	PCINT10	2
#define	PCINT9	1
#define	PCINT8	0


/* PCMSK0 */
#define	PCINT7	7
#define	PCINT6	6
#define	PCINT5	5
#define	PCINT4	4
#define	PCINT3	3
#define	PCINT2	2
#define	PCINT1	1
#define	PCINT0	0


/* TIMSK0 */
#define	TOIE0   0
#define	OCIE0A  1	 
#define	TOIE0B  2

/* TIMSK1 */
#define	ICIE1	5
#define	OCIE1B	3
#define	OCIE1A	2
#define	TOIE1	1

/* TIMSK2 */
#define	OCIE2B	2
#define	OCIE2A	1
#define	TOIE2	0


/* TIFR0 */
#define	TOV0    0
#define	OCF0A	1
#define	OCF0B	2

/* TIFR1 */
#define	ICF1	5
#define	OCF1B	2
#define	OCR1A	1
#define	TOV1	0

/* TIFR2 */
#define	OCF2B	2
#define	OCF2A	1
#define	TOV2	0


/* MCUCR */
#define JTD	7
#define BODS	6
#define BODSE	5
#define PUD	4
#define	IVSEL	1
#define IVCE	0

/* MCUSR */
#define	JTRF	 4
#define	WDRF     3
#define	BORF     2
#define	EXTRF    1
#define	PORF     0

/* GTCCR */
#define	TSM	7
#define	PSRASY	1
#define	PSRSYNC	0

/* TCCR0A */
#define	COM0A1	7   
#define	COM0A0	6   
#define	COM0B1	5   
#define	COM0B0	4   
#define	WGM01   1
#define	WGM00   0

/* TCCR0B */
#define	FOC0A	7
#define	FOC0B	6
#define	WGM02	3
#define	CS02	2
#define	CS01	1
#define	CS00	0

/* TCCR2A */
#define	COM2A1	7
#define	COM2A0	6
#define	COM2B1	5
#define	COM2B0	4
#define	WGM21	1
#define	WGM20	0

/* TCCR2B */
#define	FOC2A	7
#define	FOC2B	6
#define	WGM22	3
#define	CS22	2
#define	CS21	1
#define	CS20	0

/* ASSR */
#define	EXCLK	6
#define	AS2	5
#define	TCN2UB	4
#define	OCR2AUB	3
#define	OCR2BUB	2
#define	TCR2AUB	1
#define	TCR2BUB	0

/* UCSR


/* WDTCSR */
#define WDIF	7
#define WDIE	6
#define	WDCE	4
#define	WDE	3
#define WDP3	5
#define	WDP2	2
#define	WDP1	1
#define	WDP0	0

/* PORTA */
#define	PA7	7
#define	PA6	6
#define	PA5	5
#define	PA4	4
#define	PA3	3
#define	PA2	2
#define	PA1	1
#define	PA0	0

/* DDRA */
#define	DDA7	7
#define	DDA6	6
#define	DDA5	5
#define	DDA4	4
#define	DDA3	3
#define	DDA2	2
#define	DDA1	1
#define	DDA0	0

/* PINA */
#define	PINA7	7
#define	PINA6	6
#define	PINA5	5
#define	PINA4	4
#define	PINA3	3
#define	PINA2	2
#define	PINA1	1
#define	PINA0	0

/* PORTB */
#define	PB7	7
#define	PB6	6
#define	PB5	5
#define	PB4	4
#define	PB3	3
#define	PB2	2
#define	PB1	1
#define	PB0	0

/* DDRB */
#define	DDB7	7
#define	DDB6	6
#define	DDB5	5
#define	DDB4	4
#define	DDB3	3
#define	DDB2	2
#define	DDB1	1
#define	DDB0	0

/* PINB */
#define	PINB7	7
#define	PINB6	6
#define	PINB5	5
#define	PINB4	4
#define	PINB3	3
#define	PINB2	2
#define	PINB1	1
#define	PINB0	0

/* PORTC */
#define	PC7	7
#define	PC6	6
#define	PC5	5
#define	PC4	4
#define	PC3	3
#define	PC2	2
#define	PC1	1
#define	PC0	0

/* DDRC */
#define	DDC7	7
#define	DDC6	6
#define	DDC5	5
#define	DDC4	4
#define	DDC3	3
#define	DDC2	2
#define	DDC1	1
#define	DDC0	0

/* PINC */
#define	PINC7	7
#define	PINC6	6
#define	PINC5	5
#define	PINC4	4
#define	PINC3	3
#define	PINC2	2
#define	PINC1	1
#define	PINC0	0

/* PORTD */
#define	PD7	7
#define	PD6	6
#define	PD5	5
#define	PD4	4
#define	PD3	3
#define	PD2	2
#define	PD1	1
#define	PD0	0

/* DDRD */
#define	DDD7	7
#define	DDD6	6
#define	DDD5	5
#define	DDD4	4
#define	DDD3	3
#define	DDD2	2
#define	DDD1	1
#define	DDD0	0

/* PIND */
#define	PIND7	7
#define	PIND6	6
#define	PIND5	5
#define	PIND4	4
#define	PIND3	3
#define	PIND2	2
#define	PIND1	1
#define	PIND0	0


/* UCSRA */
#define	RXC	7
#define	TXC	6
#define	UDRE	5
#define	FE	4
#define	DOR	3	/*New name for OR */
#define	UPE	2	 
#define	U2X	1
#define	MPCM	0

/* UCSRB */
#define	RXCIE	7
#define	TXCIE	6
#define	UDRIE	5
#define	RXEN	4
#define	TXEN	3
#define	CHR9	2
#define	UCSZ2	2	/* New name for CHR9 */
#define	RXB8	1
#define	TXB8	0

/*UCSRC */
#define	UMSEL1	7	 
#define	UMSEL0	6	 
#define	UPM1	5	 
#define	UPM0	4	 
#define	USBS	3	 
#define	UCSZ1	2	 
#define	UCSZ0	1	 
#define	UCPOL	0	 


/* ADCSRB */
#define	ACME	6
#define	ADTS2	2
#define	ADTS1	1
#define	ADTS0	0

/* ACSR */
#define	ACD	7
#define	ACBG    6
#define	ACO	5
#define	ACI	4
#define	ACIE	3
#define	ACIC	2
#define	ACIS1	1
#define	ACIS0	0

/* DIDR1 */
#define	AIN1D	1
#define	AIN0D	0


/* ADMUX */
#define	REFS1   7
#define	REFS0   6
#define	ADLAR   5
#define	MUX4    4
#define	MUX3    3
#define	MUX2    2
#define	MUX1    1
#define	MUX0    0

/* ADCSRA */
#define	ADEN    7
#define	ADSC    6
#define	ADATE	5	 
#define	ADIF    4
#define	ADIE    3
#define	ADPS2   2
#define	ADPS1   1
#define	ADPS0   0

#define	XL	r26
#define	XH	r27
#define	YL	r28
#define	YH	r29
#define	ZL	r30
#define	ZH	r31

/* SPMMCSR */
#define	SPMIE	7
#define	RWWSB	6
#define	SIGRD	5
#define	RWWSRE	4
#define	BLBSET	3
#define	PGWRT	2
#define	PGERS	1
#define	SPMEN	0

#define	RAMTOP		0x100
#define	RAMEND		0x4ff	/* (1024 * 8) */
#define	FLASHEND	0x1fff
#define	E2END		0x01ff	/* 512 bytes */

#define	SMALLBOOTSTART	0b1111110000000  /* (0x1F80) smallest boot block is 256B */
#define	SECONDBOOTSTART	0b1111100000000  /* (0x1F00) second boot block size is 512B */
#define	THIRDBOOTSTART	0b1111000000000  /* (0x1E00) third boot block size is 1KB */
#define	LARGEBOOTSTART	0b1110000000000  /* (0x1C00) largest boot block is 2KB
#define	PAGESIZE	64     /* number of WORDS in a page */

#define	RESETaddr		0x000	/* Reset Vector Address */
#define	INT0addr		0x002	/* External Interrupt0 Vector Address */
#define	INT1addr		0x004	/* External Interrupt1 Vector Address */
#define	INT2addr		0x006	/* External Interrupt2 Vector Address */
#define	PCINT0addr		0x008	/* Pin Change Interrupt Request 0 */
#define	PCINT1addr		0x00a	/* Pin Change Interrupt Request 1 */
#define	PCINT2addr		0x00c	/* Pin Change Interrupt Request 2 */
#define	PCINT3addr		0x00e	/* Pin Change Interrupt Request 3 */
#define	WDTaddr			0x010	/* Watchdog Time-out Interrupt */
#define	TIMER2_COMPAaddr	0x012	/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPBaddr	0x014	/* Timer/Counter2 Compare Match B */
#define	Timer2_OVFaddr		0x016	/* Timer/Counter2 Overflow */
#define	Timer1_CAPTaddr		0x018	/* Timer/Counter1 Capture Event */
#define	Timer1_COMPAaddr	0x01a	/* Timer/Counter1 Compare Match A */
#define Timer1_COMPBaddr	0x01c	/* Timer/Counter1 Compare Match B */
#define Timer1_OVFaddr		0x01E	/* Timer/Counter1 Overflow */
#define	TIMER0_COMPAaddr	0x020	/* Timer/Counter0 Compare Match A */
#define	TIMER0_COMPBaddr	0x022	/* Timer/Counter0 Compare Match B */
#define	TIMER0_OVFaddr		0x024	/* Timer/Counter0 Overflow */
#define	SPI_STCaddr		0x026	/* SPI Serial Transfer Complete */
#define	USART0_RXaddr		0x028	/* USART0 Rx Complete */
#define	USART0_UDREaddr		0x02a	/* USART0 Data Register Empty */
#define	USART0_TXaddr		0x02c	/* USART0 Tx Complete */
#define	ANALOG_COMPaddr		0x02e	/* Analog Comparator */
#define	ADCaddr			0x030	/* ADC Conversion Complete */
#define	EE_READYaddr		0x032	/* EEPROM Ready */
#define	TWIaddr			0x034	/* 2-wire Serial Interface */
#define	SPM_READYaddr		0x036	/* Store Program Memory Ready */
#define	USART1_RX		0x038	/* USART1 Rx Complete */
#define	USART1_UDRE		0x03a	/* USART1 Data Register Empty */
#define	USART1_TX		0x03c	/* USART1 Tx Complete */

