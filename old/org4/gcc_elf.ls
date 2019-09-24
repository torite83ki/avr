/**********************************************************
/
/	2006.11.04 ihex file format option has a bug?
/	OUTPUT_FORMAT("ihex")
/
***********************************************************/

OUTPUT_FORMAT("elf32-avr")
OUTPUT_ARCH(AVR5)

MEMORY
{
  text   (rx)   : ORIGIN = 0,    LENGTH = 2K
  data   (rw!x) : ORIGIN = (0x800000 + 0x60), LENGTH = 512
  eeprom (rw!x) : ORIGIN = 0x810000, LENGTH = 512
 }



SECTIONS
{
	.	=	0x0000;
	.text	:	{*(.text)}	> text 
	.data	:	{*(.data)}	> data
	.eeprom :	{*(.eeprom)}	> eeprom
	/*	PROVIDE	(__stack = 0xdf) ;*/
}
