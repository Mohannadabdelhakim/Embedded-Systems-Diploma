#include <stdio.h>
#include <stdlib.h>

int main()
{

   int num,i,location,element;
   printf("please enter the number of array elements \n");
   scanf("%d",&num);

   int arr[num];

   printf("please enter the array elements: \n");
   for(i=0;i<num;i++)
    {
    scanf("%d",&arr[i]);
   }

     printf("please enter the element to be inserted \n");
     scanf("%d",&element);

     printf("please enter the location \n");
     scanf("%d",&location);

     for(i=num;i>=location;i--)
     {
         arr[i]=arr[i-1];
     }
     num++;
     arr[location-1]=element;
     for(i=0;i<num;i++)
     {
    printf("\n %d  ",arr[i]);
     }
    return 0;
}
