/*
 * Pressure_Sensor.h
 *
 *  Created on: Jan 21, 2024
 *      Author: HP
 */

#ifndef Pressure_Sensor_H_
#define Pressure_Sensor_H_
#include "Platform_Types.h"

/*state Define*/
enum{
	Pressure_Sensor_waiting,
	Pressure_Sensor_reading
}Pressure_Sensor_state_ID;

/*state pointer*/
void(*pPressure_sensor_state)();
/*model INIT*/
void Alarm_Actuator_INIT();

/*declare state functions of Pressure Sensor*/
//STATE_define(Pressure_Sensor_waiting);
STATE_define(Pressure_Sensor_reading);

#endif /* Pressure_Sensor_H_ */
