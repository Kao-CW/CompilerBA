#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char s[100];
char line[20];
char *ps = s;
char *pline;
void first(char *str);
void gline(char *str);

int main()
{
    
    scanf("%[^\0]", s);
    gline(ps);
    pline = line;
    while (*pline!= '\0'){
        printf("%c",*pline);      
        pline++;
    }
    // pline = line;
    // if(strcmp(pline,"END_OF_GRAMMAR")==0){
    //     printf("11111");
    // }
    // printf("22222");
    // printf("\n");  
    // gline(ps);
    // pline = line;
    // while (*pline!= '\0'){
    //     printf("%c",*pline);      
    //     pline++;
    // }
    return 0;
}

void first(char *str){
    pline = line;
    while(strcmp(pline,"END_OF_GRAMMAR")!=0){

    }
    

}

void gline(char *str){
    int i = 0;
    memset(line, '\0', 20);
    while(*ps!='\n'){
        line[i] = *ps;
        i++;
        ps++;
    }
    ps++;
}
