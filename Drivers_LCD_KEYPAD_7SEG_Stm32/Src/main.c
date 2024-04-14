/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohannad Abd El Hakim
 * @brief          : Main program body
 ******************************************************************************
 */
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "lcd.h"
#include "keypad.h"

GPIO_PiConfig_t pinCfg ;

#define ZERO	 0x01
#define ONE		 0x79
#define TWO		 0x24
#define THREE	 0x30
#define FOUR	 0x4C
#define FIVE   	 0x12
#define SIX    	 0x02
#define SEVEN 	 0x19
#define EIGHT    0x00
#define NINE 	 0x10

void my_wait(int x)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);
}

void clock_init()
{
	//Enable clock for GPIOA
	RCC_GPIOA_CLK_EN();
	//Enable clock for GPIOB
	RCC_GPIOB_CLK_EN();

}

void GPIO_init()
{
	//set all ports form 9to 15 as output PP to display numbers on the seven sigment
	//00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz.

	pinCfg.GPIO_PinNumber=GPIO_PIN_9;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);


	pinCfg.GPIO_PinNumber=GPIO_PIN_10;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_11;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_12;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_13;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	//============================

	pinCfg.GPIO_PinNumber=GPIO_PIN_14;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_15;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &pinCfg);
}



int main(void)
{
	clock_init() ;
	GPIO_init() ;
	LCD_INIT();
	unsigned char key_pressed;
	//check on the lcd
	LCD_WRITE_STRING("hey There");
	my_wait(500);
	LCD_clear_screen();
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char SEG [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WRITE_CHAR(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, SEG[i] << 9); /* write data on to the LED port */
		my_wait(100);
		/* wait for 1 second */
	}
	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	my_wait(500);
	LCD_clear_screen();

	while(1)
	{
		key_pressed = Keypad_getkey();
		switch (key_pressed) {
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressed);
			break;

		}
		/*//PA1>>>External PUR
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)) //press
		{
			//toggle(^) bit PB1 when pushbutton is pressed
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0));//single pressing
		}
		//PA13>>>External PDR
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)==1) //press
		{
			//toggle(^) bit PB13 when pushbutton is pressed
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		my_wait(1);
	}*/
	}
}


