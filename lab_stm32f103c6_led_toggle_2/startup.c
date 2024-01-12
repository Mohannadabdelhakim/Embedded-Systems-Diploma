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
void MM_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;
void Bus_fault(void) __attribute__ ((weak,alias("Default_Handler")));;
void Usage_fault_Handler(void) __attribute__ ((weak,alias("Default_Handler")));;

uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_Handler
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