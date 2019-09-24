/*
 *
 *  avr_lcd.h
 *  avr lcd control program header file
 *  
 *  coded by H.Takenobu
 *  2008.3.10 rev.0
 */

#ifndef _AVR_LCD_H_
#define _AVR_LCD_H_

#include "avr.h"

/* 
 * user defined constant
 */
#define LCD_PORT PORTB	// LCD asigned port
#define LCD_PIN  PINB	// LCD asigned port pin
#define LCD_DDR  DDRB	// LCD asigned port DDR
#define LCD_LED	0	// LCD back light LED
#define LCD_RS	1	// LCD control bit RS
#define LCD_RW	2	// LCD control bit Read/Write_ 
#define LCD_E	3	// LCD control bit E 
#define LCD_DB4	4	// LCD DB4
#define LCD_DB5	5	// LCD DB5
#define LCD_DB6	6	// LCD DB6
#define LCD_DB7	7	// LCD DB7

#define LCD_INI	      0x30	//0011 *00* lcd initialize
#define LCD_FUNC_SET0 0x20	//0010 *00* 4 bit address mode
#define LCD_FUNC_SET1 0x80	//0000 *00* 5x7 dot 2 line
#define LCD_CLEAR0    0x00	//0000 *00* clear the display 
#define LCD_CLEAR1    0x10	//0001 *00*
#define LCD_TURN_OFF0 0x00	//0000 *00* turn off the display and cursor
#define LCD_TURN_OFF1 0x00	//1000 *00* 
#define LCD_TURN_ON0  0x00	//0000 *00* turn on the display 
//#define LCD_TURN_ON1  0xe0	//1110 *00* turn on the display and cursor
#define LCD_TURN_ON1  0xc0	//1100 *00* 
#define LCD_ENTRY0    0x00	//0000 *00* increment mode
#define LCD_ENTRY1    0x60      //0110 *00*
#define LCD_BUSY      0x80	//1000 0000 busy flag
#define LCD_CUR_HOME0 0x00	//0000 *00*
#define LCD_CUR_HOME1 0x02	//0010 *00*

/*
 * user defined functions
 */
void lcd_ini(void) NAKED;
void lcd_write(byte data);
void lcd_data_write(byte data);
void lcd_check_busy(void);
void lcd_addr_write(byte addr);
void lcd_puts(byte addr, byte* str);
void lcd_putc(byte addr, byte data);
void lcd_clr(void);

/*
 * sram static values
 */
static byte lcd_led;		/* lcd_led output data */
#endif
