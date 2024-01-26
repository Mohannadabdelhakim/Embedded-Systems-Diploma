/*
 * Alarm_monitor.h
 *
 *  Created on: Jan 21, 2024
 *      Author: HP
 */

#ifndef Alarm_monitor_H_
#define Alarm_monitor_H_
#include"STATE.h"
#include "stdint.h"
#include "stdio.h"
#include "GPIOA.h"
#include "Platform_Types.h"

/*State_Define*/
enum{
	Alarm_monitor_waiting,
	Alarm_monitor_Off,
	Alarm_monitor_ON
}Alarm_monitor_state_ID;

/*state pointer*/
void(*pAlarm_monitor_state)();

/*declare state functions of Alarm monitor*/
STATE_define(Alarm_monitor_waiting);
STATE_define(Alarm_monitor_Off);
STATE_define(Alarm_monitor_ON);

void Start_alarm();
void Stop_alarm();
#endif /*Alarm_monitor_H_ */
