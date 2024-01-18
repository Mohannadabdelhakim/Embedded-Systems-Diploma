/*
 * main.c
 *
 *  Created on: Jan 18, 2024
 *      Author: HP
 */
#include"STATE.h"
#include"US.h"
#include"DC.h"
#include"CA.h"

void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_Driver DC_Driver
	/*init block*/

	US_init();
	DC_init();

	//Set State pointer for each block
	pCA_state =STATE(CA_waiting);
	pUS_state=STATE(US_busy);
	pDC_state=STATE(DC_idle);
}


void main()
{
	volatile int delay=0;

	setup();

	while(1)
	{
		pUS_state();
		pCA_state();
		pDC_state();
		for(delay=0;delay<=1000;delay++);
	}
}
