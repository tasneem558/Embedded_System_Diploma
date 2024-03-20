/*startup.c
Eng.tasneem
*/

#include <stdint.h>
extern int main();
void Reset_Handler();

void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;
void MM_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;
void Bus_Handler() __attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;

extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Handler,
	(uint32_t) &Usage_Fault_Handler
};
extern unsigned int  E_text;
extern unsigned int _S_Data;
extern unsigned int _E_Data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_Handler()
{
	//copy data from Rom to RAM
	unsigned int Data_size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data;
	unsigned char* P_src = (unsigned char*)&E_text;
	unsigned char* P_dst = (unsigned char*)&_S_Data;
	for(int i=0; i < Data_size; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	//init the .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(int i=0; i <bss_size; i++)
	{
		*((unsigned char*)P_dst++) =(unsigned char)0;
	}

   main();
}