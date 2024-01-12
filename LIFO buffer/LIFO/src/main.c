/*
 ============================================================================
 Name        : LIFO.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

//create first buffer
unsigned int Buffer1[5]; //4*5=20byte

int main()
{
	int i,temp=0;
	LIFO_BUF_t Uart_LIFO,I2C ;
	//static allocation for buffer 1
	LIFO_init(&Uart_LIFO , Buffer1 , 5);
	//dynamic allocation for buffer 2
	unsigned int* Buffer2 = (unsigned int*) malloc(5*sizeof(unsigned int)); //5*4=20 byte

	//lifo initialize
	LIFO_init(&I2C, Buffer2,5);
	//add item
	for (i=0;i<5;i++)
	{
		if(LIFO_ADD(&Uart_LIFO ,i) == LIFO_no_error)
			printf("\n Uart_LIFO add item : %d",i);
	}
	//get item
	for (i=0;i<5;i++)
	{
		if(LIFO_GET(&Uart_LIFO,&temp) == LIFO_no_error)
			printf("\n Uart_LIFO get item : %d",temp);
	}


}
