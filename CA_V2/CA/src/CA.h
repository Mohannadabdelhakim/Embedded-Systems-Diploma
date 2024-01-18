/*
 * CA.h
 *
 *  Created on: Jan 18, 2024
 *      Author: HP
 */

#ifndef CA_H_
#define CA_H_

enum{
	CA_waiting,
	CA_driving
}CA_STATE_ID;

void (*pCA_state)();

//declare state functions of CA
STATE_define(CA_driving);  //void ST_CA_driving();
STATE_define(CA_waiting);  //void ST_CA_waiting();


#endif /* CA_H_ */
