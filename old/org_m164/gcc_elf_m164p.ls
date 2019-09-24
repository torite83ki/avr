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
  text   (rx)   : ORIGIN = 0,    LENGTH = 8K
  data   (rw!x) : ORIGIN = (0x800000 + 0x100), LENGTH = 1k
  eeprom (rw!x) : ORIGIN = 0x810000, LENGTH = 512 
 }



SECTIONS
{
	.	=	0x0000;
	.text	:	{*(.text)}	> text 
	.bss	:	{*(.bss)}	> data
	.eeprom :	{*(.eeprom)}	> eeprom
}
