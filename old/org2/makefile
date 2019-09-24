main = avr_main.c
eeprom = avr_eep.c
mmcu_header = 2313def.h
headers = avr.h avr_main.h
mmcu = at90s2313
stack = 0xdf
object = crt.o avr_main.o putc.o
object_eep = avr_eep.o

avr_main.hex	: avr_main.elf
	objcopy-avr -O ihex avr_main.elf avr_main.hex

avr_main.elf	: $(object)
	ld-avr -o avr_main.elf  -T gcc_elf.ls $(object)

avr_main.o	: $(main) $(mmcu_header) $(headers)
	gcc-avr -Wall -c $(main) -o avr_main.o -mmcu=$(mmcu) -minit-stack=$(stack)

crt.o	: crt.S $(mmcu_header) $(headers)
	gcc-avr -Wall -c crt.S -mmcu=$(mmcu) -minit-stack=$(stack)

avr_func.o	: avr_func.c $(mmcu_header) $(headers)
	gcc-avr -Wall -c avr_func.c -mmcu=$(mmcu) -minit-stack=$(stack)

putc.o	: putc.S $(mmcu_header) $(headers)
	gcc-avr -Wall -c putc.S -mmcu=$(mmcu) -minit-stack=$(stack)

puts_avr.o	: puts_avr.c $(headers)
	gcc-avr -Wall -c puts_avr.c -mmcu=$(mmcu) -minit-stack=$(stack)

avr_eep.hex	: avr_eep.elf
	objcopy-avr -O ihex avr_eep.elf avr_eep.hex

avr_eep.elf	: $(object_eep) 
	ld-avr -o avr_eep.elf -T gcc_elf.ls $(object_eep)

avr_eep.o	: $(eeprom) $(mmcu_header) $(headers)
	gcc-avr -Wall -c $(eeprom) -mmcu=$(mmcu) -minit-stack=$(stack)

clean	:
	rm -f *.o
	rm -f *.hex
	rm -f *.elf
	rm -f *.eep

e	: 
	sudo /home/tak5tak/prog/avr/ewr/avrsp -pl1 -e

w	:
	sudo /home/tak5tak/prog/avr/ewr/avrsp -pl1 avr_main.hex

we	:
	sudo /home/tak5tak/prog/avr/ewr/avrsp -pl1 avr_eep.eep

sig	:
	sudo /home/tak5tak/prog/avr/ewr/avrsp -pl1 -r

