/*
 * US.h
 *
 *  Created on: Jan 18, 2024
 *      Author: HP
 */

#ifndef US_H_
#define US_H_

/*define states*/\
enum{
	US_busy,
}US_STATE_ID;

/*state pointer*/
void (*pUS_state)();

/*US model INIT*/
void US_init();

//declare state functions of CA
STATE_define(US_busy);	//void ST_US_busy();

#endif /* US_H_ */
