AVRMAIN = avr_main
AVRLS = gcc_elf_m88.ls
mainS = main.S
CRT = crt_m88
mmcu_header = m88def.h
headers = avr.h
mmcu = atmega164p
DEV = m164p
#stack = 0x9f ;no use

CC = avr-gcc
OPTION =  -O1 -Wall
//OPTION = -Os -Wall
OPTION += -nostdinc -nostdlib -fno-builtin
//OPTION += -mno-interrupts
//OPTION += -mcall-prologues
OBJCOPY	= avr-objcopy
OBJDUMP = avr-objdump
LD = avr-ld
NM = avr-nm

#object = $(CRT).o main.o $(AVRMAIN).o wait.o 
#object = $(CRT).o main.o $(AVRMAIN).o 
object = $(CRT).o  delay.o main.o $(AVRMAIN).o wait.o

$(AVRMAIN).hex 	: $(AVRMAIN).elf $(AVRMAIN).eep $(AVRMAIN).map $(AVRMAIN).llp
	$(OBJCOPY) -j .text -j .data -O ihex $(AVRMAIN).elf $(AVRMAIN).hex

$(AVRMAIN).llp	: $(AVRMAIN).elf
	$(OBJDUMP) -D $(AVRMAIN).elf > $(AVRMAIN).llp

$(AVRMAIN).map	: $(AVRMAIN).elf
	$(NM) -ln $(AVRMAIN).elf > $(AVRMAIN).map 

$(AVRMAIN).elf	: $(object)
	$(LD) -o $(AVRMAIN).elf  -T $(AVRLS) $(object)

$(AVRMAIN).o	: $(AVRMAIN).c $(mmcu_header) $(headers)
	$(CC) $(OPTION) -nostartfiles -c $(AVRMAIN).c -o $(AVRMAIN).o -mmcu=$(mmcu) 

main.o : main.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c main.S -mmcu=$(mmcu) 

$(CRT).o	: $(CRT).S $(mmcu_header) $(headers)
	$(CC) -Wall -c $(CRT).S -mmcu=$(mmcu) 

wait.o	: wait.S $(mmcu_header) $(headers)
	$(CC) -Wall -c wait.S -mmcu=$(mmcu) 

delay.o : delay.S $(mmcu_header) $(headers)
	$(CC) $(OPTION) -c delay.S -mmcu=$(mmcu) 


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
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -e	

w	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U flash:w:$(AVRMAIN).hex eeprom:w:$(AVRMAIN).eep
wf	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U flash:w:$(AVRMAIN).hex

we	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U eeprom:w:$(AVRMAIN).eep

sig	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV)  -v -n speed=1 
rp	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U flash:r:read_flash.hex
re	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U eeprom:r:read_eeprom.eep
rfuse	:
	avrdude -c avrispmkII -P usb:200027253 -p $(DEV) -U hfuse:r:m 
