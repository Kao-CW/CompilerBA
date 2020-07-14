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
    while (*p!= '\0')
    {
        printf("%c",*p);
        p++;
    }
    p = s;
    printf("\n");
    scanner(p);
    printf("scannerdone\n");
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
    printf("---------------program--------------\n");
    stmts();
}
void stmts(){
    printf("---------------stmts--------------\n");
    printf("peekt== %s \n ", peekt);
    printf("token== %s \n ", token);
    peek(str);
    printf("peekt== %s \n ", peekt);
    if((!(strcmp(peekt,"ID")))||!((strcmp(peekt,"STRLIT")))){
        stmt();
        stmts();
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam
    }
    else{
        printf("1---------\n");
        error();
    }
}
void stmt(){
    printf("---------------stmt--------------\n");
    expp();
    printf("2------------------------\n");
    str = gettoken(str);
    match(str,"SEMICOLON");//semi
    printf("2ok----------------------\n");
    
}
void expp(){
    printf("---------------expp--------------\n");
    peek(str);
    printf("peekt==%s\n", peekt);
    if(!(strcmp(peekt,"ID"))){
        primary();
    }
    else if(!(strcmp(peekt,"STRLIT"))){
        printf("3------------------------\n");
        str = gettoken(str);
        match(str,"STRLIT");//strlit
        printf("token==%s\n", token);
        printf("3ok----------------------\n");
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam
    }
    else{
        printf("4-----------------------\n");
        error();
    }
}
void primary(){
    printf("---------------primary--------------\n");
    printf("5--------------------------\n");
    str = gettoken(str);
    match(str,"ID");//id
    printf("5ok------------------------\n");
    primary_tail();
}
void primary_tail(){
    printf("---------------primary tail--------------\n");
    peek(str);
    printf("peekt==%s\n", peekt);
    if(!(strcmp(peekt,"DOT"))){
        printf("6--------------------------\n");
        str = gettoken(str);
        match(str,"DOT");//dot
        printf("token==%s\n", token);
        printf("6ok------------------------\n");
        printf("7--------------------------\n");
        str = gettoken(str);
        match(str,"ID");//id
        printf("token==%s\n", token);
        printf("7ok------------------------\n");
        primary_tail();
    }
    else if (!(strcmp(peekt,"LBR"))){
        printf("8-------------------------\n");
        str = gettoken(str);
        match(str,"LBR");//lbr
        printf("token==%s\n", token);
        printf("8ok-----------------------\n");
        expp();
        printf("9-------------------------\n");
        printf("before match rbr token==%s\n", token);
        printf("match rbr= %d\n", strcmp(peekt, "RBR"));
        str = gettoken(str);
        match(str,"RBR");//rbr
        printf("before gettoken==%s\n", token);
        printf("9ok-----------------------\n");
        primary_tail();
    }
    else if(!(strcmp(peekt,"$"))||!(strcmp(peekt,"SEMICOLON"))){
        //lam!(strcmp(token,"\0"))
    }
    else{
        printf("10-------------------------\n");
        error();
    }
}
char *match(char *str,char *s){
    if(strcmp(token, s)!=0){
        error();
    }
    printf("match done\n");
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
    printf("gettokendone token == %s\n",token);
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
    printf("peekdone peekt == %s\n",peekt);
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