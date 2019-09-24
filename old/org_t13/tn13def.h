/***************************************************************************
 * This file converted from Atmel application file.
 * 2010.11.03 
 *
 ***************************************************************************/





//**************************************************************************
// A P P L I C A T I O N   N O T E   F O R   T H E   A V R   F A M I L Y
// 
// Number               :AVR000
// File Name            :"tn12.inc"
// Title                :Register/Bit Definitions for the ATtiny12
// Date                 :99.01.28
// Version              :1.30
// Support telephone    :+47 72 88 43 88 (ATMEL Norway)
// Support fax          :+47 72 88 43 99 (ATMEL Norway)
// Support E-mail       :avr@atmel.com
// Target MCU           :XX ATtiny12 XX
//                      :>> ATtiny13
//
// DESCRIPTION
// When including this file in the assembly program file, all I/O register      
// names and I/O register bit names appearing in the data book can be used.
// In addition, the two registers forming the data pointer Z have been 
// assigned names ZL - ZH. 
//
// The Register names are represented by their hexadecimal address.
// 
// The Register Bit names are represented by their bit number (0-7).
// 
// Please observe the difference in using the bit names with instructions
// such as "sbr"/"cbr" (set/clear bit in register) and "sbrs"/"sbrc" 
// (skip if bit in register set/cleared). The following example illustrates
// this:
// 
// in   r16,PORTB               ;read PORTB latch
// sbr  r16,(1<<PB6)+(1<<PB5)   ;set PB6 and PB5 (use masks, not bit#)
// out  PORTB,r16               ;output to PORTB
//
// in   r16,TIFR                ;read the Timer Interrupt Flag Register
// sbrc r16,TOV0                ;test the overflow flag (use bit#)
// rjmp TOV0_is_set             ;jump if set
// ...                          ;otherwise do something else
//**************************************************************************

#ifndef _TN13DEF_H_
#define _TN13DEF_H_

//**** Specify Device
//.device ATtiny13

//**** I/O Register Definitions
#define    SREG    0x3f		//Status Register
#define    SPL     0x3d		//
#define    GIMSK   0x3b		//General Interrupt Mask Register
#define    GIFR    0x3a		//General Interrpt Flag Register
#define    TIMSK0  0x39		//Timer/Counter Interrupt Mask Register
#define    TIFR0   0x38		//Timer/Counter Interrupt Flag Register
#define    SPMCSR  0X37		//
#define    OCR0A   0X36		//
#define    MCUCR   0x35		//MCU General Control Register
#define    MCUSR   0x34		//
#define    TCCR0B  0x33
#define    TCNT0   0x32
#define    OSCCAL  0x31
#define    TCCR0A  0x2f
#define    DWDR    0x2e
#define    OCR0B   0x29
#define    GTCCR   0x28
#define    CLKPR   0x26
#define    WDTCR   0x21
#define    EEARL   0x1e
#define    EEDR    0x1d
#define    EECR    0x1c
#define    PORTB   0x18
#define    DDRB    0x17
#define    PINB    0x16
#define    PCMSK   0x15
#define    DIDR0   0x14
#define    ACSR    0x08
#define    ADMUX   0x07
#define    ADCSRA  0x06
#define    ADCH    0x05
#define    ADCL    0x04
#define    ADCSRB  0x03


//**** Bit Definitions

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


#define    INT0    6
#define    PCIE    5

#define    INTF0   6
#define    PCIF    5

#define    OCIE0B  3
#define    OCIE0A  2
#define    TOIE0   1

#define    OCF0B   3
#define    OCF0A   2
#define    TOV0    1

#define    CTPB    4
#define    RFLB    3
#define    PGWRT   2
#define    PGERS   1
#define    SELFPR  0

#define    PUD     6
#define    SE      5
#define    SM1     4
#define    SM0     3
#define    ISC01   1
#define    ISC00   0

#define    WDRF    3
#define    BORF    2
#define    EXTRF   1
#define    PORF    0

#define    FOC0A   7
#define    FOC0B   6
#define    WGM02   3
#define    CS02    2
#define    CS01    1
#define    CS00    0

#define    COM0A1  7
#define    COM0A0  6
#define    COM0B1  5
#define    COM0B0  4
#define    WGM01   1
#define    WGM00   0

#define    TSM     7
#define    PSR10   0

#define    CLKPCE   7
#define    CLKPS3   3
#define    CLKPS2   2
#define    CLKPS1   1
#define    CLKPS0   0

#define    WDTIF    7
#define    WDTIE    6
#define    WDP3     5
#define    WDCE     4
#define    WDE      3
#define    WDP2     2
#define    WDP1     1
#define    WDP0     0

#define    EEPM1    5
#define    EEPM0    4
#define    EERIE    3
#define    EEMPE    2
#define    EEPE     1
#define    EERE     0

#define    PORTB5   5
#define    PORTB4   4
#define    PORTB3   3
#define    PORTB2   2
#define    PORTB1   1
#define    PORTB0   0

#define    DDB5     5
#define    DDB4     4
#define    DDB3     3
#define    DDB2     2
#define    DDB1     1
#define    DDB0     0

#define    PINB5    5
#define    PINB4    4
#define    PINB3    3
#define    PINB2    2
#define    PINB1    1
#define    PINB0    0

#define    PCINT5   5
#define    PCINT4   4
#define    PCINT3   3
#define    PCINT2   2
#define    PCINT1   1
#define    PCINT0   0

#define    ADC0D   5
#define    ADC2D   4
#define    ADC3D   3
#define    ADC1D   2
#define    AIN1D   1
#define    AIN0D   0

#define    ACD     7
#define    ACBG    6
#define    ACO     5
#define    ACI     4
#define    ACIE    3
#define    ACIS1   1
#define    ACIS0   0

#define    REFS0   6
#define    ADLAR   5
#define    MUX1    1
#define    MUX0    0

#define    ADEN    7
#define    ADSC    6
#define    ADATE   5
#define    ADIF    4
#define    ADIE    3
#define    ADPS2   2
#define    ADPS1   1
#define    ADPS0   0

#define    ACME    6
#define    ADTS2   2
#define    ADTS1   1
#define    ADTS0   0


//.def    ZL      r30
//.def    ZH      r31

// SRAM InDirect Access Register
#define XL	r26
#define XH	r27
#define YL	r28
#define YH	r29
#define ZL	r30
#define ZH	r31

#define    RESETaddr	0x000	//
#define    INT0addr		0x001	//External Interrupt0 Vector Address
#define    PCINTaddr	0x002	//Pin change Interrupt Vector Address
#define    TIM0_OVFaddr	0x003	//Overflow0 Interrupt Vector Address
#define    EE_RDYaddr	0x004	//EEPROM Ready Vector Address
#define    ANA_COMPaddr	0x005	//Analog Comparator Interrupt Vector Address
#define    TIM0_COMPA	0x006	//Timer/Counter Compare Match A
#define    TIM0_COMPB	0x007	//Timer/Counter Compare Match B
#define    WDT			0x008	//Watchdog Time-out
#define    ADC			0x009	//ADC Conversion Complete



// 2010.11.03 added by Tak

// Register Definition
#define	temp		r16	//temporary
#define	temp1		r17	//temporary
#define	temp2		r18	//temporary
#define temp3           r19     //temporary

#define	FLASHEND 0x1FF
#define	E2END	0x3F
#define EEAR 0x1e
#define RAMTOP 0x60		//Ram Top
#define RAMEND 0x9F		//Ram End



#endif
