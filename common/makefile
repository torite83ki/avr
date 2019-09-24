AVRMAIN = avr_main
MMCU = mega88
MMCU_TARGET = atmega88
MMCU_AVRDUDE = m88

mmcu_header = $(MMCU)def.h
AVRLS = gcc_elf_$(MMCU).ls
AVRCRT = crt_$(MMCU)
headers = avr.h

CC = avr-gcc
OPTION =  -O -Wall
OPTION += -nostdinc -nostdlib -fno-builtin
OPTION +=  -Wall
OBJCOPY	= avr-objcopy
OBJDUMP = avr-objdump
LD = avr-ld
NM = avr-nm

object = wait.o delay.o putc.o read_byte_eeprom.o r_eep.o w_eep.o USI_TWI_Master.o USI_TWI_Slave.o
#object = crt_avr.o wait.o delay.o putc.o read_byte_eeprom.o r_eep.o w_eep.o USI_TWI_Master.o $(AVRMAIN).o

wait.o	: wait.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c wait.S -mmcu=$(MMCU_TARGET) 

delay.o : delay.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c delay.S -mmcu=$(MMCU_TARGET) 

putc.o	: putc.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c putc.S -mmcu=$(MMCU_TARGET)

read_byte_eeprom.o	: read_byte_eeprom.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c read_byte_eeprom.S -mmcu=$(MMCU_TARGET) 

r_eep.o	: r_eep.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c r_eep.S -mmcu=$(MMCU_TARGET) 
w_eep.o	: w_eep.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c w_eep.S -mmcu=$(MMCU_TARGET) 

USI_TWI_Master.o	: USI_TWI_Master.c USI_TWI_Master.h $(mmcu_header) $(headers)
	$(CC) $(OPTION) -nostartfiles -c USI_TWI_Master.c -o USI_TWI_Master.o -mmcu=$(MMCU_TARGET) 

USI_TWI_Slave.o	: USI_TWI_Slave.c USI_TWI_Slave.h $(mmcu_header) $(headers)
	$(CC) $(OPTION) -nostartfiles -c USI_TWI_Slave.c -o USI_TWI_Slave.o -mmcu=$(MMCU_TARGET) 

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
