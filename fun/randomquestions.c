#include <stdio.h>
#include <string.h>


int function(float a, float b)
{
    int i = b + a;
    return i;
}


double fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n-1); //you don't need to do too much apparently. 
}
void replace_ws(char *s)
{
    int size1 = strlen(s);
    char *replace = "winter";
    int size2 = strlen(replace);
    for (int i = 0; i < size1; i++) //now sure why you'd need the size2 as well. 
    {
        if (strncmp(s + i, replace, size2)==0) //when comparing substrings, you need to use strncmp. 
        {
            strncpy(s+ i, "summer", size2);
        }
    }
    //strncmp and strncpy are very useful!!!
}

int main()
{
    char str[] = "I love winter. Winter is cold.";
    replace_ws(str);
    printf("%s\n", str);  // Expected output: "I love summer. Summer is cold."
    return 0;
    //you need to make sure they are all lowercase... or else, will
    //not really work. 
}