#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("please enter a letter \n");
    scanf(" %c",&c);
    if(c=='i'||c=='e'||c=='o'||c=='u'||c=='a'||c=='I'||c=='E'||c=='O'||c=='U'||c=='A')
    {
        printf("\n the letter you entered is a vowel");
    }
    else
    {
        printf("\n the letter you entered is a consonant");

    }
    return 0;
}
