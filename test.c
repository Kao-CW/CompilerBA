#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char str[100];
int i = 0;
char *p;
int main()
{
    p = str;
    //printf("input:\n");
    scanf("%[^\0]", str);

        //printf("output:\n");
        //printf("%s", str);
        /*while(str[i]!='\0')
    {
        printf("%c", str[i]);
        i++;
    }*/
        while (*p != '\0')
        {
            printf("%c",*p);
            p++;
    }

    return 0;
}

