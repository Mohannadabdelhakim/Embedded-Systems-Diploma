/*
 * STATE.h
 *
 *  Created on: Jan 21, 2024
 *      Author: HP
 */

#ifndef STATE_H_
#define STATE_H_
#include "GPIOA.h"
#include "Platform_Types.h"

/*macro for function generation*/
#define STATE_define(_statefunc_) ST_##_statefunc_()

/*macro for function calling*/
#define STATE(_statefunc_) ST_##_statefunc_

//states connections
void psensor_set_pressure(int p);
void Start_alarm();
void Stop_alarm();
void highpressure_detected();

#endif /* STATE_H_ */
