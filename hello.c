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
int checkgm(bool a1,/* bool a2,*/ bool a3);
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
            /*str--;
            if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')||(*str >= '0' && *str <= '9')||(*str=='_'))
            {
                str++;
                checkBR = false;
                addtoken("LBR ");
                add(str);
                addn();
            }
            else
            {
                invaildinput();
            }*/
        }
        else if (*str == ')')
        {
            addtoken("RBR ");
            add(str);
            addn();
            /*
            if(!checkBR)
            {
                checkBR = true;
                addtoken("RBR ");
                add(str);
                addn();
            }
            else
            {
                printf("case RBR\n");
                invaildinput();
            }
            */
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
            //str=casesemi(str);           
        }
        else if (*str=='\n')
        {
            /*str--;
            if (*str != ';')
            {
                printf("case newline\n");
                invaildinput();
            }*/
            //printf("after n str=%c\n", *str);
            //str++;
            //printf("after n str++=%c\n", *str);
        }
        else if (*str==' ')
        {
            str++;
        }
        else
        {
            //printf("case else\n");           
            //printf("str=%c \n", *str);
            str--;
            //printf("str--=%c \n", *str);
            invaildinput();
        }
        str++;
    }
    /*printf("1---%c\n", *str);
    str--;
    printf("2---%c\n", *str);
    str--;
    printf("3---%c\n", *str);
    if (*str!= ';')
    {
        printf("case finalsemi\n");
        printf("%c", *str);
        invaildinput();
    }*/
    str++;
    return str;
}

char *caseid(char *str)//ok
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

char *casesemi(char *str)//ok
{
    str++;
    if(*str=='\n'||*str=='\0'||*str==EOF)
    {
        checksemi = true;
    }
    else
    {
        printf("case semi\n");
        invaildinput();
    }
    addtoken("SEMICOLON ");
    str--;
    add(str);
    addn();
    return str;
}

int invaildinput()//ok
{
    printf("invaild input\n");
    exit(1);
}

char *casestr(char *str)
{
    addtoken("STRLIT ");
    add(str);
    str++;
    while(*str!='"'^*str=='\0')//||*str=='\0'||*str==')'
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
        printf("case str\n");
        invaildinput();
    }
    addn();
    return str;
}

int checkgm(bool a1,/*bool a2,*/bool a3)

{
    if(a1==true&&/*a2==true&&*/a3==true)
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
    /*FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");
    while((s[i]=fgetc(fp))!=EOF)
    {
        i++;
    }*/
    scanf("%[^\0]", s);
    char *p =s;
    scanner(p);
    if(checkgm(checkBR,/* checksemi,*/ checkstr))
    {
        final_print();
    }
    else
    {
        printf("%d\n", checkBR);
        printf("%d\n", checkstr);
        printf("%d\n", checksemi);
        printf("final");
        printf("invaild input\n");
    }
    return 0;
}