#include<stdio.h>
#include<stdlib.h>

int main()
{
    char s[100];

    FILE *fp;
    fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");    
    while((fscanf(fp,"%s",s))!=EOF)
    {
        printf("%s", s);
    }
    fclose(fp);
    system("pause");
    return 0;
}