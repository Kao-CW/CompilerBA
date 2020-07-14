#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[100];
char str2[100];
char *p,*q;
char tmp[20];
char peekt[20];
char *fun(char *str);
void *peek(char *str);

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
    
    q=fun(q);
    printf("%s\n",tmp);
    printf("%c\n",*q);
    peek(q);
    printf("q=%c\n",*q);
    printf("%s\n",peekt);
    printf("------------------------\n");

    

    return 0;
}
char *fun(char *str){
    int i = 0;
    memset(tmp, '\0', 10);
    while (*str!= '\n')
    {
        tmp[i]= *str;
        str++;
        i++;
    }
    str++;
    return str;
}

void *peek(char *str){
    memset(peekt, '\0', 10);
    char *p;
    p = str;
    int i = 0;
    while (*p != '\n')
    {
        peekt[i]= *p;
        p++;
        i++;
    }
    printf("str=%c\n", *q);
    q++;
    printf("str=%c\n", *q);
    q++;
    printf("str=%c\n", *q);
    q++;
    q++;
}
