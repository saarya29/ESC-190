#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    fp = fopen("wiktionary.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to Open this File");
        return EXIT_FAILURE;
    }
    else 
    {
        while ((ch = fgetc(fp))!= EOF)
        {
            printf("%c", ch);
        }
    }
    
   
    return 0;
}