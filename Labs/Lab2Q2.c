#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "This is";
    char str2[] = "programming";
    int length = strlen(str2); 

    for (int i = 0; i < length; i++) { 
        char temp[2] = {str2[i], '\0'}; // Create a temporary string with the current character and null terminator
        strcat(str1, temp); 
    }

    puts(str1);
    


    /*char s[100] = "This is";
    char *t = "programming";
    int sizet = strlen(t);
    for (int i = 0; i <= sizet; i++)
    {
        *(&s[strlen(s)]) = *(t + i); // Assign the current character from t to the next available position in s

    }

    puts(s);
    return 0;
}

//string [i] (withouth strcat) and the pointer arithmetic */