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
#include "CA.h"
/*variables*/
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

/*state pointer*/
extern void (*pCA_state)();

int US_Get_distance_random(int l,int r,int count);


void US_set_distance(int d)
{
	CA_distance= d;
	(CA_distance<= CA_threshold)? (pCA_state=STATE(CA_waiting)):(pCA_state=STATE(CA_driving));
	printf("US-------distance=%d -------> CA\n",CA_distance);
}


 STATE_define(CA_waiting)
{
	/*state name*/
	CA_STATE_ID=CA_waiting;
	printf("CA_waiting---->speed=%d,distance=%d",CA_speed,CA_distance);
	/*state action*/
	CA_speed=0;
	DC_motor_set(CA_speed);
	CA_distance=US_Get_distance_random(45,55,1);

}

 STATE_define(CA_driving)
{
	/*state name*/
	CA_STATE_ID=CA_driving;
	printf("US_driving---->speed=%d,distance=%d",CA_speed,CA_distance);
	/*state action*/
	CA_speed=30;
	DC_motor_set(CA_speed);
}
