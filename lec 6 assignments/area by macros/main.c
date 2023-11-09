#include <stdio.h>
#include <stdlib.h>
#define pi3.1415
#define area(r)(PI*(r)*(r))
int main()
{
    int radius;
    float area;
    printf("enter radius:\n");
    scanf("%d",&radius);
    area=area(radius);
    printf("area=%.2f",area);
    return 0;
}
