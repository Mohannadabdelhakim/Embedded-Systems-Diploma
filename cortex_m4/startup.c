//learn_in_depth_cortex_m3
//Mohannad Abd elhakim

#include <stdint.h>

extern int main(void);
extern unsigned int _stack_top;
void Reset_Handler (void) ;

void Default_Handler()
{
	Reset_Handler() ;
}

void NMI_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;

//booking 1024 B by .bss section to assign SP at its end after 1024 B
static unsigned long Stack_top[256] ;

void (* const g_p_fn_vectors[])() __attribute__ ((section(".vectors"))) =
{
(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),
&Reset_Handler,
&NMI_Handler,
&H_fault_Handler
};

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _E_text;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler(void)
{
	int i;

	//copy data section form flash to sram
	
	unsigned char DATA_size=(unsigned char*)&_E_data  - (unsigned char*)&_S_data ;
	unsigned char* P_SRC = (unsigned char*)&_E_text;
	unsigned char* P_DST = (unsigned char*)&_S_data;
	for(i=0;i<DATA_size;i++)
	{
		*((unsigned char*)P_DST++)=*((unsigned char*)P_SRC++);
	}

	//init bss and intialize by 0 

	unsigned char BSS_size=(unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_DST = (unsigned char*)&_S_bss;
	for (i=0 ; i<BSS_size ; i++)
	{
		*((unsigned char*)P_DST++)= 0 ;

	}

	//jump to main

	main();
}