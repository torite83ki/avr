/*******************************************************
 * io.h
 * header file for avr
 * This file includes i/o definitions 
 * This file is for C source file.
 *
 * 2012.01.08
 * coded by H.Takenobu
 *
 * rev.0 release
 *
 *******************************************************/


#ifndef _IO_H_
#define _IO_H_

#if defined (__AVR_ATtiny2313__)
#include "avr/tiny2313def.h"
#
#elif defined (__AVR_ATtiny13__)
#include "avr/tiny13def.h"
#
#elif defined (__AVR_ATtiny26__)
#include "avr/tiny26def.h"
#
#elif defined (__AVR_ATmega8__)
#include "avr/mega8def.h"
#
#elif defined (__AVR_ATmega88__)
#include "avr/mega88def.h"
#
#endif

#endif
