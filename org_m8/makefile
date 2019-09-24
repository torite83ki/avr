AVRMAIN = avr_main
MMCU = mega8
MMCU_TARGET = at$(MMCU)
MMCU_AVRDUDE = m8

AVRLS = gcc_elf_$(MMCU).ls
AVRCRT = crt_$(MMCU)
header_path = /Users/tak11tak/prog/avr/src/ORGS/common
lib_path = $(header_path)/avr4
mmcu_header = $(header_path)/avr/$(MMCU)def.h

CC = avr-gcc
OPTION =  -O -Wall -I./ -I- -I$(header_path)
OPTION += -nostdinc -nostdlib -fno-builtin
OPTION += -L$(lib_path) -lmisc
OBJCOPY	= avr-objcopy
OBJDUMP = avr-objdump
LD = avr-ld
NM = avr-nm

#object = crt_avr.o   $(AVRMAIN).o 
object = crt_avr.o lcd_lib.o $(AVRMAIN).o 

$(AVRMAIN).hex 	: $(AVRMAIN).elf $(AVRMAIN).eep $(AVRMAIN).map $(AVRMAIN).llp
	$(OBJCOPY) -j .text -j .data -O ihex $(AVRMAIN).elf $(AVRMAIN).hex

$(AVRMAIN).llp	: $(AVRMAIN).elf
	$(OBJDUMP) -D $(AVRMAIN).elf > $(AVRMAIN).llp

$(AVRMAIN).map	: $(AVRMAIN).elf
	$(NM) -ln $(AVRMAIN).elf > $(AVRMAIN).map 

$(AVRMAIN).elf	: $(object) 
	$(LD) -o $(AVRMAIN).elf -T $(AVRLS) $(object) -L $(lib_path) -lmisc

$(AVRMAIN).o	: $(AVRMAIN).c 
	$(CC) $(OPTION) -nostartfiles -c $(AVRMAIN).c -o $(AVRMAIN).o -mmcu=$(MMCU_TARGET) 

crt_avr.o 	: $(AVRCRT).S 
	$(CC) $(OPTION) -o crt_avr.o -c $(AVRCRT).S -mmcu=$(MMCU_TARGET) 

lcd_lib.o	: lcd_lib.c
	$(CC) $(OPTION) -c lcd_lib.c -mmcu=$(MMCU_TARGET)

$(AVRMAIN).eep	: $(AVRMAIN).elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $(AVRMAIN).elf $(AVRMAIN).eep

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
