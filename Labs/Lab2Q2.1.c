#include <stdio.h>
#include <string.h>

//1. Indexing: 
char* indexing(char *str1, char *str2, int length1, int length2)
{
    for (int i = 0; i <=length2; i++) //it's going to go through the second string and then keep on adding it to the first string. The reason for the equal is we need it to include the null terminator
    {
        str1 = str1 + str2[i]; //it's going to add the first part of the second string in here. 
        printf("%s\n",str2);
    }
    return str2;
}  


int main()
{
    char str1[100] = "This is";
    char str2[] = "programming";
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    indexing(str1, str2, length1, length2);
    //I want to get "This is programming"
    return 0;
}