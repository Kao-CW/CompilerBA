#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

char *gettoken(char *str);
void program();
void stmts();
void stmt();
void expp();
void primary();
void primary_tail();
char *match(char *str,char *s);
void error();
void peek(char *str);
char token[20];
char peekt[20];
char s[100];
char *str;
//scanner
char pr[100];
char *prp=pr;
bool checkBR = true;
bool checkstr = true;
char *scanner(char *p);
char *caseid(char *p);
int invaildinput();
char *casestr(char *p);
int checkgm(bool a1,bool a3);
void addn();
void addtoken(char token[]);

int main()
{
    scanf("%[^\0]", s);
    char *p = s;
    scanner(p);
    if(checkgm(checkBR,checkstr))
    {    
        *prp = '$';
        prp++;
        addn();
        str = pr;
        program();
        printf("Valid");
    }
    else
    {
        printf("invaild input\n");
    }
    
    return 0;
    //printf("Valid");
}

void program(){
    stmts();
}
void stmts(){
    peek(str);
    if((!(strcmp(peekt,"ID")))||!((strcmp(peekt,"STRLIT")))){
        stmt();
        stmts();
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam
    }
    else{
        error();
    }
}
void stmt(){
    expp();
    str = gettoken(str);
    match(str,"SEMICOLON");//semi
    
}
void expp(){
    peek(str);
    if(!(strcmp(peekt,"ID"))){
        primary();
    }
    else if(!(strcmp(peekt,"STRLIT"))){
        str = gettoken(str);
        match(str,"STRLIT");//strlit
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam
    }
    else{
        error();
    }
}
void primary(){
    str = gettoken(str);
    match(str,"ID");//id
    primary_tail();
}
void primary_tail(){
    peek(str);
    if(!(strcmp(peekt,"DOT"))){
        str = gettoken(str);
        match(str,"DOT");//dot
        str = gettoken(str);
        match(str,"ID");//id
        primary_tail();
    }
    else if (!(strcmp(peekt,"LBR"))){
        str = gettoken(str);
        match(str,"LBR");//lbr
        expp();
        str = gettoken(str);
        match(str,"RBR");//rbr
        primary_tail();
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam!(strcmp(token,"\0"))
    }
    else{
        error();
    }
}
char *match(char *str,char *s){
    if(strcmp(token, s)!=0){
        error();
    }
    return str;

}
void error(){
    printf("Invalid\n");
    exit(1);
}
char *gettoken(char *str){
    int i = 0;
    memset(token, '\0', 10);
    while ((*str!= '\n')^(*str=='\0'))//^(*str!='\0')
    {
        token[i]= *str;
        str++;
        i++;
    }
    str++;
    return str;
}
void peek(char *str){ 
    char *p;
    p = str;
    int i = 0;
    memset(peekt, '\0', 10);
    if(*p=='$'){
        peekt[0] = '$';
    }
    else {

        while ((*p != '\n')^(*str=='\0'))
       {          
           peekt[i]= *p;
           p++;
           i++;
       }
    }
}
//scanner-----------------------------------------------
char *scanner(char* p){
    while (*p !='\0')
    {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')||*p=='_')
        {
            p=caseid(p);           
        }
        else if (*p == '.')
        {
            addtoken("DOT");
            addn();
        }
        else if (*p == '(')
        {
            addtoken("LBR");
            addn();
        }
        else if (*p == ')')
        {
            addtoken("RBR");
            addn();
        }
        else if (*p == '"')
        {
            checkstr = false;
            p=casestr(p);
        }
        else if (*p == ';')
        {
            addtoken("SEMICOLON");
            addn();        
        }
        else if (*p=='\n'){}
        else if (*p==' ')
        {
            p++;
        }
        else
        {
            p--;
            invaildinput();
        }
        p++;
    }
    p++;
    return p;
}
char *caseid(char *p){
    addtoken("ID");
    while((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')||(*p >= '0' && *p <= '9')||*p=='_')
    {
        p++;       
    }
    addn();
    p--;
    return p;
}
int invaildinput(){
    printf("invaild input\n");
    exit(1);
}
char *casestr(char *p){
    addtoken("STRLIT");

    p++;
    while(*p!='"'^*p=='\0')
    {
        p++; 
    }
    if(*p=='"')
    {
        checkstr = true;
    }
    else
    {
        invaildinput();
    }
    addn();
    return p;
}
int checkgm(bool a1,bool a3){
    if(a1==true&&a3==true)
    {
        return 1;
    }
    return 0;
}
void addn()
{
    *prp = '\n';
    prp++;
}
void addtoken(char token[]){
    char *tmp=token; 
    strcat(prp, tmp);
    prp = prp + strlen(tmp);
}