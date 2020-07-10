#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[100];
char str2[100];
int i = 0;
char *p,*q;
char tmp[10];
int main()
{
    p = str1;
    q = str2;
    FILE *fp;
    /*fp = fopen("D://CPROJECT//CompilerBA//mytestcase.txt","r");
    while((str1[i]=fgetc(fp))!=EOF)
    {
        i++;
    }*/
    scanf("%[^\0]", str2);
    //scanf("%s", str2);

        //printf("output:\n");
        //printf("%s", str);
        /*while(str[i]!='\0')
    {
        printf("%c", str[i]);
        i++;
    }*/
    /*while (*p != '\0')
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");*/
    while (*q!= '\0')
    {
        printf("%c",*q);
        q++;
    }
    q= str2;
    printf("\n");
    printf("q = %c\n", *q);
    while (*q!= '\n')
    {
        tmp[i]= *q;
        printf("q = %c\n", *q);
        printf("tmp = %s\n", tmp);
        q++;
        i++;
    }
    printf("\n");
    printf("------------------------\n");
    printf("%s",tmp);
     /*while (*tmp!= '\0')
    {
        printf("%s",tmp);
        tmp++;
    }*/
    //printf("%s\n",str1);
    //printf("%s\n",str2);
    //printf("result=%d", strcmp(str2, str1));

    return 0;
}


