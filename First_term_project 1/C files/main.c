/*
 ============================================================================
 Name        : main.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"STATE.h"
#include "GPIOA.h"
#include "Alarm_Actuator.h"
#include"Pressure_Sensor.h"
#include"Alarm_monitor.h"
#include"PD.h"


void Setup()
{
	/*
	 * init all the drivers
	 * init IRQ...
	 * init HAL US_Driver DC_Driver
	 * init Block
	 * set States Pointers for each Block
	 */
	Pressure_Sensor_INIT();
	/*set state pointer for each block*/
	pPressure_sensor_state = STATE(Pressure_Sensor_reading);
	pPd_state = STATE(High_Pressure_Detected);
	pAlarm_monitor_state = STATE(Alarm_monitor_Off);
	//pAlarm_Actuator_state=STATE(Alarm_Actuator_OFF);
}
int main (){
	Setup();

	while (1)
	{
		//Implement your Design
		pPressure_sensor_state();
		pPd_state();
		pAlarm_monitor_state();
		//pAlarm_Actuator_state();

		//delay
		Delay(1000);
	}

}

