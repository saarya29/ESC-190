#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *reverse_word(char *str)
{
    int size = strlen(str);
    char *copy = (char *)malloc(sizeof(char)*(size + 1));
    int start = size;
    for (int i = size; i > 0; i--)
    {
        if (str[i] == ' ')
        {
            (*copy)[i] = str[start:i];
            start = start - i; 
        }
    }
    return copy;
}




//Question 4: 
int is_increasing(int *arr, int sz)
{
    if (sz == 0)
    {
        return 1;
    }
    if (sz == 1)
    {
        return 1:
    }
    if (arr[0] < arr[1])
    {
        is_increasing(arr[1], sz - 1);
        return 1
    }
    else
    {
        return 0;
    }
}