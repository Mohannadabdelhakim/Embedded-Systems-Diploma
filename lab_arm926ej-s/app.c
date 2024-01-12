
#include "uart.h"
unsigned char string_buffer[100] = "learn in depth_mohannad abd elhakim" ;
unsigned char const string_buffer2[100] = "learn in depth_mohannad abd elhakim" ;
unsigned char const string_buffer3[100] = "learn in depth_mohannad abd elhakim" ;

void main(void)
{
	uart_send_string(string_buffer) ;
}
