/*
 * Map_Memory.h
 *
 * Created: 5/14/2024 3:32:44 AM
 *  Author: tasneem
 */ 


#ifndef MAP_MEMORY_H_
#define MAP_MEMORY_H_

#define DDRA (*(volatile unsigned char*)0x3B)
#define PORTA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

#define DDRC (*(volatile unsigned char*)0x34)
#define PORTC (*(volatile unsigned char*)0x35)
#define PINC (*(volatile unsigned char*)0x33)


#endif /* MAP_MEMORY_H_ */