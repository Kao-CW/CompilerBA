#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void addtoken(char token[]);

int i = 0;
char s[100];
char pr[100];
char *prp=pr;
char *scanner(char *str);
char *caseid(char *str);
char *casesemi(char *str);
int invaildinput();
char *casestr(char *str);
void add(char *str);
void addn();
void addtoken(char token[]);
void final_print();
int main()
{
    char *id;
    id= "ID";
    int l = strlen(id);
    printf("%d", l);
    addtoken("ID");
    printf("%c", pr[0]);
    printf("%c", pr[1]);
    printf("%c\n", pr[2]);
    addtoken("dsdffasij");
    printf("%c", pr[0]);
    printf("%c", pr[1]);
    printf("%c", pr[2]);
    printf("%c", pr[3]);
    printf("%c", pr[4]);
    printf("%c", pr[5]);
    printf("%c", pr[6]);
}

void addtoken(char token[])
{
    char *tmp=token; 
    //printf("%c", *tmp);   
    strcat(prp, tmp);
    prp = prp + strlen(tmp);
}