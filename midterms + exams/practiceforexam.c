#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int median(int *arr, int size)
{
    int index = size/2;
    int median = arr[index];
    return median;
}
//but you'd also have to add qsort which has a complexity of n log n



char *reverse_word(char *s)
{
    int size = strlen(str);
    char **temp = (char *)malloc(sizeof(char)*(size + 1));
    int start = 0; int end = 0; int word = 0;
    for (int i = size - 1; i > = 0; i--)
    {
        if (str[i] == " ")
        {
            end = i; 
            start = i + 1;
            int word_len = end - start + 1;
            strncpy(temp + word, str + start, word_len);
            word += word_len;
        }
    }
    return temp;
}


char *reverse_word(char *s)
{
    int size = strlen(str);
    char **temp = (char *)malloc(sizeof(char)*(size + 1));
    int start = 0; int end = 0; int word = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (str[i] == " ")
        {
            end = i; 
            start = i + 1; // you want to continue afterwards
            word_len = end - start + 1; //ok
            strncpy(temp + word, str + start, word_len);
            word += word_len;
        }
    }
    return temp;
}
