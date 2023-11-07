#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x=0,y=0,z=0;
    printf("please enter three numbers : \n");
    scanf("%f %f %f",&x,&y,&z);
   if(x>y&&x>z)
   {
       printf("%f is the largest number",x);
   }
   else if (y>x&&y>z)
   {
     printf("%f is the largest number",y);
   }
   else
   {
        printf("%f is the largest number",z);

   }
    }

