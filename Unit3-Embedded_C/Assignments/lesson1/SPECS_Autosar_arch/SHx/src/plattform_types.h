/*
 ============================================================================
 Name        : plattform_types.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#include <stdbool.h>


#ifndef _Bool
#define _Bool unsigned char
#endif


#define CPU_TYPE         CPU_TYPE_32
#define CPU_BIT_ORDER    LSB_FIRST
#define CPU_BYTE_ORDER   HIGH_BYTE_FIRST

#ifndef FALSE
#define FALSE            (boolean)false
#endif
#ifndef TRUE
#define TRUE             (boolean)true
#endif

typedef _Bool               boolean;
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed int          sint32;
typedef signed long long    sint64;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

typedef unsigned long       uint8_least;
typedef unsigned long       uint16_least;
typedef unsigned long       uint32_least;
typedef signed long         sint8_least;
typedef signed long         sint16_least;
typedef signed long         sint32_least;

typedef float               float32;
typedef double              float64;


#endif
