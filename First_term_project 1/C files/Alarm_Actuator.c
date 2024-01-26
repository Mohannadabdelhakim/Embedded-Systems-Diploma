/*
 ============================================================================
 Name        : c.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alarm_Actuator.h"
#include "Alarm_monitor.h"
#include"STATE.h"
#include "GPIOA.h"
#include "Platform_Types.h"

/*state pointer*/
extern void(*pAlarm_Actuator_state)();

/*variables*/


void Alarm_Actuator_INIT()
{
		GPIO_INITIALIZATION();
	//printf("-----Alarm Actuator INIT-----\n");
}
void Start_alarm()
{
	Set_Alarm_actuator(0);
}

void Stop_alarm()
{
	Set_Alarm_actuator(1);
}

//STATE_define(Alarm_Actuator_ON)
//{
//	/*state name*/
//	Alarm_Actuator_state_ID=Alarm_Actuator_ON;
//	/*state action*/
//	Set_Alarm_actuator(0);
//	pAlarm_Actuator_state=STATE(Alarm_Actuator_ON);
//}

//STATE_define(Alarm_Actuator_OFF)
//{
//	/*state name*/
//	Alarm_Actuator_state_ID=Alarm_Actuator_OFF;
//	/*state action*/
//	Set_Alarm_actuator(1);
//	pAlarm_Actuator_state=STATE(Alarm_Actuator_OFF);
//}

