/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: HP
 */

#include "fifo.h"
//APIs

FIFO_STATUS FIFO_init (FIFO_Buf_t* fifo , unsigned int* BUFF , uint32_t length)
{
	if (BUFF== NULL)
		return FIFO_NULL;
	fifo->base=BUFF;
	fifo->head=BUFF;
	fifo->tail=BUFF;
	fifo->length=length;
	fifo->count=0;

	return FIFO_no_error;
}
FIFO_STATUS FIFO_enqueue (FIFO_Buf_t* fifo , unsigned int item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	//FIFO full case check
	if(FIFO_IS_FULL((fifo)==FIFO_full))
		return FIFO_full;
	//enqueue action
	fifo->head=item;
	fifo->count++;
	//circular mechanism
	if(fifo->head==(fifo->base+(fifo->length *sizeof(element_type))))
		fifo->head=fifo->base;
	else
		fifo->head++;
}
FIFO_STATUS FIFO_dequeue (FIFO_Buf_t* fifo , unsigned int* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count==0)
		return FIFO_empty;
	*item=*(fifo->tail);
	//circular mechanism
	if(fifo->tail==(fifo->base+(fifo->length *sizeof(element_type))))
		fifo->tail=fifo->base;
	else
		fifo->tail++;
}
FIFO_STATUS FIFO_IS_FULL (FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count==fifo->length)
		return FIFO_full;
	return FIFO_no_error;

}
FIFO_STATUS FIFO_Print (FIFO_Buf_t* fifo) // @suppress("No return")
{
	int i;
	element_type* temp;
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count==0)
		return FIFO_empty;
	else
		temp=fifo->tail;\
		printf("\n=========FIFO print =========");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t %x \n");
			temp++;
		}
		printf("\n==================");
}
