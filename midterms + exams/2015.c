#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first_occurence(char *str1, char *str2, int len2, int i, int j)
{
    if(str1[i] == '\n')
    {
        return -1;
    }
    if (len2 == j)
    {
        return i - j; //you need to return the starting index. 
    }
    if (str1[i] != str2[j])
    {
        first_occurence(str1, str2, len2, i+1, 0);
    }
    else
    {
        first_occurence(str1, str2, len2, i +1, j+1);
    }
    
}