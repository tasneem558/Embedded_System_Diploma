/*
 ============================================================================
 Name        : EX3_less6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct  SComplex
{
	float real_num;
	float img_num;
}x,y,s;

struct SComplex Read_number();
struct SComplex add(struct  SComplex x,struct  SComplex y);
void print_summtion(struct SComplex sum);

int main()
{
	printf("For 1st complex number \n");
	x=Read_number();
	printf("For 2nd complex number \n");
	y=Read_number();
	s=add(x,y);
	print_summtion(s);
}

struct SComplex Read_number()
{
	struct  SComplex num;
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num.real_num,&num.img_num);
	return num;
}

struct SComplex add(struct  SComplex x,struct  SComplex y)
{
	struct SComplex sum;
	sum.real_num=x.real_num +y.real_num;
	sum.img_num=x.img_num+y.img_num;
	return sum;
}

void print_summtion(struct SComplex sum)
{
	printf("Sum=%0.1f+%0.1fi",sum.real_num,sum.img_num);
}
