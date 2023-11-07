#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int main()
{
  int n;
  printf("please enter a positive integer : \n");
  scanf("%d",&n);
  printf("factorial of %d is : %d\n",n,factorial(n));

return 0;
}
int factorial(int n)
{
    if(n!=1)
        return n*factorial(n-1);
}
