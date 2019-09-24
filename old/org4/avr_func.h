/*
 * avr_func.h
 * header file for avr_func.c
 *
 * 2007.12.30
 * coded by H.Takenobu
 *
 */
#ifndef _AVR_FUNC_H_
#define _AVR_FUNC_H_

// 2008.02.04 commented out by tak
//extern void b8tohex(byte *ch);

// 2008.02.04 added by tak
extern void wait(void) NAKED;
#endif
