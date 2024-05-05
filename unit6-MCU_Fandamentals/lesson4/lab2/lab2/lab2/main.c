/*
 * lab2.c
 *
 * Created: 5/5/2024 11:28:41 AM
 * Author : tasneem
 */ 

#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>


ISR(INT0_vect)
{
	PORTD |=(1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	PORTD |=(1<<7);
	_delay_ms(1000);
}




int main(void)
{
	//enable INT0 any logic change (rising/falling) edge,1->rising edge
	MCUCR |=((1<<0)|(1<<2)|(1<<3));
	MCUCR &= ~(1<<1);
	//enable INT2 falling edge
	MCUCSR &= ~(1<<6);
	//enable EXTI0,1,2
	GICR |=((1<<5)|(1<<6)|(1<<7));
	//enable global INTR0,1,2
	sei();
	DDRD |=((1<<5)|(1<<6)|(1<<7));
	
	
	
	while (1)
	{
		PORTD &= ~((1<<5)|(1<<6)|(1<<7));
		_delay_ms(1000);
	}
}

