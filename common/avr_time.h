/*
 * avr_time.h
 * header file for timing utilities 
 * This file contains some utilities for avr devices.
 *
 * 2012.01.29
 * coded by H.Takenobu
 *
 */
#ifndef _AVR_TIME_H_
#define _AVR_TIME_H_

#include "avr.h"
#include "avr_typedef.h"

#define CPU_CLOCK 1000000	// 1 MHz
#define CPU_TICK 1/CPU_CLOCK
#define WAIT_CNT1	(0.001/(1.5 * CPU_TICK)/50)
#define WAIT_CNT2	50
#define WAIT_CNT3	250
#define WAIT_CNT4	(0.000005/(1.5 * CPU_TICK))
extern void wait(void) NAKED;
void wait_1m(void) NAKED;		// busy loop
void wait_5m(void) NAKED;		// busy loop
void wait_5u(void) NAKED;		// busy loop


extern delay_cycles(uint8_t);		// busy loop uS


#endif
