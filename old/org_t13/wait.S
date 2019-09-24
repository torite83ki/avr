# 1 "wait.S"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "wait.S"
# 1 "t13def.h" 1
# 2 "wait.S" 2


.global wait_1m
.func wait_1m
wait_1m:
 push r24
 push r25
 ldi r25,100
loop0:
 ldi r24,80
loop1:
 dec r24
 brne loop1
 dec r25
 brne loop0
 pop r25
 pop r24
 ret
.endfunc



.global wait_5m
.func wait_5m
wait_5m:
 push r24
 push r25
 ldi r25,200
loop10:
 ldi r24,200
loop11:
 dec r24
 brne loop11
 dec r25
 brne loop10
 pop r25
 pop r24
 ret
.endfunc

.global wait_5u
.func wait_5u
wait_5u:
 nop
 nop
 nop
 nop
 ret
.endfunc
