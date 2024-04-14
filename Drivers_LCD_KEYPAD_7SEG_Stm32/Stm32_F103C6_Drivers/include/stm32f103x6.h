/*
 * stm32f103x6.h
 *
 *  Created on: Apr 3, 2024
 *      Author: HP
 */

#ifndef INCLUDE_STM32F103X6_H_
#define INCLUDE_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include <stdint.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE    							0x08000000UL
#define SRAM_MEMORY_BASE     							0x20000000UL
#define SYSTEM_MEMORY_BASE   							0x1FFFF000UL

#define Peripheral_MEMORY_BASE     						0x40000000UL
#define Cortex_M3_internal_peripherals_MEMORY_BASE     	0xE0000000UL


//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------

//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------
//RCC
#define RCC_BASE		0x40021000UL

//-----------------------------
//Base addresses for APB BUS Peripherals
//-----------------------------

//GPIO
//A,B is fully included in LQFP48 Package
#define GPIOA_BASE		0x40010800UL
#define GPIOB_BASE		0x40010C00UL


//C,D is partially included

#define GPIOC_BASE		0x40011000UL
#define GPIOD_BASE		0x40011400UL

//E is not included
#define GPIOE_BASE		0x40011800UL

//EXTI
#define EXTI_BASE  			0x40010400UL

//AFIO
#define AFIO_BASE			0x40010000UL

//==========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
	uint32_t 		  Resereved0 ; 	//0x18
	volatile uint32_t AFIO_MAPR2;  //0x1c

}AFIO_Typedef;

//==========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 		((GPIO_Typedef *) GPIOA_BASE)
#define GPIOB 		((GPIO_Typedef *) GPIOB_BASE)
#define GPIOC 		((GPIO_Typedef *) GPIOC_BASE)
#define GPIOD 		((GPIO_Typedef *) GPIOD_BASE)
#define GPIOE 		((GPIO_Typedef *) GPIOE_BASE)



#define RCC 		((RCC_Typedef *)RCC_BASE)

#define EXTI		((EXTI_Typedef *)EXTI_BASE)


#define AFIO 		((AFIO_Typedef *)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:GPIO/AFIO
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |=1<<6)

#define AFIO_GPIO_CLK_EN()		(RCC->APB2ENR |=1<<0)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INCLUDE_STM32F103X6_H_ */
