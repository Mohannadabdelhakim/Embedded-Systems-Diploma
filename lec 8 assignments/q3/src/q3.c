/*
 ============================================================================
 Name        : q3.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i=-1;
	char arr[30];
	char rarr[30];
	char*ptr=arr;
	char*rptr=rarr;
	printf("Pointer : print a string in reverse order: \n");
	printf("--------------------------------\n");
	printf("Input a string \n");
	scanf("%s",arr);
	while(*ptr)
	{
		ptr++;
		i++;
	}

	while(i>=0)
	{
	     ptr--;
         *rptr=*ptr;
         rptr++;
         --i;
	}
	*rptr='\0';
	printf("reversed string : %s \n",rarr);
return 0;
}
