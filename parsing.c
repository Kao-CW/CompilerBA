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
void final_print();
void peek(char *str);
char token[20];
char peekt[20];
char str1[100];
char *str;

int main()
{
    str = str1;
    scanf("%[^\0]", str1);
    while (*str!= '\0')
    {
        printf("%c",*str);
        str++;
    }
    printf("\n");
    str = str1;
    str = gettoken(str);
    printf("str==%c\n", *str);
    printf("token==%s\n", token);
    printf("peek==%s\n", peekt);
    program();
}

void program(){
    stmts();
}
void stmts(){
    //peek(str);
    printf("strcmp== %d \n ", strcmp(token,"ID"));
    if((!(strcmp(token,"ID")))||!((strcmp(token,"STRLIT")))){
        stmt();
        stmts();
    }
    else if(!(strcmp(token,"\0"))){
        //lam
    }
    else{
        printf("1---------\n");
        error();
    }
}
void stmt(){
    expp();
    printf("2---------\n");
    match(str,"SEMICOLON");//semi
}
void expp(){
    peek(str);
    printf("token==%s\n", token);
    printf("peekt==%s\n", peekt);
    if(!(strcmp(token,"ID"))){
        primary();
    }
    else if(!(strcmp(token,"STRLIT"))){
        printf("3------------------------\n");
        match(str,"STRLIT");//strlit
    }
    else if(!(strcmp(token,"\0"))){
        //lam
    }
    else{
        printf("4-----------------------\n");
        error();
    }
}
void primary(){
    printf("5--------------------------\n");
    match(str,"ID");//id
    printf("5ok------------------------\n");
    primary_tail();
}
void primary_tail(){
    printf("str==%c\n", *str);
    peek(str);
    printf("token==%s\n", token);
    printf("peekt==%s\n", peekt);
    if(!(strcmp(token,"DOT"))){
        printf("6--------------------------\n");
        match(str,"DOT");//dot
        printf("6ok------------------------\n");
        printf("token==%s\n", token);
        printf("7--------------------------\n");
        match(str,"ID");//id
        printf("7ok------------------------\n");
        primary_tail();
    }
    else if (!(strcmp(token,"LBR"))){
        printf("8-------------------------\n");
        match(str,"LBR");//lbr
        printf("8ok-----------------------\n");
        expp();
        printf("9-------------------------\n");
        match(str,"RBR");//rbr
        printf("9ok-----------------------\n");
        primary_tail();
    }
    else if(!(strcmp(peekt,"\0"))){
        //lam
    }
    else{
        printf("10-------------------------\n");
        error();
    }
}
char *match(char *str,char *s){//ok
    if(strcmp(token, s)!=0){
        error();
    }
    printf("before match token= %s\n", token);
    printf("before match str= %c\n", *str);
    str=gettoken(str);
    printf("after match token= %s\n", token);
    printf("after match str= %c\n", *str);
    return str;

}
void error(){//ok
    printf("Invalid\n");
    exit(1);
}
char *gettoken(char *str){//ok
    int i = 0;
    memset(token, '\0', 10);
    while (*str!= '\n')
    {
        token[i]= *str;
        str++;
        i++;
    }
    str++;
    return str;
}
void peek(char *str){
    memset(peekt, '\0', 10);
    char *p;
    p = str;
    int i = 0;
    while (*p != '\n')
    {
        peekt[i]= *p;
        p++;
        i++;
    }
}
void final_print(){

}