#include <stdio.h>
#include <stdlib.h>

int power(int x,int y);
int main()
{
    int result;
    int x,y;
    printf("please enter the base number: ");
    scanf("%d",&x);
    printf("please enter the power number: ");
    scanf("%d",&y);
    power(x,y);
    printf("%d ^ %d=%d",x,y,power(x,y));

    return 0;
}
int power(int x,int y)
{int result;
    if(y!=0)
    {
        return x*power(x,y-1);
    }
    else
    return 1;
}
