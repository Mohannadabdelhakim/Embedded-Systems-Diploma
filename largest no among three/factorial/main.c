#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i=0,n;
   float factorial=1;
   printf("please enter a whole number \n");
   scanf("%d",&n);
   if(n<0)
   {
       printf("error \!");
   }
else
    {
    for (i=1;i<=n;i++)
    {
            factorial*=i;

    }
    printf("factorial= %f",factorial);
    }
    return 0;
       }
