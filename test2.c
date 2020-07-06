#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char s[100];
char pr[100];
int prp = 0;
char *p,*q;
int i = 0;
char *fun(char *p,int prp);

int main()
{
    FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");
    while((s[i]=fgetc(fp))!=EOF)
    {
        i++;
    }
    char *p =s;
    /*while(*p!='\0')
    {
        printf("%c", *p);
        p++;
    }*/
    fun(p,prp);
    /*pr[0] ='0';
    pr[1]='a';
    printf("\n%c\n", pr[0]);
    printf("%c\n", pr[1]);*/

    //q = pr;
    printf("111111\n");
    printf("%c", pr[0]);
    printf("%c", pr[1]);
    printf("%c", pr[2]);
    printf("%c", pr[3]);
    printf("%c", pr[4]);

    return 0;
}
char *fun(char *p,int prp)
{
    printf("\nprp=%d\n", prp);
    printf("*p=%c\n", *p);
    while(*p!='\0')
    {
        pr[prp] = *p;
        printf("pr[ %d ] = %c \n", prp, pr[prp]);
        prp++;
        p++;
    }
    pr[prp] = *p;
    printf("pr[ %d ] = %c \n", prp, pr[prp]);
    /*prp++;
    printf("\nprp++1: %d", prp);
    p++;
    s[prp] ='1';
    prp++;
    printf("\nprp++2: %d", prp);*/
    
    return p;
}
