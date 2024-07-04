/*
 * keybad.c
 *
 * Created: 5/21/2024 4:46:50 AM
 *  Author: tasneem
 */ 
#include "keybad.h"

int keypad_R[4] = {R0,R1,R2,R3};
int keypad_C[4] = {C0,C1,C2,C3};

void KEYBAD_INIT()
{
	DATADir_KEYPAD_PORT &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	DATADir_KEYPAD_PORT |=  ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	KEYPAD_PORT = 0xFF;
}
char KEYPAD_GETCHAR()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		KEYPAD_PORT |= ((1<<keypad_C[0]) | (keypad_C[1]) | (keypad_C[2]) | (keypad_C[3]));
		KEYPAD_PORT &= ~(1<<keypad_C[i]);
		for(j=0;j<4;j++)
		{
			if(!(KEYPAD_PIN & (1<<keypad_R[i])))
			     while(!(KEYPAD_PIN & (1<<keypad_R[i])));
				 switch(i)
				 {
					 case(0):
					 {
						 if      (j==0) return '7';
						 else if (j==1) return '4';
						 else if (j==2) return '1';
						 else if (j==1) return '!';
						 break;
					 }
					 case(1):
					 {
						 if      (j==0) return '8';
						 else if (j==1) return '5';
						 else if (j==2) return '2';
						 else if (j==1) return '0';
						 break;
					 }
					 case(2):
					 {
						 if      (j==0) return '9';
						 else if (j==1) return '6';
						 else if (j==2) return '3';
						 else if (j==1) return '=';
						 break;
					 }
					 case(3):
					 {
						 if      (j==0) return '/';
						 else if (j==1) return '*';
						 else if (j==2) return '-';
						 else if (j==1) return '+';
						 break;
					 }
					 
				 }
			
		}
	}
	return 'N';
}