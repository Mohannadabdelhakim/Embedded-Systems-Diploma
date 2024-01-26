//startup.c---selim

#include <stdint.h>
extern int main(void);

void default_handler();
void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias ("default_handler")));
void H_Fault_Handler() __attribute__((weak, alias ("default_handler")));
void MM_fault_Handler() __attribute__((weak, alias ("default_handler")));
void Bus_fault() __attribute__((weak, alias ("default_handler")));
void Usage_fault() __attribute__((weak, alias ("default_handler")));

extern unsigned int _stack_top ;

uint32_t vectors[] __attribute__((section(".vectors"))) = {

	(uint32_t) &_stack_top ,
	(uint32_t) &Reset_Handler ,
	(uint32_t) &NMI_Handler ,
	(uint32_t) &H_Fault_Handler ,
	(uint32_t) &MM_fault_Handler ,
	(uint32_t) &Bus_fault ,
	(uint32_t) &Usage_fault ,
};

void default_handler()
{
	Reset_Handler();
}

extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler()
{
	//copy data section from flash to RAM
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;

	int i;
	for( i = 0; i < DATA_size ; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}

	//init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;

	P_dst = (unsigned char*)&_S_bss ;

	for( i = 0; i < bss_size ; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}

	//jump main()

	main();
}
