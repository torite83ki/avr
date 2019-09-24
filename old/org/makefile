object = avr_main.c

avr_main.hex	: avr_main.elf
	objcopy-avr -O ihex avr_main.elf avr_main.hex
avr_main.o	: $(object) 2313def.h avr.h
	gcc-avr -Wall -c $(object) -o avr_main.o -mmcu=at90s2313 -minit-stack=0xdf

crt.o	: crt.S 2313def.h avr.h
	gcc-avr -Wall -c crt.S -mmcu=at90s2313 -minit-stack=0xdf

avr_main.elf	: avr_main.o crt.o
	ld-avr -o avr_main.elf  -T gcc_elf.ls crt.o avr_main.o

gen	: avr_main.hex
	sudo /home/tak5tak/prog/avr/awr/awr -d -f avr_main.hex

erase	: 
	sudo /home/tak5tak/prog/avr/awr/awr -e

write	:
	sudo /home/tak5tak/prog/avr/awr/awr -w -f out.gen

write_e	:
	sudo /home/tak5tak/prog/avr/awr/awr -t -f out.eep

sig	:
	sudo /home/tak5tak/prog/avr/awr/awr -s

