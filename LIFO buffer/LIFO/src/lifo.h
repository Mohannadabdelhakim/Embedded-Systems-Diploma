/*
 * LIFO.h
 *
 *  Created on: Dec 29, 2023
 *      Author: HP
 */

#ifndef LIFO_H_
#define LIFO_H_

//type definitions
typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO_BUF_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_NULL
}LIFO_STATUS;

//APIs
LIFO_STATUS LIFO_ADD (LIFO_BUF_t* lifo_buff , 	unsigned int item);	//LIFO ADD (LIFO NAME, ITEM to be added)
LIFO_STATUS LIFO_GET (LIFO_BUF_t* lifo_buff , 	unsigned int * item); //LIFO GET (LIFO NAME, ITEM to be popped)
LIFO_STATUS LIFO_init (LIFO_BUF_t* lifo_buff , 	unsigned int* BUFF ,unsigned int length); //LIFO initialize (LIFO NAME, buffer it self)

#endif /* LIFO_H_ */
