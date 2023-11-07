#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,y,sum=0;
    printf("please enter the target number \n");
    scanf("%d",&y);
   for(i=1;i<=y;i++)
   {
       sum+=i;
   }
    printf("sum= %d",sum);
}
