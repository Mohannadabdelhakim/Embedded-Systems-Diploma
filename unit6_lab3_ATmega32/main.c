/*
 * main.c
 *
 * Created: 3/7/2024 9:21:25 AM
 *  Author: Mohannad Abd Elhakim
 */ 
#define F_CPU  8000000UL

#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>


#define SET_BIT(ADDRESS,BIT) ADDRESS |=(1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &=~ (1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS &=(1<<BIT)>>BIT)

//IO 
#define IO_BASE 0x20
#define PORTD   *(volatile uint32_t *) (IO_BASE + 0x12)
#define DDRD   *(volatile uint32_t *) (IO_BASE + 0x11)
#define INT_GICR   *(volatile uint32_t *) (IO_BASE + 0x3B)
#define INT_MCUCR   *(volatile uint32_t *) (IO_BASE + 0x35)
#define INT_MCUCSR  *(volatile uint32_t *) (IO_BASE + 0x34)



int main(void)
{
	//allow PIN(5,6,7) as output in Port D(initially PIN=0)
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);

	//set MCUCR
	//set INT 0 Logical
	SET_BIT(INT_MCUCR,0);
	RESET_BIT(INT_MCUCR,1);
	//set INT 1 Rising EDGE
	SET_BIT(INT_MCUCR,2);
	SET_BIT(INT_MCUCR,3);

	//set MCUCSR
	//SET INT 2 Falling Edge
	RESET_BIT(INT_MCUCSR,6);

	//set GICR for INT(0,1,2)
	SET_BIT(INT_GICR,5);
	SET_BIT(INT_GICR,6);
	SET_BIT(INT_GICR,7);

//enable status register
	sei();
	while(1)
	{
		RESET_BIT(PORTD,5);
		RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);

	}
}

ISR(INT0_vect){
	SET_BIT(PORTD,5);
	_delay_ms(100);
}

ISR(INT1_vect){
	SET_BIT(PORTD,6);
	_delay_ms(100);
}

ISR(INT2_vect){
	SET_BIT(PORTD,7);
	_delay_ms(100);
}