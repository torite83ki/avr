AVRMAIN = avr_main
AVRLS = gcc_elf_t13.ls
mainS = main.S
mmcu_header = tn13def.h
headers = avr.h
mmcu = attiny13
#stack = 0x9f ;no use

CC = avr-gcc
OBJCOPY	= avr-objcopy
OBJDUMP = avr-objdump
LD = avr-ld
NM = avr-nm

object = crt_t13.o main.o $(AVRMAIN).o wait.o 

$(AVRMAIN).hex	: $(AVRMAIN).elf $(AVRMAIN).eep
	$(OBJCOPY) -j .text -j .data -O ihex $(AVRMAIN).elf $(AVRMAIN).hex

$(AVRMAIN).map	: $(AVRMAIN).elf
	$(NM) -ln $(AVRMAIN).elf > $(AVRMAIN).map 

$(AVRMAIN).elf	: $(object)
	$(LD) -o $(AVRMAIN).elf  -T $(AVRLS) $(object)

$(AVRMAIN).o	: $(AVRMAIN).c $(mmcu_header) $(headers)
	$(CC) -Wall -nostartfiles -c $(AVRMAIN).c -o $(AVRMAIN).o -mmcu=$(mmcu) 

main.o : main.S $(mmcu_header) $(headers)
	$(CC) -Wall -c main.S -mmcu=$(mmcu) 

crt_t13.o	: crt_t13.S $(mmcu_header) $(headers)
	$(CC) -Wall -c crt_t13.S -mmcu=$(mmcu) 

wait.o	: wait.S $(mmcu_header) $(headers)
	$(CC) -Wall -c wait.S -mmcu=$(mmcu) 

$(AVRMAIN).eep	: $(AVRMAIN).elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $(AVRMAIN).elf $(AVRMAIN).eep

clean	:
	rm -f *.o
	rm -f *.hex
	rm -f *.elf
	rm -f *.eep
	rm -f *.map
	rm -f *.out

disa	:
	$(OBJDUMP) -D $(AVRMAIN).elf

e	: 
	avrdude -c avrispmkII -P usb:200027253 -p t13 -e	

w	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -U flash:w:$(AVRMAIN).hex eeprom:w:$(AVRMAIN).eep
wf	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -U flash:w:$(AVRMAIN).hex

we	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -U eeprom:w:$(AVRMAIN).eep

sig	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -n speed=1
rp	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -U flash:r:read_flash.hex
re	:
	avrdude -c avrispmkII -P usb:200027253 -p t13 -U eeprom:r:read_eeprom.eep
