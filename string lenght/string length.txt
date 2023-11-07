#include <stdio.h>
#include <stdlib.h>

int main()
{
   char c[100];
   int i=0,count=0;
   printf("enter a string:");
   scanf("%s",c);
   for(i=0;c[i]!='\0';i++)
    {
    count++;
   }
   printf("lenght is %d",count);
   return 0;
}
