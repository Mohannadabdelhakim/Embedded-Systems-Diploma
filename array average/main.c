#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    float arr[100];
    float sum=0;
    float average;


    printf("please enter the numbers of data \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter number %d: ",i);
        scanf("%f",&arr[n]);
        sum+=arr[n];
    }

    average=sum/n;
    printf("average = %0.2f",average);


    return 0;
}
