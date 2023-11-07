#include <stdio.h>
#include <stdlib.h>

int prime_check(int num);
int main()
{
    int i,flag;
    int n1,n2;
    printf("please enter the two numbers intervals : \n");
    scanf("%d %d",&n1,&n2);
    printf("prime numbers are: ");
    for(i=n1+1;i<n2;i++)                   //i=n1+1 to start counting from the no after 10
    {
    flag=prime_check(i);                   //flag=prime_check(i) to check with the iterative value i inside the function
    if (flag==1)
        printf("%d ",i);
    }
    return 0;
}
int prime_check(int num)
{
    int j=2,flag=1;        //j=2 so it skips 0 and 1
    for(j=2;j<num/2;j++)     //j<num/2 so it checks only the first half as in if n1+1=11 so j checks 11/2,11/3,11/4,11/5 which all have decimals
    {
        if(num%j==0)
        {
            flag=0;
            break;
        }
    }
return flag;

}
