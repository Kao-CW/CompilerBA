#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str[10];
int i = 0;
char *p;
int main()
{
    printf("input:\n");
    scanf("%s",str);
    p = str;
    printf("output:\n");
    /*while(str[i]!='\0')
    {
        printf("%c", str[i]);
        i++;
    }*/
    
    while(*p!='\0')
    {
        printf("%c", *p);
        p++;
    }
    


    return 0;
}

