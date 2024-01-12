/*
 * fifo.h
 *
 *  Created on: Dec 31, 2023
 *      Author: HP
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

//user configuration
//select the element type(uint8_t,uint32_t,...) and width
#define element_type uint8_t
#define width1 5
//define the UART buffer with element type data type
element_type Uart_BUFF [width1] ;

//FIFO data types
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* head;
	element_type* tail;
	element_type* base;
}FIFO_Buf_t;

//FIFO status
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_STATUS;

//APIs
FIFO_STATUS FIFO_init (FIFO_Buf_t* fifo , unsigned int* BUFF , uint32_t length); //FIFO initialize (LIFO NAME, buffer it self)
FIFO_STATUS FIFO_enqueue (FIFO_Buf_t* fifo , unsigned int item);	//FIFO ADD (LIFO NAME, ITEM to be added)
FIFO_STATUS FIFO_dequeue (FIFO_Buf_t* fifo , unsigned int* item); //FIFO GET (LIFO NAME, ITEM to be popped)
FIFO_STATUS FIFO_IS_FULL (FIFO_Buf_t* fifo); //is the FIFO full?
FIFO_STATUS FIFO_Print (FIFO_Buf_t* fifo); //FIFO Print

#endif /* FIFO_H_ */
