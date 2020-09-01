#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100];
char line[20];
char *pline;
char *ps;
void func_1(char *str);
void func_2();
void gline(char *str);
void add(char target[], char *p);
void sort(char target[]);
void final_print();
int match(char a,int k);
int i=0; // nontern count
int key = 1;
struct set{
    char nonterminal;
    char terminal[30];
    char us[10];
};

struct set firstset[15];
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
    func_2();
    final_print();

    return 0;
}

void func_1(char *str){
    gline(ps);
    pline = line;
     printf("cmp=%d\n", strcmp(pline, "END_OF_GRAMMAR"));
    while(strcmp(pline,"END_OF_GRAMMAR")!=0){
        pline = line;
        firstset[i].nonterminal = *pline;
        pline=pline+2;
        while (*pline != '\0')
        {       
            if(key==1 && (*pline >= 'a' && *pline <= 'z')){
                //nonterminal
                add(firstset[i].us, pline);
            }
            else if(key==1 &&(*pline >= 'A' && *pline <= 'Z')){
                //terminal
                add(firstset[i].terminal, pline);
                key = 0;
            }
            else if(key==1 &&((*pline=='!')||(*pline=='@')||(*pline=='#')||(*pline=='%')||(*pline=='^')||(*pline=='&')||(*pline=='*'))){
                //terminal
                add(firstset[i].terminal, pline);
                key = 0;
            }
            else if(key==1 &&*pline == ';'){
                add(firstset[i].terminal, pline);
                key = 0;
                //eol         
            }
            else if(key==1 &&*pline == '$'){
                add(firstset[i].terminal, pline);
                key = 0;
                //eof
            }
             else if(*pline=='|'){
                key = 1;                
            }
            else{
                //ket!=0
            }
            pline++;
        }
        printf("NONTERN=%c\n", firstset[i].nonterminal);
        printf("TERN=%s\n", firstset[i].terminal);
        printf("us=%s\n", firstset[i].us);
        printf("----------------------------------------------\n");
        gline(ps);
        key = 1;
        pline = line;
        printf("cmp=%d\n", strcmp(pline, "END_OF_GRAMMAR"));
        pline = line;
        i++;
    }
    i--;
}

void func_2(){
    int c = i;
    for (int j = c; j >=0;j--){
        char *tmp = firstset[j].us;
        while(*tmp!='\0'){
            char a = *tmp;
            int t=match(a, j);
            strcat(firstset[j].terminal, firstset[t].terminal);
            tmp++;
        }
    }
    for (int j = 0; j <=c;j++){     
        sort(firstset[j].terminal);
    }
    int size = c + 1;
    for (int i = 1; i <=c;i++){
        struct set tmp = firstset[i];
        int j = i-1;
        while(tmp.nonterminal>firstset[j].nonterminal && j>=0){
            firstset[j + 1] = firstset[j];
            j--;
        }
        firstset[j + 1] = tmp;
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
    printf("%s\n", line);
    ps++;
    printf("gline success\n");
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
}
