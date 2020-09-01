#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[100];
char str2[300];
char *p,*q;
char tmp[20];
char peekt[20];

struct first
{
    char terminal;
    char nonterminal[30];
};

int main()
{
    q = str2;
    scanf("%[^'\0']", str2);
    while (*q!= '\0')
    {
        printf("%c",*q);
        q++;
    }

    return 0;
}