/*
 *
 *  lib_lcd.c
 *  avr lcd control program
 *  
 *  coded by H.Takenobu
 *  2008.3.10 rev.0
 *  2008.3.24 rev.1
 *   This library compile without Optimizational option.
 *   ex) gcc -c lib_lcd.o lib_lcd.c
 */

#include "io.h"
#include "avr.h"
#include "lcd_lib.h"
#include "avr_typedef.h"
#include "avr_time.h"

static uint8_t lcd_led;		/* lcd_led output data */

/* follows are Sub routine */

void lcd_check_busy(void){
	volatile uint8_t ddr_buf,busy_flg;
	ddr_buf = LCD_DDR;

	while(1){
		LCD_PORT = (1 << LCD_RW);
		LCD_PORT |= (1 << LCD_E);
		LCD_PORT &= ~(1 << LCD_E);
		/* set data input */
		LCD_DDR = (1 << LCD_LED) | (1 << LCD_RS) | \
				       (1 << LCD_RW) | (1 << LCD_E);
		busy_flg = LCD_PIN;
		if((busy_flg &= (1 << LCD_BF)) != LCD_BUSY)
			break;
		LCD_DDR = ddr_buf;
	}
	/* set output */
	LCD_DDR = ddr_buf;
}

void lcd_putc(uint8_t addr, uint8_t data){
	lcd_addr_write(addr);
	lcd_data_write(data);
}

void lcd_clr(void){
	lcd_write(LCD_CLEAR0);
	lcd_write(LCD_CLEAR1);
	lcd_check_busy();
}

/* put string to the DD ram address */
void lcd_puts(uint8_t addr, uint8_t* str){
	uint8_t buf;
	while((buf = *(str++)) != NULL){
		if(addr == LCD_COL_LEN)
			addr = LCD_2ND_LINE_ADDR;
		if(addr >= (LCD_COL_LEN + LCD_2ND_LINE_ADDR))
			addr = LCD_1ST_LINE_ADDR;
		lcd_addr_write(addr++);
		lcd_data_write(buf);
	}
}

void lcd_addr_write(uint8_t addr){
	addr |= (1 << LCD_DB7);
	lcd_write(addr & LCD_MSB_MASK);
	lcd_write(addr << LCD_4SHIFT);
}

void lcd_data_write(uint8_t data){
	lcd_write((data & LCD_MSB_MASK) | (1 <<LCD_RS));
	lcd_write((data << LCD_4SHIFT) | (1 << LCD_RS));
}	

void lcd_write(uint8_t data){
	data |= lcd_led;
	LCD_PORT = data;
	LCD_PORT |= (1 << LCD_E);
	LCD_PORT &= ~(1 << LCD_E);
	lcd_check_busy();	
}


void lcd_ini(void){
	// initialize 1 15mSec
	wait_5m();
	wait_5m();
	wait_5m();
	lcd_write(LCD_INI);
	
	// initialize 2 4.1mSec
	wait_5m();
	lcd_write(LCD_INI);
	
	// initialize 3 100uSec
	wait_1m();
	lcd_write(LCD_INI);

	// initialize function
	lcd_write(LCD_FUNC_SET0);
	lcd_write(LCD_FUNC_SET0);
	lcd_write(LCD_FUNC_SET1);
	
	lcd_write(LCD_TURN_OFF0);
	lcd_write(LCD_TURN_OFF1);
	
	lcd_write(LCD_CLEAR0);
	lcd_write(LCD_CLEAR1);
	wait_5m();
	lcd_write(LCD_TURN_ON0);
	lcd_write(LCD_TURN_ON1);
	lcd_write(LCD_ENTRY0);
	lcd_write(LCD_ENTRY1);
	ret();
}




