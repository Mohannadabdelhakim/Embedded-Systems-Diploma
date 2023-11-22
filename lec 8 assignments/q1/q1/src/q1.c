/*
 ============================================================================
 Name        : q1.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m=29;
	printf("address of m = %p\n",&m);
	printf("value of m = %d\n",m);
int* ab=&m;
printf("address of pointer = %p\n",ab);
printf("value of pointer ab = %d\n",*ab);
m=34;
printf("address of pointer = %p\n",ab);
printf("value of pointer ab = %d\n",*ab);
*ab=7;
printf("address of m = %p\n",ab);
printf("value of m = %d\n",*ab);
return 0;
}
