/*
 * STATE.h
 *
 *  Created on: Jan 18, 2024
 *      Author: HP
 */

#ifndef STATE_H_
#define STATE_H_

/*macro for function generation*/
#define STATE_define(_statefunc_) ST_##_statefunc_()

/*macro for function calling*/
#define STATE(_statefunc_) ST_##_statefunc_

/*connections between blocks*/
void US_set_distance(int d);
void DC_motor_set(int s);

#endif /* STATE_H_ */
