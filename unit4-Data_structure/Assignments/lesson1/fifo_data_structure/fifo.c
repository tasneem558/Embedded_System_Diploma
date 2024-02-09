/*
 * fifo.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */
#include "fifo.h"
FIFO_Buff_status FIFO_init(FIFO_Buff_t* fifo,element_type* buff, uint32 length)
{
	if(buff == NULL)
		return FIFO_null;
	fifo->base = buff;
	fifo->head = buff;
	fifo->tail = buff;
	fifo->length = length;
	fifo->count =0;
	return FIFO_no_error;
}
FIFO_Buff_status FIFO_enqeueu(FIFO_Buff_t* fifo,element_type item)
{
	//fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//fifo is full?
	if(FIFO_is_full(fifo) == FIFO_full)
		return FIFO_full;
	//enqueue fifo
	*(fifo->head) = item;
	fifo->count ++;
	if(fifo->head == (fifo->base + (sizeof(element_type)*(fifo->length))))
		fifo->head = fifo->base;
	else
		fifo->head ++;
	return FIFO_no_error;
}
FIFO_Buff_status FIFO_deqeueu(FIFO_Buff_t* fifo,element_type* item)
{
	//fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//fifo is empty?
	if(fifo->count ==0)
		return FIFO_empty;
	//dequeue fifo
	*item = *(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base + (sizeof(element_type)*(fifo->length))))
		fifo->tail = fifo->base;
	else
		fifo->tail ++;

	return FIFO_no_error;
}
FIFO_Buff_status FIFO_is_full(FIFO_Buff_t* fifo)
{
	//fifo is valid
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//fifo full
	if(fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}
void FIFO_print(FIFO_Buff_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count ==0)
		printf("\n fifo is empty \n");
	else
	{
		temp = fifo->tail;
		printf("\n ---------->fifo print<----------\n");
		for(i=0;i< fifo->count; i++)
		{
			printf("%x \n",*temp);
			temp++;
		}
	}

}

