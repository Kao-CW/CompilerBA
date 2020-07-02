
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char *func(char *p);
int main()
{
    char *p="kljjkavdf";
    
    int i = 0;
    while (*p !='\0')
	{
        if(*p=='a')
        {
            p=func(p);
        }
        printf("%c %d\n", *p,i);
        p++;
        i++;
    }
    printf("你好");
    return 0;
}

char *func(char *p)
{
    printf("%c\n", *p);
    p++;
    return p;
}