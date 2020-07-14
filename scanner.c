#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int i = 0;
char s[100];
char pr[100];
char *prp=pr;
bool checkBR = true;
bool checkstr = true;
char *scanner(char *str);
char *caseid(char *str);
int invaildinput();
char *casestr(char *str);
int checkgm(bool a1,bool a3);
void add(char *str);
void addn();
void addtoken(char token[]);
void final_print();

char *scanner(char* str)
{
    while (*str !='\0')
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||*str=='_')
        {
            str=caseid(str);           
        }
        else if (*str == '.')
        {
            addtoken("DOT ");
            add(str);
            addn();
        }
        else if (*str == '(')
        {
            addtoken("LBR ");
            add(str);
            addn();
        }
        else if (*str == ')')
        {
            addtoken("RBR ");
            add(str);
            addn();
        }
        else if (*str == '"')
        {
            checkstr = false;
            str=casestr(str);
        }
        else if (*str == ';')
        {
            addtoken("SEMICOLON ");
            add(str);
            addn();        
        }
        else if (*str=='\n'){}
        else if (*str==' ')
        {
            str++;
        }
        else
        {
            str--;
            invaildinput();
        }
        str++;
    }
    str++;
    return str;
}

char *caseid(char *str)
{
    addtoken("ID ");
    while((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9')||*str=='_')
    {
        add(str);
        str++;       
    }
    addn();
    str--;
    return str;
}
int invaildinput()
{
    printf("invaild input\n");
    exit(1);
}

char *casestr(char *str)
{
    addtoken("STRLIT ");
    add(str);
    str++;
    while(*str!='"'^*str=='\0')
    {
        add(str);
        str++; 
    }
    if(*str=='"')
    {
        checkstr = true;
        add(str);
    }
    else
    {
        invaildinput();
    }
    addn();
    return str;
}

int checkgm(bool a1,bool a3)

{
    if(a1==true&&a3==true)
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
    char *tmp;
    tmp = pr;
    while(*tmp!='\0')
    {
        printf("%c", *tmp);
        tmp++;
    }
}

void addtoken(char token[])
{
    char *tmp=token; 
    strcat(prp, tmp);
    prp = prp + strlen(tmp);
}

int main()
{
    scanf("%[^\0]", s);
    char *p =s;
    scanner(p);
    if(checkgm(checkBR,checkstr))
    {
        final_print();
    }
    else
    {
        printf("invaild input\n");
    }
    return 0;
}