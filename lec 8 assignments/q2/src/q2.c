/*
 ============================================================================
 Name        : q2.c
 Author      : Mohannad Abd Elhakim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char alph[27];
	int i=0;
	printf("the alphabets are :\n");
	printf("-------------------");
	char *ptr=alph;
	for(i=0;i<26;i++)
	{
		*ptr=i+'A';
		ptr++;
	}
	ptr=alph;

	printf("\n\n printing the alphabets: \n");
	for(i=0;i<26;i++)
	{
		printf("%c",*ptr);
		ptr++;
		printf("  ");

	}
	printf("\n\n");
	return 0;
}
