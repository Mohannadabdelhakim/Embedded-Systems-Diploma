/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: HP
 */

#include "fifo.h"

void main()
{
	element_type i;
	element_type temp;
	temp = 0;
	FIFO_Buf_t Uart_FIFO ;

	//FIFO init
	if(FIFO_init(&Uart_FIFO,Uart_BUFF,5)==FIFO_no_error)
		printf("FIFO init .........");

	//FIFO enqueue
	for(i=0;i<7;i++)
	{
		printf("\nFIFO enqueue (%x)",i);

		if(FIFO_enqueue(&Uart_FIFO,i)==FIFO_no_error)
			printf("FIFO enqueue.....done\n");
		else
		printf("FIFO enqueue.....failed\n");

	}
	//FIFO dequeue
		for(i=0;i<7;i++)
		{
			FIFO_Print(&Uart_FIFO);
			if(FIFO_dequeue(&Uart_FIFO,&temp)==FIFO_no_error)
			printf("FIFO dequeue (%x)",temp);
			if(FIFO_dequeue(&Uart_FIFO,&temp)==FIFO_no_error)
			printf("FIFO dequeue (%x)",temp);
			FIFO_Print(&Uart_FIFO);
		}
}
