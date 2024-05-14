/*
 * lab1.c
 *
 * Created: 5/14/2024 4:52:28 AM
 * Author : tasneem
 */ 

#include "Map_Memory.h"
#define  F_CPU 8000000UL
#include "util/delay.h"

#define set_bit(reg,bit) reg |=(1<<bit)
#define clear_bit(reg,bit) reg &= ~(1<<bit)
#define read_bit (reg,bit)  ((reg>>bit)&1)
int main(void)
{
	DDRA  =0b11111111;
	/* Replace with your application code */
	while (1)
	{
		for(int i =0;i<8;i++)
		{
			set_bit(PORTA,i);
			_delay_ms(50);
		}
		for(int j =7;j>=0;j--)
		{
			clear_bit(PORTA,j);
			_delay_ms(50);
		}
	}
}

