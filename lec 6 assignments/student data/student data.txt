#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[100];
    int roll;
    float marks;
};
int main()
{
   struct Student s;
   //for data gathering
   printf("please enter the student's name\n");
   scanf("%s",s.name);
   printf("please enter the Roll number\n");
   scanf("%d",&s.roll);
   printf("please enter the student's mark\n");
   scanf("%f",&s.marks);
   //for data displaying
   printf("the student's data is: %s\t%d\t%.2f",s.name,s.roll,s.marks);
    return 0;
}
