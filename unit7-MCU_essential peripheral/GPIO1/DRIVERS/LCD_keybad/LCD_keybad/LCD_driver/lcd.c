/*
 * lcd.c
 *
 * Created: 5/17/2024 9:39:49 AM
 *  Author: tasneem
 */ 

#include "lcd.h"
void LCD_KICK(void)
{
	LCD_CTRL&=~(1<ENABLE_SWITCH);
	_delay_ms(50);
	LCD_CTRL|=(1<ENABLE_SWITCH);
}
void LCD_GOTO_XY(int line,int position)
{
	if(line ==1)
	{
		if(position >=0 && position <16)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
		
	}
	else if(line==2)
	{
		if(position >=0 && position <32)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}	
	}
}
void LCD_isbusy(void)
{
	#ifdef EIGHT_BIT_MODE
	DataDir_LCD_CTRL =0X00; //with all 8bits
	#endif
	
	#ifdef FOUR_BIT_MODE
	DataDir_LCD_CTRL &= ~(0xFF<<DATA_SHFT); //WITH ONLY 4BITS
    #endif
	
	LCD_CTRL |=(1<<RW_SWITCH); //READ MODE
	LCD_CTRL&=~(1<RS_SWITCH);
	LCD_KICK();
	DataDir_LCD_PORT = 0XFF;
	LCD_CTRL &= ~(1<<RW_SWITCH);
}
void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
	
}
void LCD_INIT(void)
{
	_delay_ms(25);
	LCD_isbusy();
	DataDir_LCD_CTRL |=(1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH);
	LCD_CTRL &= ~(1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH);
	DataDir_LCD_PORT =0xFF;
	LCD_clear_screen();
	
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_WRITE_COMMAND(0X02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}
void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_isbusy();
	#ifdef EIGHT_BIT_MODE
	LCD_PORT = command;
	LCD_CTRL &= ~(1<<RW_SWITCH)| (1<<RS_SWITCH);
	LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
	LCD_CTRL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH));
	_delay_ms(1);
	LCD_KICK();
	#endif
	
}
void LCD_WRITE_CHAR(unsigned char data)
{
	LCD_isbusy();
	
	#ifdef EIGHT_BIT_MODE
	LCD_CTRL |=(RS_SWITCH);
	LCD_PORT = data;
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |=(RS_SWITCH);
	LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_CTRL &= ~(1<<RW_SWITCH) ;
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	LCD_CTRL &= ~(1<<RW_SWITCH) ;
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_KICK();
	#endif
}
void LCD_WRITE_string( char* data)
{
	int count = 0;
	while(*data >0)
	{
		LCD_WRITE_CHAR(*data++);
		count++;
		if(count==16)
		{
			LCD_GOTO_XY(2,0);
		}
	else if (count==32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count=0;
		}
		
	}
}

