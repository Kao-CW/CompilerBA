#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int i = 0;
char s[100];
char pr[100];
char *prp=pr;
bool checksemi = false;
bool checkBR = true;
bool checkstr = true;
char *scanner(char *str);
char *caseid(char *str);
char *casesemi(char *str);
int invaildinput();
char *casestr(char *str);
int checkgm(bool a1, bool a2, bool a3);
void add(char *str);
void addn();
void final_print();

char *scanner(char* str)
{
    while (*str != EOF)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            str=caseid(str);
            //printf("after caseid str point to: %c\n", *str);
        }
        else if (*str == '.')
        {
            add(str);
            addn();
            printf("DOT . \n");
        }
        else if (*str == '(')
        {
            str--;
            if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9'))
            {
                str++;
                checkBR = false;
                add(str);
                addn();
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
                add(str);
                addn();
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
            //printf("after casestr str point to: %c\n", *str);
        }
        else if (*str == ';')
        {
            //printf("before casesemi str point to: %c\n", *str);
            str=casesemi(str);
            
        }
        else
        {
            invaildinput();
        }
       
        //printf("%d\n", cnt);
        str++;
    }
    return str;
}

char *caseid(char *str)//ok
{
    strcat(prp, "ID");
    

    while((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9')||*str=='_')
    {
        printf("%c ", *str);
        add(str);
        str++;       
    }
    printf("\n----ID---- \n");
    addn();
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
    add(str);
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
        add(str);
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
    addn();
    return str;
}

int checkgm(bool a1,bool a2,bool a3)

{
    if(a1==true&&a2==true&&a3==true)
    {
        return 1;
    }
    return 0;
}

void add(char *str)
{
    *prp=*str;
    prp++;
}

void addn()
{
    *prp = '\n';
    prp++;
}

void final_print()
{
    char *tmp = pr;
    while(*tmp!='\0')
    {
        printf("%c", *tmp);
        tmp++;
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
    printf("---------------final--------------------\n");
    final_print();
    /*if(checkgm(checkBR, checksemi, checkstr))
    {
        final_print();
    }
    else
    {
        printf("invaild input\n");
    }*/
    return 0;
}