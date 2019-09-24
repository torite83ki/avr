/**********************************************************
/
/	2006.11.04 ihex file format option has a bug?
/	OUTPUT_FORMAT("ihex")
/
***********************************************************/

OUTPUT_FORMAT("elf32-avr")
OUTPUT_ARCH(AVR4)

MEMORY
{
	flash(rwx)	: ORIGIN = 0x000000, LENGTH = 7k
	flashdata(rw)	: ORIGIN = 0x001c00, LENGTH = 1k
	ram(rw!x)	: ORIGIN = 0x800100, LENGTH = 1k
	eeprom(rw!x)	: ORIGIN = 0x810000, LENGTH = 512 
 }



SECTIONS
{
	.flash : {
		_resetvec_start = .;
		KEEP(crt_avr.o(.resetvec))
		_eresetvec = .;
		_vectors_start = .;
		KEEP(crt_avr.o(.vectors))
		_evectors = .;
		_text_start = .;
		*(.text)
		_etext = .;
	} > flash

	.data : {
		_data_start = .;
		*(.data)
		_edata = .;
	} > ram AT>flashdata

	.bss : {
		_bss_start = .;
		*(.bss)
		_ebss = .;
	} > ram
	
	.eeprom : {
		_eeprom_start = .;
		*(.eeprom)
		_eeeprom = .;
	} > eeprom
}
