#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int i = 0;
int cnt = 0;
int flag2 = 0;
char s[100];
char pr[100];
int prp = 0;
bool checksemi = false;
bool checkBR = true;
bool checkstr = true;
char *scanner(char *str);
char *caseid(char *str);
char *casesemi(char *str);
int invaildinput();
char *casestr(char *str);
int checkgm(bool a1, bool a2, bool a3);

char *scanner(char* str)
{
    while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            str=caseid(str);
            //printf("after caseid str point to: %c\n", *str);
        }
        else if (*str == '.')
        {
            printf("DOT . \n");
        }
        else if (*str == '(')
        {
            str--;
            if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9'))
            {
                str++;
                checkBR = false;
                printf("LBR ( \n");
            }
            else
            {
                invaildinput();
            }
        }
        else if (*str == ')')
        {
            if(!checkBR)
            {
                checkBR = true;
                printf("RBR ) \n");
            }
            else
            {
                invaildinput();
            }
        }
        else if (*str == '"')
        {
            checkstr = false;
            str=casestr(str);
            printf("after casestr str point to: %c\n", *str);
        }
        else if (*str == ';')
        {
            printf("before casesemi str point to: %c\n", *str);
            str=casesemi(str);
            
        }
        else
        {
            invaildinput();
        }
        cnt++;
        //printf("%d\n", cnt);
        str++;
    }
    return str;
}

char *caseid(char *str)//ok
{

    while((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9')||*str=='_')
    {
        printf("%c ", *str);
        str++;       
    }
    printf("\n----ID---- \n");
    str--;
    return str;
}

char *casesemi(char *str)//ok
{
    str++;
    if(*str=='\n'||*str=='\0'||*str==EOF)
    {
        checksemi = true;
    }
    else
    {
        printf("casesemi\n");
        invaildinput();
    }
    printf("SEMICOLON ; \n");
    str--;
    return str;
}

int invaildinput()//ok
{
    printf("invaild input\n");
    exit(1);
}

char *casestr(char *str)
{
    str++;
    while(*str!='"')//||*str!='\0'||*str!=')'
    {
        printf("%c ", *str);
        str++; 
    }
    if(*str=='"')
    {
        checkstr = true;
        printf("\n STRLIT \n");
    }
    else
    {
        printf("casestr");
        invaildinput();
    }
    return str;
}

int checkgm(bool a1,bool a2,bool a3)
{
    if(a1==true&&a2==true&&a3==true)
    {
        return 1;
    }
}

int main()
{
    FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");
    while((s[i]=fgetc(fp))!=EOF)
    {
        i++;
    }
    char *p =s;
    scanner(p);
    if(checkgm(checkBR, checksemi, checkstr))
    {

    }
    return 0;
}