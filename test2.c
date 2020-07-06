#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char s[100];
char pr[100];
int prp = 0;
char *p;
int i = 0;
char *fun(char *s);

int main()
{
    FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");
    while((s[i]=fgetc(fp))!=EOF)
    {
        i++;
    }
    char *p =s;
    while(*p!='\0')
    {
        printf("%c", *p);
        p++;
    }

    return 0;
}

char *fun(char *s)
{

}