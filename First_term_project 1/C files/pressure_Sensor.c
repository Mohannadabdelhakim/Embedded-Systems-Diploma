/*
 ============================================================================
 Name        : Pressure_Sensor.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Mohannad Abd Elhakim
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"Pressure_Sensor.h"
#include"STATE.h"
#include "GPIOA.h"
#include "Platform_Types.h"

/*state pointer*/
extern void(*pPressure_sensor_state)();

/*variables*/
int Psensor_Pressure=0;

void Pressure_Sensor_INIT()
{
	GPIO_INITIALIZATION ();
	//printf("-----Pressure Sensor Driver INIT-----\n");

}

STATE_define(Pressure_Sensor_reading)
{
	/*state name*/
	Pressure_Sensor_state_ID=Pressure_Sensor_reading;

	/*state action*/
	Psensor_Pressure = getPressureVal();

	/*send pressureVAL to PD*/
	psensor_set_pressure(Psensor_Pressure);
}

//STATE_define(Pressure_Sensor_waiting)
//{
//	/*state name*/
//	Pressure_Sensor_state_ID=Pressure_Sensor_waiting;
//	/*state action*/
//	Pval=getPressureVal();
//	getPressureVal(Pval);
//
//	pPressure_sensor_state=STATE(Pressure_Sensor_reading);
//}






