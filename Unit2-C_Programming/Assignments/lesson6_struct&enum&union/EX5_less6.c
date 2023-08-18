/*
 ============================================================================
 Name        : EX5_less6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define AREA_OF_CIRCLE(radius) (PI * (radius) * (radius))

int main() {
    int radius;
    printf("Enter the radius: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &radius);

    double area = AREA_OF_CIRCLE(radius);

    printf("Area=%.2lf", area);

    return 0;
}
