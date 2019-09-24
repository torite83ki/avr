
/***************************************************************************
 * This file converted from Atmel application file.
 * 2011.04.17 
 *
 * Target MCU = ATmega88
 *
 ***************************************************************************/



//***************************************************************************
//* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
//* 
//* Number				:AVR000
//* File Name			:"m8def.inc"
//* Title				:Register/Bit Definitions for the ATmega8
//* Date                 :07.09.2001
//* Version              :1.00
//* Support telephone	:+47 72 88 43 88 (ATMEL Norway)
//* Support fax			:+47 72 88 43 99 (ATMEL Norway)
//* Support E-mail		:avr@atmel.no
//* Target MCU			:ATmega8
//*
//* DESCRIPTION
//* When including this file in the assembly program file, all I/O register	
//* names and I/O register bit names appearing in the data book can be used.
//* In addition, the six registers forming the three data pointers X, Y and
//* Z have been assigned names XL - ZH. Highest RAM address for Internal 
//* SRAM is also defined 
//*
//* The Register names are represented by their hexadecimal address.
//* 
//* The Register Bit names are represented by their bit number (0-7).
//* 
//* Please observe the difference in using the bit names with instructions
//* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
//* (skip if bit in register set/cleared). The following example illustrates
//* this:
//* 
//* in	r16,PORTB				//read PORTB latch
//* sbr	r16,(1<<PB6)+(1<<PB5)	//set PB6 and PB5 (use masks, not bit#)
//* out  PORTB,r16				//output to PORTB
//*
//* in	r16,TIFR				//read the Timer Interrupt Flag Register
//* sbrc	r16,TOV0				//test the overflow flag (use bit#)
//* rjmp	TOV0_is_set				//jump if set
//* ...							//otherwise do something else
//***************************************************************************

//***** Specify Device
//.device ATmega88

//***** I/O Register Definitions
#define Reg_Offset	0x20

#define	UDR0	0xc6 - Reg_Offset
#define	UBRR0H	0xc5 - Reg_Offset
#define UBRR0L	0xc4 - Reg_Offset
#define UCSR0C	0xc2 - Reg_Offset
#define UCSR0B	0xc1 - Reg_Offset
#define UCSR0A	0xc0 - Reg_Offset
#define TWAMR	0xbd - Reg_Offset
#define TWCR	0xbc - Reg_Offset
#define TWDR	0xbb - Reg_Offset
#define	TWAR	0xba - Reg_Offset
#define TWSR	0xb9 - Reg_Offset
#define TWBR	0xb8 - Reg_Offset
#define ASSR	0xb6 - Reg_Offset
#define OCR2B	0xb4 - Reg_Offset
#define OCR2A	0xb3 - Reg_Offset
#define TCNT2	0xb2 - Reg_Offset
#define TCCR2B	0xb1 - Reg_Offset
#define	TCCR2A	0xb0 - Reg_Offset
#define	OCR1BH	0x8b - Reg_Offset
#define	OCR1BL	0x8a - Reg_Offset
#define	OCR1AH	0x89 - Reg_Offset
#define	OCR1AL	0x88 - Reg_Offset
#define	ICR1H	0x87 - Reg_Offset
#define	ICR1L	0x86 - Reg_Offset
#define TCNT1H	0x85 - Reg_Offset
#define TCNT1L	0x84 - Reg_Offset
#define	TCCR1C	0x82 - Reg_Offset
#define TCCR1B	0x81 - Reg_Offset
#define	TCCR1A	0x80 - Reg_Offset
#define	DIDR1	0x7f - Reg_Offset
#define	DIDR0	0x7e - Reg_Offset
#define	ADMUX	0x7c - Reg_Offset
#define	ADCSRB	0x7b - Reg_Offset
#define	ADCSRA	0x7a - Reg_Offset
#define	ADCH	0x79 - Reg_Offset
#define	ADCL	0x78 - Reg_Offset
#define	TIMSK2	0x70 - Reg_Offset
#define	TIMSK1	0x6f - Reg_Offset
#define TIMSK0	0x6e - Reg_Offset
#define	PCMSK2	0x6d - Reg_Offset
#define	PCMSK1	0x6c - Reg_Offset
#define	PCMSK0	0x6b - Reg_Offset
#define	EICRA	0x69 - Reg_Offset
#define	PCICR	0x68 - Reg_Offset
#define	OSCCAL	0x66 - Reg_Offset
#define	PRR	0x64 - Reg_Offset
#define	CLKPR	0x61 - Reg_Offset
#define	WDTCSR	0x60 - Reg_Offset

#define	SREG	0x3f
#define	SPH	0x3e
#define	SPL	0x3d
#define SPMCSR	0x37
#define MCUCR	0x35
#define MCUSR   0x34		// For compatibility, 
#define MCUCSR  0x34		// keep both names until further
#define	SMCR	0x33
#define ACSR	0x30
#define	SPDR	0x2e
#define	SPSR	0x2d
#define	SPCR	0x2c
#define	GPIOR2	0x2b
#define	GPIOR1	0x2a
#define	OCR0B	0x28
#define	OCR0A	0x27
#define	TCNT0	0x26
#define	TCCR0B	0x25
#define	TCCR0A	0x24
#define	GTCCR	0x23
#define	EEARH	0x22
#define	EEARL	0x21
#define	EEAR	0x21
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
#define PORTB	0x05
#define	DDRB	0x04
#define	PINB	0x03


//***** Bit Definitions
//GICR  (former GIMSK)
#define	INT1	7
#define	INT0	6
#define	IVSEL	1		// interrupt vector select
#define	IVCE	0		// interrupt vector change enable

//GIFR
#define	INTF1	7
#define	INTF0	6

//TIMSK
#define TOIE0   0
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

//TIFR
#define TOV0    0
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

//SPMCR
#define	SPMIE	7
#define	RWWSB	6
#define	RWWSRE	4
#define	BLBSET	3
#define	PGWRT	2
#define	PGERS	1
#define	SPMEN	0

//MCUCR
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

//MCUCSR
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

//TCCR0
#define	CS02	2
#define	CS01	1
#define	CS00	0

//TCCR1A
#define	COM1A1	7
#define	COM1A0	6
#define	COM1B1	5
#define	COM1B0	4
#define	FOC1A	3
#define	FOC1B	2
#define	PWM11	1	// OBSOLETE! Use WGM11
#define	PWM10	0	// OBSOLETE! Use WGM10
#define	WGM11	1
#define	WGM10	0

//TCCR1B
#define	ICNC1	7
#define	ICES1	6
#define	CTC11	4	// OBSOLETE! Use WGM13
#define	CTC10	3	// OBSOLETE! Use WGM12
#define	WGM13	4
#define	WGM12	3	
#define	CTC1	3		// Obsolete - Included for backward compatibility
#define	CS12	2
#define	CS11	1
#define	CS10	0

//TCCR2
#define	FOC2	7
#define PWM2    6	// OBSOLETE! Use WGM20
#define	WGM20	6	
#define COM21   5
#define COM20   4
#define CTC2    3	// OBSOLETE! Use WGM21
#define	WGM21	3	
#define CS22    2
#define CS21    1
#define CS20    0

//SFIOR
#define ADHSM   4
#define ACME    3
#define PUD     2
#define	PSR2	1
#define	PSR10	0

//WDTCR
#define	WDCE	4
#define	WDTOE	4
#define	WDE	3
#define	WDP2	2
#define	WDP1	1
#define	WDP0	0

//EECR
#define EEPM1	5
#define EEPM0	4
#define EERIE   3
#define	EEMPE	2
#define	EEPE	1
#define	EERE	0

//PORTB
#define	PB7	7
#define	PB6	6
#define	PB5	5
#define	PB4	4
#define	PB3	3
#define	PB2	2
#define	PB1	1
#define	PB0	0

//DDRB
#define	DDB7	7
#define	DDB6	6
#define	DDB5	5
#define	DDB4	4
#define	DDB3	3
#define	DDB2	2
#define	DDB1	1
#define	DDB0	0

//PINB
#define	PINB7	7
#define	PINB6	6
#define	PINB5	5
#define	PINB4	4
#define	PINB3	3
#define	PINB2	2
#define	PINB1	1
#define	PINB0	0

//PORTC
#define	PC6	6
#define	PC5	5
#define	PC4	4
#define	PC3	3
#define	PC2	2
#define	PC1	1
#define	PC0	0

//DDRC
#define	DDC6	6
#define	DDC5	5
#define	DDC4	4
#define	DDC3	3
#define	DDC2	2
#define	DDC1	1
#define	DDC0	0

//PINC
#define	PINC6	6
#define	PINC5	5
#define	PINC4	4
#define	PINC3	3
#define	PINC2	2
#define	PINC1	1
#define	PINC0	0

//PORTD
#define	PD7	7
#define	PD6	6
#define	PD5	5
#define	PD4	4
#define	PD3	3
#define	PD2	2
#define	PD1	1
#define	PD0	0

//DDRD
#define	DDD7	7
#define	DDD6	6
#define	DDD5	5
#define	DDD4	4
#define	DDD3	3
#define	DDD2	2
#define	DDD1	1
#define	DDD0	0

//PIND
#define	PIND7	7
#define	PIND6	6
#define	PIND5	5
#define	PIND4	4
#define	PIND3	3
#define	PIND2	2
#define	PIND1	1
#define	PIND0	0

//UCSRA
#define	RXC	7
#define	TXC	6
#define	UDRE	5
#define	FE	4
#define	OR	3		// old name kept for compatibilty
#define	DOR	3
#define	UPE	2
#define	PE	2
#define	U2X	1
#define	MPCM	0

//UCSRB
#define	RXCIE	7
#define	TXCIE	6
#define	UDRIE	5
#define	RXEN	4
#define	TXEN	3
#define	CHR9	2		// old name kept for compatibilty
#define	UCSZ2	2
#define	RXB8	1
#define	TXB8	0

//UCSRC
#define	URSEL	7
#define	UMSEL	6
#define	UPM1	5
#define	UPM0	4
#define	USBS	3
#define	UCSZ1	2
#define	UCSZ0	1
#define	UCPOL	0
		
//SPCR
#define	SPIE	7
#define	SPE	6
#define	DORD	5
#define	MSTR	4
#define	CPOL	3
#define	CPHA	2
#define	SPR1	1
#define	SPR0	0

//SPSR
#define	SPIF	7
#define	WCOL	6
#define	SPI2X	0

//ACSR
#define	ACD	7
#define ACBG    6
#define	ACO	5
#define	ACI	4
#define	ACIE	3
#define	ACIC	2
#define	ACIS1	1
#define	ACIS0	0

//ADMUX
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

//ADCSR
#define ADEN    7
#define ADSC    6
#define ADFR    5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

// TWCR
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

// TWAR
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

// TWSR
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
#define	TWPS1	1
#define	TWPS0	0

//ASSR
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0
#define	XL	r26 
#define	XH	r27 
#define	YL	r28 
#define	YH	r29 
#define	ZL	r30
#define	ZH	r31

#define RAMTOP	0x0100	// Internal SRAM starts here
#define	RAMEND  0X4FF
#define	FLASHEND 0X1FFF
#define E2END		0x01ff	// 512

		      //  byte groups
		      /* /\/--\/--\/--\ */ 
#define	SMALLBOOTSTART	0b00111110000000  //($0F80) smallest boot block is 256
#define	SECONDBOOTSTART	0b00111100000000  //($0F00) 2'nd boot block size is 512
#define	THIRDBOOTSTART	0b00111000000000  //($0E00) third boot block size is 1K
#define	LARGEBOOTSTART	0b00110000000000  //($0C00) largest boot block is 2K
#define	BOOTSTART	THIRDBOOTSTART  //OBSOLETE!!! kept for compatibility
#define	PAGESIZE	32     //number of WORDS in a page

#define	INT0addr	0x001	// External Interrupt0 Vector Address
#define	INT1addr	0x002	// External Interrupt1 Vector Address
#define	OC2addr 	0x003	// Output Compare2 Interrupt Vector Address
#define	OVF2addr	0x004	// Overflow2 Interrupt Vector Address
#define	ICP1addr	0x005	// Input Capture1 Interrupt Vector Address
#define	OC1Aaddr	0x006	// Output Compare1A Interrupt Vector Address
#define	OC1Baddr	0x007	// Output Compare1B Interrupt Vector Address
#define	OVF1addr	0x008	// Overflow1 Interrupt Vector Address
#define	OVF0addr	0x009	// Overflow0 Interrupt Vector Address
#define	SPIaddr 	0x00a	// SPI Interrupt Vector Address
#define	URXCaddr	0x00b	// USART Receive Complete Interrupt Vector Address
#define	UDREaddr	0x00c	// USART Data Register Empty Interrupt Vector Address
#define	UTXCaddr	0x00d	// USART Transmit Complete Interrupt Vector Address
#define	ADCCaddr	0x00e	// ADC Interrupt Vector Address
#define	ERDYaddr	0x00f	// EEPROM Interrupt Vector Address
#define	ACIaddr 	0x010	// Analog Comparator Interrupt Vector Address
#define TWIaddr 	0x011   // Irq. vector address for Two-Wire Interface
#define	SPMaddr 	0x012	// SPM complete Interrupt Vector Address
#define	SPMRaddr 	0x012	// SPM complete Interrupt Vector Address



// Temporary Register Definition
#define	temp	r16
#define	temp1	r17
#define	temp2	r18
#define temp3	r19

#define E2END		0x01ff	// 512
#define RAMTOP		0x0100	// Internal SRAM starts here
