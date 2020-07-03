#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[100];
    char c;
    int i = 0;
    char *p;

    FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");    
    while((s[i]=fgetc(fp))!=EOF)
    {
       // printf("%c", s[i]);
        i++;
    }
    p = s;
    while (*p !='\0')
	{
        
        printf("%c", *p);
        p++;
        
    }
    i = 0;
    /*while(s[i]!=EOF)
    {
        printf("%c", s[i]);
        i++;
    }*/
    
    fclose(fp);
    system("pause");
    return 0;
}