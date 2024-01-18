/*
 ============================================================================
 Name        : CA.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"STATE.h"
#include "DC.h"

static int DC_speed=0;

/*state pointer*/
extern void DC_init();

void DC_init()
{
	printf("DC_motor module INIT\n");
}

void DC_motor_set(int s)
{
	DC_speed=s;
	pDC_state=STATE(DC_busy);
	printf("\n CA -> -> -> DC \n");
}

STATE_define(DC_idle)
{
	DC_STATE_ID=DC_idle;
	/*state action*/
	pDC_state=STATE(DC_idle);
	printf("-------DC_idle state with speed = %d-------\n \n \n",DC_speed);

}


STATE_define(DC_busy)
{
	/*state action*/

	DC_STATE_ID=DC_busy;
	/*call DC_driver*/
	DC_speed=30;
	pDC_state=STATE(DC_idle);
	printf("-------DC_busy state with speed=%d-------\n \n \n",DC_speed);

}



