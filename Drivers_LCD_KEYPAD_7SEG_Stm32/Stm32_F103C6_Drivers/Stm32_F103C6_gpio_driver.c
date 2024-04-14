/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Mohannad Abd El hakim
 */

//Includes
#include "Stm32_F103C6_gpio_driver.h"


/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Intializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]  -GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -PinConfig pointer to GPIO_PiConfig_t struct that contains the pin configuration info for the specified PIN
 * @retval 		-NONE
 * Note			-Stm32F103C6 contains GPIO A,B,C,D,E modules
 * 				-LQFP48 Package has only A & B,Part of C & D exported as External Pins from the MCU
 */

//Get_CRLH_Position function to get the position of the specified pin in either CRL or CRH Register
uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_7:
		return 24;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0 ;
}

void MCAL_GPIO_Init (GPIO_Typedef*GPIOx , GPIO_PiConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) from 0 to 7
	//Port configuration register high (GPIOx_CRH) from 8 to 15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_CONFIG=0;
	configregister=(PinConfig->GPIO_PinNumber< GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	//clear CNFy[1:0]: Port x configuration bits (y= 0 .. 7) | clear CNFy[1:0]: Port x configuration bits (y= 8 .. 15)
	//clear the specified CNF pins from Get_CRLH_Position function after storing ones in them(0xf)
	(*configregister)&=~(0xf<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//IF THE PIN IS OUTPUT
	if(	(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD	) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) ||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD	) ||(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) )
	{
		//set CNF8[1:0] MODE8[1:0]

		PIN_CONFIG=( (((PinConfig->GPIO_MODE -4 )<<2) | (PinConfig->GPIO_Output_Speed)) & 0x0f );
	}
	//if pin is input
	else //MODE=00:Input mode (reset state)
	{
		if(	(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO	) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//set CNF8[1:0] MODE8[1:0]
			PIN_CONFIG=( (((PinConfig->GPIO_MODE)<<2) |0x0) & 0x0f );
		}else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{
			//set CNF8[1:0] MODE8[1:0]00
			PIN_CONFIG=( (((GPIO_MODE_INPUT_FLO )<<2) |0x0) & 0x0f );
		}
		else //PU PD Input
		{
			PIN_CONFIG=( (((GPIO_MODE_INPUT_PU )<<2) |0x0) & 0x0f );
			if(PinConfig->GPIO_MODE== GPIO_MODE_INPUT_PU)
			{
				//PxODR= 1 Input pull up from table 20. port bit config table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;

			}
			else
			{
				//PxODR= 1 Input pull up from table 20. port bit config table
				GPIOx->ODR &=~( PinConfig->GPIO_PinNumber);
			}
		}
	}
	(*configregister)|= ( (PIN_CONFIG)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
}

/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-RESET the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in]  -GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @retval 		-None
 * Note			-None
 *
 */
void MCAL_GPIO_DeInit(GPIO_Typedef*GPIOx )
{
	/*APB2 peripheral reset register (RCC_APB2RSTR)
	Address offset: 0x0C
	Reset value: 0x00000 0000
	Access: no wait state, word, half-word and byte access*/
	if(GPIOx == GPIOA)
	{
		//Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);
	}else if(GPIOx==GPIOB)
	{
		//Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}else if(GPIOx==GPIOC)
	{
		//Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}else if(GPIOx==GPIOD)
	{
		//Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}else if(GPIOx==GPIOE)
	{
		//Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}


}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief		-Read the specified Input Pin Value
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -PinNumber:SET PinNumber according to @ref GPIO_PIN_define
 * @retval 		-The Input Pin Value @ref GPIO_PIN_STATE (0 or 1)
 * Note			-None
 */

//READ APIs
uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef*GPIOx , uint16_t PinNumber)
{
	uint8_t bitstatus;
	if(((GPIOx->IDR) & PinNumber)!=(uint32_t)GPIO_PIN_RESET)
	{
		bitstatus= GPIO_PIN_SET ;
	}else
	{
		bitstatus=GPIO_PIN_RESET ;
	}
	return bitstatus ;
}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief		-Read the specified Input Port Value
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @retval 		-The Input Port Value @ref GPIO_PIN_STATE (0 or 1)
 * Note			-None
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef*GPIOx)
{
	uint16_t port_value;
	port_value = (uint16_t)(GPIOx->IDR);
	return port_value ;
}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write on the specified Input Pin
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -PinNumber:SET PinNumber according to @ref GPIO_PIN_define
 * @param [in]  -Value:Pin Value
 * @retval 		-None
 * Note			-None
 */

//WRITE APIs
void MCAL_GPIO_WritePin (GPIO_Typedef*GPIOx , uint16_t PinNumber,uint8_t Value)
{
	if(Value!= GPIO_PIN_RESET)
	{
		//GPIOx->ODR |=PinNumber;
		//or
		/*Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Set the corresponding ODRx bit*/
		GPIOx->BSRR = PinNumber;
	}else
	{
		/*Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Reset the corresponding ODRx bit*/
		GPIOx->BRR = PinNumber ;
	}

}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief		-Write on the specified Input Port
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -Value:Pin Value
 * @retval 		-None
 * Note			-None
 */

void MCAL_GPIO_WritePort (GPIO_Typedef*GPIOx , uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;

}

/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief		-Toggle the specified Pin
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -PinNumber: specifies the PinNumber according to @ref GPIO_PIN_define
 * @retval 		-None
 * Note			-None
 */
void MCAL_GPIO_TogglePin (GPIO_Typedef*GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^=(PinNumber);
}

/**================================================================
 * @Fn			-MCAL_GPIO_Lockpin
 * @brief		-The locking Mechanism allows the IO configuration to be frozen
 * @param [in] 	-GPIOx : where x can be any instant(A..E depending on device used)to select the used peripheral instant
 * @param [in]  -PinNumber:Specifies the Port bit to read.set by  @ref GPIO_PIN_define
 * @retval 		-OK if pin confid is locked Or ERROR if pin not locked(Ok and ERROR are defined @ref GPIO_RETURN_LOCk
 * Note			-None
 */

uint8_t MCAL_GPIO_Lockpin (GPIO_Typedef*GPIOx , uint16_t PinNumber)
{
/*Bit 16 LCKK[16]: Lock key
This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
0: Port configuration lock key not active
1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
LOCK key writing sequence:
Write 1
Write 0
Write 1
Read 0
Read 1 (this read is optional but confirms that the lock is active)
Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
Any error in the lock sequence will abort the lock.
Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
These bits are read write but can only be written when the LCKK bit is 0.
0: Port configuration not locked
1: Port configuration locked.
 * */
//set LCKK[16]
	volatile uint32_t tmp = 1<<16;
//set the LCKy
	tmp |= PinNumber;
	//Write 1
	GPIOx->LCKR = tmp;
	//Write 0
	GPIOx->LCKR = PinNumber;
	//Write 1
	GPIOx->LCKR = tmp;
	//Read 0
	GPIOx->LCKR = PinNumber;
	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_Return_Lock_Enabled;
	}else
	{
		return GPIO_Return_Lock_ERROR;
	}
}



















