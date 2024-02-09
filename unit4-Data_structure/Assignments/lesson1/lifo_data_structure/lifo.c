/*
 * lifo.c
 *
 *  Created on: Feb 5, 2024
 *      Author: Apex
 */

#include "lifo.h"
LIFO_Buf_status LIFO_init(LIFO_Buf_t* lifo,element_type* buffer,uint32 length)
{
	if(buffer==NULL)
		return LIFO_null;

	lifo-> base = buffer;
	lifo-> head = buffer;
	lifo->length = length;
	lifo->count=0;
	return LIFO_no_error;
}
LIFO_Buf_status LIFO_add_item(LIFO_Buf_t* lifo,element_type item)
{
	//lifo is valid
	if(!lifo->base||!lifo->head)
		return LIFO_null;
	//is full?
	if (lifo->count==lifo->length)
		return LIFO_full;


	//add_item
	*(lifo-> head)=item;
	lifo->head ++;
	lifo->count ++;
	return LIFO_no_error;

}
LIFO_Buf_status LIFO_get_item(LIFO_Buf_t* lifo,element_type* item)
{
	//lifo is valid
	if(!lifo->base || !lifo-> head)
		return LIFO_null;
	//is empty?
	if (lifo->count==0)
		return LIFO_empty;
	//get item
	lifo->head --;
	*item = *(lifo->head);
	lifo->count --;
	return LIFO_no_error;
}

