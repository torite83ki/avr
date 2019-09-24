AVRMAIN = avr_main
MMCU = mega88
MMCU_TARGET = atmega88
MMCU_AVRDUDE = m88

AVRLS = gcc_elf_$(MMCU).ls
AVRCRT = crt_$(MMCU)
header_path = /Users/tak11tak/prog/avr/src/ORGS/common
headers = $(header_path)/avr.h
mmcu_header = $(header_path)/avr/$(MMCU)def.h
source_path = ..

CC = avr-gcc
OPTION = -O -Wall -dM -I./ -I- -I$(header_path)
OPTION += -nostdinc -nostdlib -fno-builtin
OPTION +=  -Wall
OBJCOPY	= avr-objcopy
OBJDUMP = avr-objdump
LD = avr-ld
NM = avr-nm

object = wait.o delay.o putc.o read_byte_eeprom.o write_byte_eeprom.o

all	: $(object)

wait.o	: $(source_path)/wait.S 
	$(CC) $(OPTION) -c $(source_path)/wait.S -mmcu=$(MMCU_TARGET) 

delay.o : $(source_path)/delay.S 
	$(CC) $(OPTION) -c $(source_path)/delay.S -mmcu=$(MMCU_TARGET) 

putc.o	: $(source_path)/putc.S 
	$(CC) $(OPTION) -c $(source_path)/putc.S -mmcu=$(MMCU_TARGET)

read_byte_eeprom.o	: $(source_path)/read_byte_eeprom.S 
	$(CC) $(OPTION) -c $(source_path)/read_byte_eeprom.S -mmcu=$(MMCU_TARGET) 

write_byte_eeprom.o	: $(source_path)/write_byte_eeprom.S 
	$(CC) $(OPTION) -c $(source_path)/write_byte_eeprom.S -mmcu=$(MMCU_TARGET) 


USI_TWI_Master.o	: $(source_path)/USI_TWI_Master.c USI_TWI_Master.h 
	$(CC) $(OPTION) -nostartfiles -c $(source_path)/USI_TWI_Master.c -o USI_TWI_Master.o -mmcu=$(MMCU_TARGET) 

USI_TWI_Slave.o	: $(source_path)/USI_TWI_Slave.c USI_TWI_Slave.h 
	$(CC) $(OPTION) -nostartfiles -c $(source_path)/USI_TWI_Slave.c -o USI_TWI_Slave.o -mmcu=$(MMCU_TARGET) 

clean	:
	rm -f *.o
	rm -f *.hex
	rm -f *.elf
	rm -f *.eep
	rm -f *.map
	rm -f *.out
	rm -f *.llp

disa	:
	$(OBJDUMP) -D $(AVRMAIN).elf > $(AVRMAIN).llp

e	: 
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -e	

w	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U flash:w:$(AVRMAIN).hex eeprom:w:$(AVRMAIN).eep
wf	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U flash:w:$(AVRMAIN).hex

we	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U eeprom:w:$(AVRMAIN).eep

sig	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -v -n speed=1 

rflash	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U flash:r:"read_flash.hex":h

reep	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U eeprom:r:"read_eeprom.hex":h

rfuse	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U efuse:r:"read_efuse.hex":h -U hfuse:r:"read_hfuse.hex":h  -U lfuse:r:"read_lfuse.hex":h


wfuse	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U efuse:w:0xff:m -U hfuse:w:0xdf:m -U lfuse:w:0x64:m

term	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -t
