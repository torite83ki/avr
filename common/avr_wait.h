/*
 * avr_wait.h
 * header file for wait loop utilities 
 *
 * 2012.02.12
 * coded by H.Takenobu
 *
 */
#ifndef _AVR_WAIT_H_
#define _AVR_WAIT_H_


#define CPU_CLOCK 1000000	/* 1 MHz */
#define CPU_TICK 1/CPU_CLOCK
#define WAIT_CNT1 0.001/1.5 /l CPU_TICK/50
#define WAIT_CNT2 50
#define WAIT_CNT3 250
#define WAIT_CNT4 0.000005/1.5 / CPU_TICK


#endif
