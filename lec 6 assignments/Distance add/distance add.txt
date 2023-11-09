#include <stdio.h>
#include <stdlib.h>
struct Scomplex
{
    float real;
    float imag;
};

struct Scomplex add(struct Scomplex c1,struct Scomplex c2);
int main()
{struct Scomplex v1,v2,sum;
    printf("please enter 1st complex number values:\n");
    scanf("%f%f",&v1.real,&v1.imag);
    printf("please enter 2nd complex number values:\n");
    scanf("%f%f",&v2.real,&v2.imag);
   sum= add(v1,v2);
   printf("sum= %.2f+j%.2f",sum.real,sum.imag);
    return 0;
}
struct Scomplex add(struct Scomplex c1,struct Scomplex c2)
{
    struct Scomplex sum;
    sum.real=c1.real+c2.real;
    sum.imag=c1.imag+c2.imag;
    return sum;
};
