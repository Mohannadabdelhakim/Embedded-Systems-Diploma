/*
 * LIFO.c
 *
 *  Created on: Dec 29, 2023
 *      Author: MOHANNAD
 */

#include "lifo.h"

//APIs
LIFO_STATUS LIFO_ADD (LIFO_BUF_t* lifo_buff , unsigned int item)
{
	// check if the LIFO is valid
	if(!lifo_buff->head || !lifo_buff->base)
		return LIFO_NULL;

	// check if the LIFO is full
	//if(lifo_buff->head == (lifo_buff->base +( lifo_buff->length * 4)))
	if(lifo_buff->count==lifo_buff->length)
		return LIFO_full;

	// add item normally
	*(lifo_buff->head)=item;
	lifo_buff->head++;
	lifo_buff->count++;

	return LIFO_no_error;
}

LIFO_STATUS LIFO_GET (LIFO_BUF_t* lifo_buff ,unsigned int* item)
{
	// check if the LIFO is valid
	if(!lifo_buff->head || !lifo_buff->base)
		return LIFO_NULL;

	// check if the LIFO is empty
	if(lifo_buff->count == 0)
		return LIFO_empty;
	// add item normally
	lifo_buff->head--;
	*(item)=*(lifo_buff->head);
	lifo_buff->count--;

	return LIFO_no_error;
}

LIFO_STATUS LIFO_init (LIFO_BUF_t* lifo_buff , 	unsigned int* BUFF ,unsigned int length)
{
	if (BUFF == '0')
	    return LIFO_NULL;


	lifo_buff->base = BUFF;
	lifo_buff->head = BUFF;
	lifo_buff->length =length;
	lifo_buff->count=0;

	return LIFO_no_error ;
}
