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
#include "avr_lcd.h"


/* follows are Sub routine */

void lcd_check_busy(void){
	byte lcd_data,ddr_buf,busy_flg;
	lcd_data = (1 << LCD_RW);
	ddr_buf = io_register(LCD_DDR);
	/* set data input */
	io_register(LCD_DDR) = (1 << LCD_LED) | (1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_E);

	while(1){
		io_register(LCD_PORT) = lcd_data;
		io_register(LCD_PORT) = lcd_data | (1 << LCD_E);
		io_register(LCD_PORT) = lcd_data & ~(1 << LCD_E);
		busy_flg = io_register(LCD_PIN);
		io_register(LCD_PORT) = lcd_data;
		io_register(LCD_PORT) = lcd_data | (1 << LCD_E);
		io_register(LCD_PORT) = lcd_data & ~(1 << LCD_E);
		if((busy_flg &= LCD_BUSY) != LCD_BUSY)
			break;
	}
	/* set output */
	io_register(LCD_DDR) = ddr_buf;
}

void lcd_putc(byte addr, byte data){
	lcd_addr_write(addr);
	lcd_data_write(data);
}

void lcd_clr(void){
	lcd_write(LCD_CLEAR0);
	lcd_write(LCD_CLEAR1);
	lcd_check_busy();
}

/* put string to the DD ram address */
void lcd_puts(byte addr, byte* str){
	byte buf;
	while((buf = *(str++)) != NULL){
		if(addr == 0x08)
			addr = 0x40;
		if(addr >= 0x48)
			addr = 0x00;
		lcd_addr_write(addr++);
		lcd_data_write(buf);
	}
}

void lcd_addr_write(byte addr){
	addr |= (1 << LCD_DB7);
	lcd_write(addr & 0xf0);
	lcd_write(addr << 4);
}

void lcd_data_write(byte data){
	lcd_write((data & 0xf0) | (1 <<LCD_RS));
	lcd_write((data << 4) | (1 << LCD_RS));
}	

void lcd_write(byte data){
	data |= lcd_led;
	io_register(LCD_PORT) = data;
	io_register(LCD_PORT) = data | (1 << LCD_E);
	io_register(LCD_PORT) = data & ~(1 << LCD_E);
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
	wait_5m();
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




