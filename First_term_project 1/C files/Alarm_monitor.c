/*
 ============================================================================
 Name        : .c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alarm_monitor.h"
#include "STATE.h"
#include "Alarm_Actuator.h"
#include "GPIOA.h"
#include "Platform_Types.h"

/*state pointer*/
extern void(*pAlarm_monitor_state)();


void Start_alarm();
void Stop_alarm();

/*void Alarm_monitor_INIT()
{
	//printf("-----Alarm Monitor INIT-----\n");
}*/

void High_Pressure_detected()
{
	pAlarm_monitor_state=STATE(Alarm_monitor_ON);
}

STATE_define(Alarm_monitor_ON)
{
	/*state name*/
	Alarm_monitor_state_ID=Alarm_monitor_ON;
	/*state action*/
	Start_alarm();
	Delay(60000);
	Stop_alarm();
	pAlarm_monitor_state=STATE(Alarm_monitor_Off);

}

STATE_define(Alarm_monitor_Off)
{
	/*state name*/
	Alarm_monitor_state_ID=Alarm_monitor_Off;
	/*state action*/
	Stop_alarm();
}


STATE_define(Alarm_monitor_waiting)
{
	/*state name*/
	Alarm_monitor_state_ID=Alarm_monitor_waiting;
	/*state action*/
	Delay(60000);
	pAlarm_monitor_state=STATE(Alarm_monitor_Off);
}

