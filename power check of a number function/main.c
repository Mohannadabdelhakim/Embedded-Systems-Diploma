#include <stdio.h>
#include <stdlib.h>

int power_check3(int x);
int main()
{
  int x;
  printf("please enter the base number \n");
  scanf("%d",&x);
  power_check3(x)?printf("0\n"):printf("1\n");

}
int power_check3(int x)
{
double i=log(x)/log(3);

    return i==trunc(i);
}
