#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[10];
    int i=0,n=0;
    char *ptr=arr;
    printf("please enter the number of array elements\n");
    scanf("%d",&n);
    printf("input the number of elements in the array \n");
    for(i=0;i<n;i++)
    {
        printf("element no %d is: ",i+1);
        scanf("%d",ptr);
        ptr++;
    }
    ptr=arr;
    printf("for printing numbers in the normal order \n");
    for(i=0;i<n;i++)
    {
        printf("element no %d is:%d \n",i+1,*ptr);
        ptr++;
    }
    printf("for printing reversed order\n");
    ptr=&arr[n-1];
    for(i=n;i>0;i--)
    {
        printf("element no %d is:%d \n",i+1,*ptr);
        ptr--;
    }
    return 0;
}
