#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100];
char line[20];
char *pline,*tmp;
char *ps;
void func_1(char *str);
void func_2();
void findfirst(int k,char t);
void gline(char *str);
void add(char target[], char *p);
void sort(char target[]);
void final_print();
int match(char a,int k);
int i=0;  //firstset count
int pc = 0; //production count
int key = 1;
struct set1{
    char nonterminal;
    char terminal[30];
    char us[10];
};
struct set2{
    char nonterminal;
    char terminal[10];
    char first[15];
    int tag;
};
struct set1 firstset[15];
struct set2 production[15];

int main()
{
    
    scanf("%[^\0]", s);
    ps = s;
    while (*ps!= '\0'){
        printf("%c",*ps);      
        ps++;
    }
    printf("\n----------------------------------------------\n");
    ps = s;
    func_1(ps);
    printf("here");
    for (int j = 0; j <pc;j++){
        printf("NONTERN=%c\n", production[j].nonterminal);
        printf("TERN=%s\n", production[j].terminal);
        printf("----------------------------------------------\n"); 
    }

    return 0;
}

void func_1(char *str){
    gline(ps);
    pline = line;
    while(strcmp(pline,"END_OF_GRAMMAR")!=0){
        pline = line;
        char t = *pline;
        production[pc].nonterminal = t;
        production[pc].tag = 0;
        pline=pline+2;
        while(*pline != '\0'){
            if(*pline=='|'){
                pc++;
                production[pc].nonterminal = t;
            }
            else{
                add(production[pc].terminal, pline);
            }
            pline++;
        }
        gline(ps);
        pline = line;
        printf("cmp=%d\n", strcmp(pline, "END_OF_GRAMMAR"));
        pline = line;
        pc++;
    }
    
}


void func_2(){
    for (int j = 0; j <pc;j++){
        tmp = production[j].terminal;
        while(*tmp!='\0'){
            if((*tmp>='A'&&*tmp<='Z')||*tmp=='$'){
                add(production[j].first, tmp);
                break;
            }
            else if(*tmp == ';'){
                add(production[j].first, tmp);
                production[j].tag = 1;
                break;
            }
            else if(*tmp>='a'&& *tmp<='z'){
                findfirst(j+1,*tmp);
            }
        }
    }
  
}

void findfirst(int k,char t){
    char *a1;
    for (int j = k; j < pc;j++){
        if(production[j].nonterminal==t){
            a1 = production[j].terminal;
            if((*tmp>='A'&&*tmp<='Z')||*tmp=='$'){
                add(production[j].first, tmp);
                break;
            }
            else if(*tmp == ';'){
                add(production[j].first, tmp);
                production[j].tag = 1;
                break;
            }
            else if(*tmp>='a'&& *tmp<='z'){
                findfirst(j+1,*tmp);
            }
        }
    }
}


void gline(char *str){
    int i = 0;
    memset(line, '\0', 20);
    while(!((*ps!='\0')^(*ps!='\n'))){
        line[i] = *ps;
        i++;
        ps++;
    }
    printf("gline success : %s\n", line);
    ps++;
}

void add(char target[], char *p){
    char a[1];
    a[0] = *p;
    strncat(target, a,1);
}

void sort(char target[]){
    int size = strlen(target);
    for (int i = 1; i < size; i++){
        int tmp = target[i];
        int j = i - 1;
        while (tmp > target[j] && j >= 0){
            target[j + 1] = target[j];
            j--;
        }
        target[j + 1] = tmp;
    }
}

int match(char a,int k){
    int c = i;
    int ans=0;
    for (int j = c; j >k;j--){
        if(a==firstset[j].nonterminal){
            ans = j;
        }
    }
    return ans;
}

void final_print(){
    printf("----------------------------------------------\n"); 
    printf("final print\n");
    printf("----------------------------------------------\n");
    int c = i;
    for (int j = 0; j <=c;j++){
        printf("NONTERN=%c\n", firstset[j].nonterminal);
        printf("TERN=%s\n", firstset[j].terminal);
        printf("us=%s\n", firstset[j].us);
        printf("----------------------------------------------\n"); 
    }
    char tmp;
    char *p;
    for (int j = 0; j <=c;j++){
        printf("%c  ", firstset[j].nonterminal);
        p = firstset[j].terminal;
        tmp = *p;
        printf("%c",*p);      
        p++;
        while (*p!= '\0'){            
            if(*p==tmp){
                p++;
            }
            else{
                printf("%c",*p); 
                tmp = *p;
            }
        }
        printf("\n");
    }
    printf("END_OF_FIRST\n");
}
