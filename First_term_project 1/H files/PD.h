/*
 * PD.h
 *
 *  Created on: Jan 21, 2024
 *      Author: HP
 */

#ifndef PD_H_
#define PD_H_
#include"STATE.h"
#include "stdint.h"
#include "stdio.h"
#include "GPIOA.h"
#include "Platform_Types.h"

enum{
	High_Pressure_Detected
}PD_state_ID;

/*state pointer*/
void(*pPd_state)();

//declare state functions of PD
STATE_define(High_Pressure_Detected);


#endif /* PD_H_ */
