/*
 * keybad.h
 *
 * Created: 5/21/2024 4:47:08 AM
 *  Author: tasneem
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_PORT PORTD
#define DATADir_KEYPAD_PORT DDRD
#define KEYPAD_PIN PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3

#define C0 0
#define C1 1
#define C2 2
#define C3 3

void KEYBAD_INIT();
char KEYPAD_GETCHAR();

#endif /* KEYBAD_H_ */