#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:<tasneem>";
unsigned char const string_buffer_2[100]="to create a rodata section";
void main(void)
{
	uart_send_strig(string_buffer);
}