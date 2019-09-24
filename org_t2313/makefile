AVRMAIN = avr_main
MMCU = tiny2313
MMCU_TARGET = attiny2313
MMCU_AVRDUDE = t2313

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

#object = $(AVRCRT).o main.o $(AVRMAIN).o wait.o 
#object = $(AVRCRT).o main.o $(AVRMAIN).o 
object = $(AVRCRT).o wait.o delay.o putc.o read_byte_eeprom.o r_eep.o w_eep.o $(AVRMAIN).o

$(AVRMAIN).hex 	: $(AVRMAIN).elf $(AVRMAIN).eep $(AVRMAIN).map $(AVRMAIN).llp
	$(OBJCOPY) -j .text -j .data -O ihex $(AVRMAIN).elf $(AVRMAIN).hex

$(AVRMAIN).llp	: $(AVRMAIN).elf
	$(OBJDUMP) -D $(AVRMAIN).elf > $(AVRMAIN).llp

$(AVRMAIN).map	: $(AVRMAIN).elf
	$(NM) -ln $(AVRMAIN).elf > $(AVRMAIN).map 

$(AVRMAIN).elf	: $(object)
	$(LD) -o $(AVRMAIN).elf  -T $(AVRLS) $(object)

$(AVRMAIN).o	: $(AVRMAIN).c $(mmcu_header) $(headers)
	$(CC) $(OPTION) -nostartfiles -c $(AVRMAIN).c -o $(AVRMAIN).o -mmcu=$(MMCU_TARGET) 

#main.o : main.S $(mmcu_header) $(headers)
#	$(CC) $(OPTION) -c main.S -mmcu=$(MMCU_TARGET) 

$(AVRCRT).o	: $(AVRCRT).S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c $(AVRCRT).S -mmcu=$(MMCU_TARGET) 

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
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -n speed=1 -v
rp	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U flash:r:read_flash.hex
re	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -U eeprom:r:read_eeprom.eep
term	:
	avrdude -c avrispmkII -P usb:200027253 -p $(MMCU_AVRDUDE) -t
