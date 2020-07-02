#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int cnt = 0;
int flag2 = 0;
char s[100];
bool checksemi = false;
bool checkBR = true;
bool checkstr = true;
char *scanner(char *str);
char *caseid(char *str);
char *casesemi(char *str);
int invaildinput();
char *casestr(char *str);

char *scanner(char* str)
{
    while (*str != '\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            str=caseid(str);
            printf("after caseid str point to: %c\n", *str);
        }
        else if (*str == '.')
        {
            printf("DOT . \n");
        }
        else if (*str == '(')
        {
            str--;
            if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9')||*str=='_')
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
            casestr(str);
        }
        else if (*str == ';')
        {
            str=casesemi(str);
            printf("after casesemi str point to: %c\n", *str);
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
    printf("\n id \n");
    str--;
    return str;
}

char *casesemi(char *str)//ok
{
    str++;
    if(*str=='\n'||*str=='\0')
    {
        checksemi = true;
    }
    else
    {
        printf("casesemi\n");
        invaildinput();
    }
    printf("SEMICOLON ; \n");
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
    while(*str!='"'||*str!='\0')
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
    str--;
    return str;
}

int main()
{
    char *s = "str.length";
    scanner(s);
    return 0;
}