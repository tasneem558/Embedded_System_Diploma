/*
 * main.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */

#include "fifo.h"
#define buff_size 5
element_type buff[buff_size];
int main()
{
	FIFO_Buff_t uart_fifo;
	element_type i,temp=0;
	if( FIFO_init(&uart_fifo,buff,buff_size)== FIFO_no_error )
	{
		printf(".... fifo init is done ....\n");
	}
	for(i=0;i<7;i++)
	{
		printf("FIFO ENQUEUE (%x)\n",i);
		if( FIFO_enqeueu(&uart_fifo,i)== FIFO_no_error)
		{
			printf(".... fifo enqueue is done ....\n");
		}
		else
		{
			printf(".... fifo enqueue is failed ....\n");
		}
	}
	FIFO_print(&uart_fifo);
	for(i=0;i<2;i++)
	{
		if( FIFO_deqeueu(&uart_fifo,&temp)== FIFO_no_error)
		{
			printf(".... fifo dequeue is done ....(%x)\n",temp);
		}
	}
	FIFO_print(&uart_fifo);
	return 0;
}
