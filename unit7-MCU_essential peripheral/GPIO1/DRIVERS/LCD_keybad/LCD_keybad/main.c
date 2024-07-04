/*
 * LCD_keybad.c
 *
 * Created: 5/17/2024 9:33:53 AM
 * Author : tasneem
 */ 

#include <avr/io.h>
#include "LCD_driver/lcd.h"
#include "keybad_driver/keybad.h"
int main(void)
{
    /* Replace with your application code */
	LCD_INIT();
	KEYBAD_INIT();
	char pressed_key;
    while (1) 
    {
		pressed_key = KEYPAD_GETCHAR();
		switch(pressed_key)
		{
			case('!'):
			    LCD_clear_screen();
			    break;
			case('N'):
			    break;
			default:
			    LCD_WRITE_CHAR(pressed_key);
				break;
        }
	}
}

