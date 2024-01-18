/*
 * DC.h
 *
 *  Created on: Jan 18, 2024
 *      Author: HP
 */

#ifndef DC_H_
#define DC_H_

/*define states*/
enum{
	DC_busy,
	DC_idle
}DC_STATE_ID;

/*state pointer*/
void (*pDC_state)();

/*DC_motor model INIT*/
void DC_init();

//declare state functions of DC
STATE_define(DC_busy);
STATE_define(DC_idle);

#endif /* DC_H_ */
