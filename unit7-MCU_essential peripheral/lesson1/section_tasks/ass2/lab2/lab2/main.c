/*
 * lab2.c
 *
 * Created: 5/14/2024 4:58:39 AM
 * Author : tasneem
 */ 
#include "Map_Memory.h"
#define  F_CPU 8000000UL
#include "util/delay.h"

#define set_bit(reg,bit) reg |=(1<<bit)
#define clear_bit(reg,bit) reg &= ~(1<<bit)
#define read_bit(reg,bit) ((reg>>bit)&1)
int main(void)
{
	DDRA  =0b11111111;
	DDRC  =0b00000000;
	PORTC =0b11111111;
	int bit = 0; 
	while (1)
	{
		if(read_bit(PINC,0)==0)
		{
			// Turn on the LED
			set_bit(PORTA, bit);
			// Wait until the button is released
			while (read_bit(PINC, 0) == 0);
			// Increment the LED index and reset to 0 if it exceeds 7
			bit = (bit + 1) % 8;
		}
	}
}


