/*
 * Stm32_F103C6_gpio_driver.h
 *
 *  Created on: Apr 3, 2024
 *      Author: HP
 */

#ifndef INCLUDE_STM32_F103C6_GPIO_DRIVER_H_
#define INCLUDE_STM32_F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103x6.h"

//---------------------------------

//-----------------------------
//User type definitions (structures)
//-----------------------------

//config structure

typedef struct
{
	uint16_t GPIO_PinNumber ; 		   //Specifies the GPIO pins to be configured
									  //This parameter must be set based on @ref GPIO_PIN_define

	uint8_t GPIO_MODE ;				 //Specifies the GPIO mode for the selected pin
									//This parameter must be a value of @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed ;    //Specifies the Output Speed fot he selected pin
	   	   	   	   	   	   	   	  //This parameter must be a value of @ref GPIO_SPEED_define

}GPIO_PiConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

// @ref GPIO_PIN_define

#define GPIO_PIN_0				((uint16_t)0x0001)	/*pin 0 selected*/  //== 1binary
#define GPIO_PIN_1				((uint16_t)0x0002)	/*pin 0 selected*/  //==2binary 10 		==1<<2
#define GPIO_PIN_2				((uint16_t)0x0004)	/*pin 0 selected*/	//==3binary 100 	==1<<3
#define GPIO_PIN_3				((uint16_t)0x0008)	/*pin 0 selected*/	//==4binary 1000  	==1<<4
#define GPIO_PIN_4				((uint16_t)0x0010)	/*pin 0 selected*/	//==5binary 10000	==1<<5
#define GPIO_PIN_5				((uint16_t)0x0020)	/*pin 0 selected*/
#define GPIO_PIN_6				((uint16_t)0x0040)	/*pin 0 selected*/
#define GPIO_PIN_7				((uint16_t)0x0080)	/*pin 0 selected*/
#define GPIO_PIN_8				((uint16_t)0x0100)	/*pin 0 selected*/
#define GPIO_PIN_9				((uint16_t)0x0200)	/*pin 0 selected*/
#define GPIO_PIN_10				((uint16_t)0x0400)	/*pin 0 selected*/
#define GPIO_PIN_11				((uint16_t)0x0800)	/*pin 0 selected*/
#define GPIO_PIN_12				((uint16_t)0x1000)	/*pin 0 selected*/
#define GPIO_PIN_13				((uint16_t)0x2000)	/*pin 0 selected*/
#define GPIO_PIN_14				((uint16_t)0x4000)	/*pin 0 selected*/
#define GPIO_PIN_15				((uint16_t)0x8000)	/*pin 0 selected*/
#define GPIO_PIN_ALL			((uint16_t)0xFFFF)	/*pin 0 selected*/

#define GPIO_PIN_MASK			0x0000FFFFu	/*pin 0 selected*/

//--------------------------------------------------------------------

//@ref GPIO_MODE_define

/*In input mode (MODE[1:0]=00):
00: Analog mode
1: Floating input (reset state)
2: Input with pull-up
3: Input with pull-down
In output mode (MODE[1:0] > 00):
4: General purpose output push-pull
5: General purpose output Open-drain
6: Alternate function output Push-pull
7: Alternate function output Open-drain
8: Alternate function Input
*/

#define GPIO_MODE_Analog			0x00000000u		//Analog Mode
#define GPIO_MODE_INPUT_FLO			0x00000001u		//Floating input (reset state)
#define GPIO_MODE_INPUT_PU			0x00000002u		//Input with pull-up
#define GPIO_MODE_INPUT_PD			0x00000003u		//Input with pull-down
#define GPIO_MODE_OUTPUT_PP			0x00000004u		//General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD			0x00000005u		//General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u		//Alternate function output Push-pul
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u		//Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT			0x00000008u		//Alternate function Input

//--------------------------------------------------------------------

//@ref GPIO_SPEED_define

 /*00: Input mode (reset state)
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz
*/
#define GPIO_SPEED_10M			0x00000001u		//Output mode, max speed 10 MHz.
#define GPIO_SPEED_2M			0x00000002u		//Output mode, max speed 2 MHz.
#define GPIO_SPEED_50M			0x00000003u		//Output mode, max speed 50 MHz


//--------------------------------------------------------------------

//@ref GPIO_PIN_STATE
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0

//--------------------------------------------------------------------

//@ref GPIO_RETURN_LOCk
#define GPIO_Return_Lock_Enabled 	1
#define GPIO_Return_Lock_ERROR	0



/* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init 		(GPIO_Typedef*GPIOx , GPIO_PiConfig_t* PinConfig);
void MCAL_GPIO_DeInit 		(GPIO_Typedef*GPIOx );

//READ APIs
uint8_t MCAL_GPIO_ReadPin 		(GPIO_Typedef*GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort 	(GPIO_Typedef*GPIOx);


//WRITE APIs
void MCAL_GPIO_WritePin 	(GPIO_Typedef*GPIOx , uint16_t PinNumber,uint8_t Value);
void MCAL_GPIO_WritePort 	(GPIO_Typedef*GPIOx , uint16_t Value);

void MCAL_GPIO_TogglePin 	(GPIO_Typedef*GPIOx , uint16_t PinNumber);

uint8_t MCAL_GPIO_Lockpin 		(GPIO_Typedef*GPIOx , uint16_t PinNumber);

#endif /* INCLUDE_STM32_F103C6_GPIO_DRIVER_H_ */



