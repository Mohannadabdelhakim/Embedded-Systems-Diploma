#include <stdio.h>
#include <stdlib.h>

struct Students
{
    char name[50];
    int roll;
    int marks;
};

 int main()
{
    int i;
    struct Students S[10];
    printf("Enter info of students\n");
    for (i=0;i<10;i++)
    {
        S[i].roll=i+1;
        printf("For roll number %d:\n",S[i].roll);
        printf("enter name: ");
        scanf("%s",S[i].name);
        printf("Enter marks: ");
        scanf("%d",&S[i].marks);
        printf("\n");
    }
    printf("Displaying Students' info");
    for(i=0;i<10;i++)
    {
        S[i].roll=i+1;
        printf("Info of roll number %d:\n",S[i].roll);
        printf("name:%s\n",S[i].name);
        printf("Enter marks:%d\n",S[i].marks);
        printf("\n");
    }
    return 0;
}
