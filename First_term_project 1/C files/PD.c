/*
 ============================================================================
 Name        : PD.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"PD.h"
#include"STATE.h"
#include"Alarm_monitor.h"
#include "Alarm_Actuator.h"
#include "GPIOA.h"
#include "Platform_Types.h"

/*state pointer*/
extern void(*pPd_state)();

/*variables*/
static int PD_val=0;
static int PD_thershold=20;

void psensor_set_pressure(int p){

	PD_val = p;
	pPd_state = STATE(High_Pressure_Detected);
}

STATE_define(High_Pressure_Detected)
{
	/*state name*/
	PD_state_ID=High_Pressure_Detected;
	/*state action*/
	if(PD_val>=PD_thershold)
	{
		//send signal to monitor
		High_Pressure_detected();
		pPd_state=STATE(High_Pressure_Detected);
	}
	else
	{
		pPd_state=STATE(High_Pressure_Detected);
	}

}

