/*
 * main.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */
#include "lifo.h"

//create static buffer
#define buffer_length 5
element_type buffer1[buffer_length];

int main()
{
	element_type i,temp=0;
	LIFO_Buf_t uart_lifo ,I2C_lifo;
	//static allocation
	LIFO_init(&uart_lifo,buffer1,buffer_length);
	//dynamic allocation
	element_type* buffer2 = (element_type*)malloc(buffer_length * sizeof(element_type));
	LIFO_init(&I2C_lifo,buffer2,buffer_length);

	printf("<<<< add items >>>>\n");
	for(i=0;i<7;i++)
	{
		if( LIFO_add_item(&uart_lifo,i) == LIFO_no_error )
			printf("\n add item is done and is = %d \n",i);
		else
			printf("\n add item is failed \n");
	}
    printf("\n<<<< get items >>>>\n");
	for(i=0;i<7;i++)
		{
			if( LIFO_get_item(&uart_lifo,&temp) == LIFO_no_error )
				printf("\n get item is done and is = %d \n ",temp);
			else
				printf("\n get item is failed \n");
		}
return 0;
}

