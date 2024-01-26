/*
 * Alarm_Actuator.h
 *
 *  Created on: Jan 21, 2024
 *      Author: HP
 */

#ifndef Alarm_Actuator_H_
#define Alarm_Actuator_H_
#include"STATE.h"
#include "stdint.h"
#include "stdio.h"
#include "Platform_Types.h"

/*State_Define*/
enum{
	Alarm_Actuator_ON,
	Alarm_Actuator_OFF
}Alarm_Actuator_state_ID;

/*state pointer*/
void(*pAlarm_Actuator_state)();

/*model INIT*/
void Alarm_Actuator_INIT();

/*declare state functions of Alarm actuator*/
STATE_define(Alarm_Actuator_ON);
STATE_define(Alarm_Actuator_OFF);

/*functions to be called*/
void Start_alarm();
void Stop_alarm();


#endif /* Alarm_Actuator_H_ */
