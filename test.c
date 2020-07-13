#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[100];
char str2[100];
char *p,*q;
char tmp[10];
char* fun(char *str);

int main()
{
    q = str2;
    scanf("%[^\0]", str2);
    while (*q!= '\0')
    {
        printf("%c",*q);
        q++;
    }
    q= str2;
    printf("\n------------------------\n");
    tmp=fun(q);
    q++;
    printf("%s\n",tmp);
    tmp=fun(q);
    printf("%s\n",tmp);
    tmp=fun(q);
    printf("%s\n",tmp);
    tmp=fun(q);
    printf("%s\n",tmp);


    return 0;
}
char* fun(char *str){
    int i = 0;
    char p[10];
    char *t = p;
    while (*str!= '\n')
    {
        p[i]= *str;
        str++;
        i++;
    }
    str++;
    return t;
}


