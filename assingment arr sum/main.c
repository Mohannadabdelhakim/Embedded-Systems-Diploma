#include <stdio.h>
#include <stdlib.h>

int main()
{
   float a1[2][2];
   float a2[2][2];
   float sum[2][2];
   int r,c;

   for(r=0;r<2;r++)
   {
       for(c=0;c<2;c++)
       {
       printf("enter the value of %d %d \n",r,c);
       scanf("%f",&a1[r][c]);
       }
   }


    for(r=0;r<2;r++)
   {
       for(c=0;c<2;c++)
       {
       printf("enter the value of %d %d \n",r,c);
       scanf("%f",&a2[r][c]);
       }
   }
   printf("the matrix a1 is: \n");
  for(r=0;r<2;r++)
   {
       for(c=0;c<2;c++)
       {
       printf("%f \t",a1[r][c]);
       }
    printf("\n \r");
   }
   printf("the matrix a2 is: \n");
  for(r=0;r<2;r++)
   {
       for(c=0;c<2;c++)
       {
       printf("%f \t",a2[r][c]);
       }
              printf("\n \r");

   }

for(r=0;r<2;r++)
{
    for(c=0;c<2;c++){
           sum[r][c]=a1[r][c]+a2[r][c];
}
}
   printf(" the sum is : \n");

   for(r=0;r<2;r++)
   {
       for(c=0;c<2;c++)
       {
       printf("%f \t",sum[r][c]);
       }

              printf("\n \r");
   }
}
