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
#include "US.h"

int US_Get_distance_random(int l,int r,int count);

static int US_distance=0;
/*state pointer*/
extern void US_init();

void US_init()
{
	printf("US_INIT module \n");
}

STATE_define(US_busy)
{
	/*state name*/
	US_STATE_ID=US_busy;
	/*state action*/
	US_distance= US_Get_distance_random(45,55,1);
	US_set_distance(US_distance);
	pUS_state=STATE(US_busy);

}

/********************************************************/
int US_Get_distance_random(int l,int r,int count)
{
	int i,rand_num;
	for(i=0;i<count;i++)
	{
		rand_num = (rand()%(r-l+1))+1;
		return rand_num;

	}
}
