#include <stdio.h>

int main()
{
   char c[1000],ch;
   int count=0,i;
   printf("enter a string:");
   gets(c);
   printf("enter the character to find its freq: ");
   scanf("%c",&ch);

    for(i=0;c[i]!='\0';i++)
     {
    if(ch==c[i])
        count ++;
    }
   printf("frequency of %c is %d \n",ch,count);
}
