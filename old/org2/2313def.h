/****************************************************************************
 * This file converted from Atmel application file.
 * 2006.02.04 
 * 
 * It use this file for gcc(target : avr)
 *
 ****************************************************************************/



//***************************************************************************
//* A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
//* 
//* Number		:AVR000
//* File Name		:"2313def.inc"
//* Title		:Register/Bit Definitions for the AT90S2313
//* Date	 		:99.01.28
//* Version		:1.30
//* Support telephone	:+47 72 88 43 88 (ATMEL Norway)
//* Support fax		:+47 72 88 43 99 (ATMEL Norway)
//* Support E-Mail	:avr@atmel.com
//* Target MCU		:AT90S2313
//*
//* DESCRIPTION
//* When including this file in the assembly program file, all I/O register
//* names and I/O register bit names appearing in the data book can be used.
//* 
//* The Register names are represented by their hexadecimal addresses.
//* 
//* The Register Bit names are represented by their bit number (0-7).
//* 
//* Please observe the difference in using the bit names with instructions
//* such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
//* (skip if bit in register set/cleared). The following example illustrates
//* this:
//* 
//* in	r16,PORTB		//read PORTB latch
//* sbr	r16,(1<<PB6)+(1<<PB5)	;set PB6 and PB5 (use masks, not bit#)
//* out  PORTB,r16		;output to PORTB
//*
//* in	r16,TIFR		;read the Timer Interrupt Flag Register
//* sbrc	r16,TOV0		;test the overflow flag (use bit#)
//* rjmp	TOV0_is_set		;jump if set
//* ...				;otherwise do something else
//***************************************************************************

//***** Specify Device
//.device AT90S2313


//***** I/O Register Definitions
#define	SREG	 0x3f		// Status Register
#define	SPL	 0x3d		// Stack Pointer Low
#define	GIMSK	 0x3b		// General Interrupt MaSK Register
#define	GIFR	 0x3a		// General Interrupt Flag Register
#define	TIMSK	 0x39		// Timer/Counter Interrupt MaSK Register
#define	TIFR	 0x38		// Timer/Counter Interrupt Flag Register
#define	MCUCR	 0x35		// MCU general Control Register
#define	TCCR0	 0x33		// Timer/Counter 0 Control Register
#define	TCNT0	 0x32		// Timer/Counter 0 (8bit)
#define	TCCR1A	 0x2f		// Timer/Counter 1 Control Register A
#define	TCCR1B	 0x2e		// Timer/Counter 1 Control Register B
#define	TCNT1H	 0x2d		// Timer/Counter 1 High Byte
#define	TCNT1L	 0x2c		// Timer/Counter 1 Low Byte
#define	OCR1AH	 0x2b		// Output Compare Register 1 High Byte
#define	OCR1AL	 0x2a		// Output Compare Register 1 Low Byte
#define	ICR1H	 0x25		// T/C 1 Input Capture Register High Byte
#define	ICR1L	 0x24		// T/C 1 Input Capture Register Low Byte
#define	WDTCR	 0x21		// Watchdog Timer Control Register
#define	EEAR	 0x1e		// EEPROM Address Register
#define	EEDR	 0x1d		// EEPROM Data Register
#define	EECR	 0x1c		// EEPROM Control Register
#define	PORTB	 0x18		// Data Register, Port B
#define	DDRB	 0x17		// Data Direction Register, Port B
#define	PINB	 0x16		// Input Pins, Port B
#define	PORTD	 0x12		// Data Register, Port D
#define	DDRD	 0x11		// Data Direction Register, Port D
#define	PIND	 0x10		// Input Pins, Port D
#define	UDR	 0x0c		// UART I/O Data Register
#define	USR	 0x0b		// UART Status Register
#define	UCR	 0x0a		// UART Control Register
#define	UBRR	 0x09		// UART Baud Rate Register
#define	ACSR	 0x08		// Analog comparator Control and Status Register


//***** Bit Definitions
// SREG
// Status Register
#define	SP7	 7		// r/w I: Global Interrupt Enable
#define	SP6	 6		// r/w T: Bit Copy Storage
#define	SP5	 5		// r/w H: Half-carry Flag
#define	SP4	 4		// r/w S: Sign Bit, S = N and V
#define	SP3	 3		// r/w V: Two's Complement Overflow Flag
#define	SP2	 2		// r/w N: Negative Flag
#define	SP1	 1		// r/w Z: Zero Flag
#define	SP0	 0		// r/w C: Carry Flag

// GIMSK
// General Interrupt Mask Register 
#define	INT1	 7		// r/w INT1: External Interrupt Request 1 Enable
#define	INT0	 6		// r/w INI0: External Interrupt Request 0 Enable

// GIFR
// General Interrupt FLAG Register
#define	INTF1	 7		// r/w INTF1: External Interrupt Flag1
#define	INTF0	 6		// r/w INTF0: External Interrupt Flag0

// TIMSK
// Timer/Counter Interrupt Mask Register
#define	TOIE1	 7		// r/w TOIE1: Timer/Counter1 Overflow Interrupt Enable
#define	OCIE1A	 6		// r/w OCIE1A: Timer/Counter1 Output Compare Match Interrupt Enable
#define	TICIE	 3		// r/w TICIE1: Timer/Counter1 Input Capture Interrupt Enable
#define	TOIE0	 1		// r/w TOIE0: Timer/Counter0 Overflow Interrupt Enable

#define BIT_TOIE1	0X80	// TOIE1:	ON
#define BIT_OCIE1A	0X40	// OCIE1A:	ON
#define BIT_TICIE	0X04	// TICIE1:	ON
#define BIT_TOIE0	0X02	// TOIE0:	ON

// TIFR
// Timer/Counter Interrupt FLAG Register
#define	TOV1	 7		// r/w TOV1: Timer/Counter1 Overflow Flag
#define	OCF1A	 6		// r/w OCF1A: Output Compare Flag 1A
#define	ICF1	 3		// r/w ICF1: Input Capture Flag 1
#define	TOV0	 1		// r/w TOV0: Timer/Counter0 Overflow Flag

#define	BIT_TOV1	0x80		// r/w TOV1: Timer/Counter1 Overflow Flag
#define	BIT_OCF1A	0x40		// r/w OCF1A: Output Compare Flag 1A
#define	BIT_ICF1	0x04		// r/w ICF1: Input Capture Flag 1
#define	BIT_TOV0	0x02		// r/w TOV0: Timer/Counter0 Overflow Flag


// MCUCR
// MCU Control Register
#define	SE	 5		// r/w SE: Sleep Enable
#define	SM	 4		// r/w SM: Sleep Mode
#define	ISC11	 3		// r/w ISC11: Interrupt Sense Control 1 bit1
#define	ISC10	 2		// r/w ISC10: Interrupt Sense Control 1 bit0
#define	ISC01	 1		// r/w ISC01: Interrupt Sense Control 0 bit1
#define	ISC00	 0		// r/w ISC00: Interrupt Sense Control 0 bit0

// TCCR0
// Timer/Counter0 Control Register
#define	CS02	 2		// r/w CS02: Clock Select0 bit2
#define	CS01	 1		// r/w CS01: Clock Select0 bit1
#define	CS00	 0		// r/w CS00: Clock Select0 bit0

// added 2006.11.05
// Timer/Counter0 Control Register bit pattern
#define BIT_CS02	0X04	// CS02: ON
#define BIT_CS01	0X02	// CS01: ON
#define BIT_CS00	0X01	// CS00: ON


// TCCR1A
// Timer/Counter1 Control Register
#define	COM1A1	 7		// r/w COM1A1: Compare Output Mode1 bit1
#define	COM1A0	 6		// r/w COM1A0: Compare Output Mode1 bit0
#define	PWM11	 1		// r/w PWM11: Pulse Width Modulator Select bit1
#define	PWM10	 0		// r/w PWM10: Pulse Width Modulator Select bit0

// added 2006.12.11
// Timer/Counte1 Control Register A bit pattern
#define BIT_COM1A1	0X80	// COM1A1: ON
#define BIT_COM1A0	0X40	// COM1A0: ON
#define BIT_PWM11	0x02	// PWM11:  ON
#define BIT_PWM10	0x01	// PWM10:  ON


// TCCR1B
// Timer/Counter1 Control Register B
#define	ICNC1	 7		// r/w ICNC1: Input Capture1 Noise Canceler(4 CKs)
#define	ICES1	 6		// r/w ICES1: Input Capture1 Edge Select
#define	CTC1	 3		// r/w CTC1: Clear Timer/Counter1 on Compare Match
#define	CS12	 2		// r/w CS12: Clock Select1 bit2
#define	CS11	 1		// r/w CS11: Clock Select1 bit1
#define	CS10	 0		// r/w CS10: Clock Select1 bit0

// added 2006.12.11
// Timer/Counter1 Control Register B bit pattern
#define BIT_ICNC1	0x80	// INCNC1:	ON
#define BIT_ICES1	0x40	// ICES1:	ON
#define BIT_CTC1	0x08	// CTC1:	ON
#define BIT_CS12	0x04	// CS12:	ON
#define BIT_CS11	0x02	// CS11:	ON
#define BIT_CS10	0x01	// CS10:	ON


// WDTCR
// Watchdog Timer Control Register
#define	WDTOE	 4		// r/w WDTOE: Watchdog Turn-off Enable
#define	WDE	 3		// r/w WDE: Watchdog Enable
#define	WDP2	 2		// r/w WDP2: Watchdog Timer Prescaler2
#define	WDP1	 1		// r/w WDP1: Watchdog Timer Prescaler1
#define	WDP0	 0		// r/w WDP0: Watchdog Timer Prescaler0

// EECR
// EEPROM Control Register
#define	EEMWE	 2		// r/w EEMWE: EEPROM Master Write Enable
#define	EEWE	 1		// r/w EEWE: EEPROM Write Enable
#define	EERE	 0		// r/w EERE: EEPROM Read Enable

// PORTB
#define	PB7	 7		// SCK: Serial clock input
#define	PB6	 6		// MISO: Data output line for memory uploading
#define	PB5	 5		// MOSI: Data input line for memory downloading
#define	PB4	 4		
#define	PB3	 3		// OC1: Timer/Counter1 Output Compare Match output
#define	PB2	 2		
#define	PB1	 1		// AIN1: Analog Comparator negative input
#define	PB0	 0		// AIN0: Analog Comparator negative input

// DDRB
// Data Direction Register
#define	DDB7	 7
#define	DDB6	 6
#define	DDB5	 5
#define	DDB4	 4
#define	DDB3	 3
#define	DDB2	 2
#define	DDB1	 1
#define	DDB0	 0

// PINB
// PortB Input Pins Address
#define	PINB7	 7
#define	PINB6	 6
#define	PINB5	 5
#define	PINB4	 4
#define	PINB3	 3
#define	PINB2	 2
#define	PINB1	 1
#define	PINB0	 0

// PORTD
#define	PD6	 6		// ICP: Timer/Counter1 Interrupt Capture pin
#define	PD5	 5		// T1: Timer/Counter1 External Input
#define	PD4	 4		// T0: Timer/Counter0 External Input
#define	PD3	 3		// INT1: External Interrupt 1 Input
#define	PD2	 2		// INT0: External Interrupt 0 Input
#define	PD1	 1		// TXD: Transmit Data output for the UART
#define	PD0	 0		// RXD: Receive Data input for the UART

// DDRD
// PORT D Data Direction Register
#define	DDD6	 6
#define	DDD5	 5
#define	DDD4	 4
#define	DDD3	 3
#define	DDD2	 2
#define	DDD1	 1
#define	DDD0	 0

// PIND
#define	PIND6	 6
#define	PIND5	 5
#define	PIND3	 3
#define	PIND2	 2
#define	PIND1	 1
#define	PIND0	 0

// USR
// UART Status Register
#define	RXC	 7		// r RXC: UART Receive Complete
#define	TXC	 6		// r/w TXC: UART Transmit Complete
#define	UDRE	 5		// r UDRE: UART Data Register Empty
#define	FE	 4		// r FE: Framing Error
#define	OR	 3		// r OR: OverRun

// UCR
// UART Control Register
#define	RXCIE	 7		// r/w RXCIE: RX Complete Interrupt Enable
#define	TXCIE	 6		// r/w TX Complete Interrupt Enable
#define	UDRIE	 5		// r/w UDRIE: UART Data Gegister Empty Interrupt Enable
#define	RXEN	 4		// r/w RXEN: Receiver Enable
#define	TXEN	 3		// r/w Txen: Transmiter Enable
#define	CHR9	 2		// r/w CHR9: 9 Bit Characters
#define	RXB8	 1		// r   RXB8: Receive Data Bit 8
#define	TXB8	 0		// w   TXB8: Transmit Data Bit 8

// ACSR
// Analog Comparator Control and Status Register
#define	ACD	 7		// r/w ACD: Analog Comparator Disable
#define	ACO	 5		// r   ACO: Analog Comparator Output
#define	ACI	 4		// r/w ACI: Analog Comparator Interrupt Flag
#define	ACIE	 3		// r/w ACIE: Analog Compparator Interrupt Enable
#define	ACIC	 2		// r/w ACIC: Analog Comparator Input Capture Enable
#define	ACIS1	 1		// r/w ACIS1: Analog Comparator Interrupt Mode Select
#define	ACIS0	 0		// r/w ACIS0: Analog Comparator Interrupt Mode Select

// SRAM InDirect Access Register
#define	XL	 r26
#define	XH	 r27
#define	YL	 r28
#define	YH	 r29
#define	ZL	 r30
#define	ZH	 r31

#define RAMTOP  0x60    // Ram Top
#define	RAMEND	0xDF	// Last On-Chip SRAM Location
#define	XRAMEND		0xDF	// Extended Ram End
#define	E2END		0x7F	// EEPROM END
#define	FLASHEND	0x3FF	// FLASH ROM END


#define	INT0addr	0x001	// External Interrupt0 Vector Address
#define	INT1addr	0x002	// External Interrupt1 Vector Address
#define	ICP1addr	0x003	// Input Capture1 Interrupt Vector Address
#define	OC1addr		0x004	// Output Compare1 Interrupt Vector Address
#define	OVF1addr	0x005	// Overflow1 Interrupt Vector Address
#define	OVF0addr	0x006	// Overflow0 Interrupt Vector Address
#define	URXCaddr	0x007	// UART Receive Complete Interrupt Vector Address
#define	UDREaddr	0x008	// UART Data Register Empty Interrupt Vector Address
#define	UTXCaddr	0x009	// UART Transmit Complete Interrupt Vector Address
#define	ACIaddr		0x00a	// Analog Comparator Interrupt Vector Address

//***** Constant definitions
//#define	RxCIE	 0x80
//#define	TxCIE	 0x40
//#define	UdrIE	 0x20
//#define	RxEN	 0x10
//#define	TxEN	 0x08
//#define	Chr9	 0x04
//#define	Rxb8	 0x02
//#define	Txb8	 0x01


// Register Definition
#define	temp		r16	//temporary
#define	temp1		r17	//temporary
#define	temp2		r18	//temporary
#define temp3           r19     //temporary

// Constant Definition
#define POUT7           0x80    // 8bit ON
#define POUT6           0x40    // 7bit ON
#define POUT5           0x20    // 6bit ON
#define POUT4           0x10    // 5bit ON
#define POUT3           0x08    // 4bit ON
#define POUT2           0x04    // 3bit ON
#define POUT1           0x02    // 2bit ON
#define POUT0           0x01    // 1bit ON

#define BIT8_ON		0x80    // 8bit ON
#define BIT7_ON		0x40    // 7bit ON
#define BIT6_ON		0x20    // 6bit ON
#define BIT5_ON		0x10    // 5bit ON
#define BIT4_ON		0x08    // 4bit ON
#define BIT3_ON		0x04    // 3bit ON
#define BIT2_ON         0x02    // 1bit ON
#define BIT1_ON		0x01    // 1bit ON


// defines at avr.h 
// changed at 06.08.06
// typedef unsigned char byte;     // 8bit data size
// typedef unsigned int  word;     // 16bit data size

// follows are apllication area


