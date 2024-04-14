/*
 * lcd.c
 *
 * Created: 4/22/2024 4:01:23 PM
 *  Author: Mohannad
 */ 

#include "lcd.h"


GPIO_PiConfig_t pinCfg ;

void LCD_INIT()
{
	//DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	//LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	//EN_SWITCH,RS_SWITCH,RW_SWITCH input HighZ floating input

	my_wait(20);

	pinCfg.GPIO_PinNumber = RS_SWITCH;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber = RW_SWITCH;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber = EN_SWITCH;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//DataDir_LCD_PORT = 0xFF;
	//============================
	//DATA Pins output with speed 10mhz
	//PA1 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_0;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA1 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_1;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA2 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_2;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA3 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_3;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA4 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_4;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA5 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_5;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA6 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_6;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//PA7 output push pull mode
	pinCfg.GPIO_PinNumber=GPIO_PIN_7;
	pinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pinCfg.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	
	my_wait(15);

	LCD_clear_screen();
	//#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	//#endif
	//#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	//LCD_WRITE_COMMAND(0x02);
	//LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	//#endif

}

void LCD_check_lcd_isbusy(){
	//set the all port A asinput to be ab;e to take data from it and then check if busy..
	//DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	pinCfg.GPIO_PinNumber=GPIO_PIN_0;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_1;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_2;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_3;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_4;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_5;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_6;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	pinCfg.GPIO_PinNumber=GPIO_PIN_7;
	pinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &pinCfg);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	//LCD_CTRL |= (1 << RW_SWITCH);
	//LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
	//DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	//LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);


}

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	//LCD_CTRL |= (1 << EN_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	my_wait(50);
	//LCD_CTRL &= ~(1 << EN_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}


void LCD_WRITE_COMMAND(unsigned char command){
	//#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	//LCD_PORT = command;
	MCAL_GPIO_WritePort(LCD_CTRL, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);

	//LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	my_wait(1);
	LCD_lcd_kick();
	//#endif
	/*#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_lcd_kick ();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	LCD_lcd_kick();
#endif
}*/
}

void LCD_WRITE_CHAR(unsigned char character){
	//#ifdef EIGHT_BIT_MODE
	//LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(LCD_CTRL, character);
	// LCD_PORT 	= character;
	//LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL,RW_SWITCH,GPIO_PIN_RESET);
	//LCD_CTRL |= (1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL,RS_SWITCH,GPIO_PIN_SET);
	my_wait(1);

	LCD_lcd_kick();
	//#endif
	/*#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick();
	LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
	LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	LCD_lcd_kick ();
#endif*/
}



void LCD_WRITE_STRING(char* string)
{
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}

