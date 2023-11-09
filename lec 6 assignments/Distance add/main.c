#include <stdio.h>
#include <stdlib.h>

struct Sdistance
{
    int feet;
    float inch;
}d1,d2,sum;
int main()
{
    printf("please enter the 1st distance data:\n");
    printf("enter in feet: \n");
    scanf("%d",&d1.feet);
    printf("enter in inch: ");
    scanf("%f",&d1.inch);

    printf("please enter the 2n2 distance data:\n");
    printf("enter in feet: \n");
    scanf("%d",&d2.feet);
    printf("enter in inch: \n");
    scanf("%f",&d2.inch);
   sum.feet=d1.feet+d2.feet;
   sum.inch=d1.inch+d2.inch;
   printf("Sum of distances = %d\'-%0.2f\"",sum.feet,sum.inch);
    return 0;
}
