#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void program();
void stmts();
void stmt();
void expp();
void primary();
void primary_tail();
void match();
void error();
void final_print();
int peek();

int main()
{
    
}

void program(){
    stmts();
}
void stmts(){
    if(peek()==0){
        stmt();
        stmts();
    }
    else if(peek()==0){
        //lam
    }
    else{
        error();
    }
}
void stmt(){
    expp();
    match();//semi
}
void expp(){
    if(peek()==0){
        primary();
    }
    else if(peek()==0){
        match();//strlit
    }
    else if(peek()==0){
        //lam
    }
    else{
        error();
    }
}
void primary(){
    match();//id
    primary_tail();
}
void primary_tail(){
    if(peek()==0){
        match();//dot
        match();//id
        primary_tail();
    }
    else if (peek()==0){
        match();//lbr
        expp();
        match();//rbr
        primary_tail();
    }
    else if(peek()==0){
        //lam
    }
    else{
        error();
    }
}
void match(){

}
void final_print(){

}