/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

typedef volatile unsigned int vuint32_t;

#include <stdint.h>

//RCC
#define RCC_Base    0x40021000
#define RCC_APB2ENR *(vuint32_t *)( RCC_Base + 0x18)
#define RCC_IOPAEN  (1<<2)
#define RCC_IOPBEN  (1<<3)


//GPIO
#define GPIOA_Base 0x40010800
#define GPIOA_CRH  *(vuint32_t *)(GPIOA_Base + 0x04)
#define GPIOA_ODR  *(vuint32_t *)(GPIOA_Base + 0x0C)
#define GPIOA_CRL  *(vuint32_t *)(GPIOA_Base + 0x00)
#define GPIOA_IDR  *(vuint32_t *)(GPIOA_Base + 0x08)

#define GPIOB_Base 0x40010C00
#define GPIOB_CRH  *(vuint32_t *)(GPIOB_Base + 0x04)
#define GPIOB_ODR  *(vuint32_t *)(GPIOB_Base + 0x0C)
#define GPIOB_CRL  *(vuint32_t *)(GPIOB_Base + 0x00)
#define GPIOB_IDR  *(vuint32_t *)(GPIOB_Base + 0x08)

void clock_init(void)
{
	//enable clock GPOIA
	RCC_APB2ENR |= RCC_IOPAEN;
	RCC_APB2ENR |= RCC_IOPBEN;

}

void GPIO_init()
{
	GPIOA_CRL = 0;
	//GPIOB_CRL = 0;
	GPIOA_CRH = 0;
	//GPIOB_CRH = 0;
	GPIOA_ODR =0;

  //PA1 floating input:
	GPIOA_CRL &= ~(0b11<<4); //00: Input mode (reset state)
	GPIOA_CRL |=  (0b01<<6); //01: Floating input (reset state)
  //PB1 output push-pull mode:
    GPIOB_CRL |=  (0b01<<4); //01: Output mode, max speed 10 MHz
    GPIOB_CRL &= ~(0b11<<6); //00: General purpose output push-pull

  //PA13 floating input:
    GPIOA_CRH &= ~(0b11<<20); //00: Input mode (reset state)
    GPIOA_CRH |=  (0b01<<22); //01: Floating input (reset state)
  //PB13 output push-pull mode:
    GPIOB_CRH |=  (0b01<<20); //01: Output mode, max speed 10 MHz
    GPIOB_CRH &= ~(0b11<<22); //00: General purpose output push-pull
}
void wait(int x)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<1000;j++);
	}
}
int main(void)
{
	clock_init();
	GPIO_init();
	while(1)
	{
		//PA1 connected external PUR
		if(( (GPIOA_IDR &(1<<1)) >>1)==0)
		{
			GPIOB_ODR ^=(1<<1);
			while(( (GPIOA_IDR &(1<<1)) >>1)==0); //single pressing
		}

		//PA13 connected external PDR
		if(( (GPIOA_IDR &(1<<13)) >>13)==1)
		{
			GPIOB_ODR ^=(1<<13); //multi pressing
		}
        wait(1);
	}
}


