#include <stdio.h>
#include <string.h>


int main()
{
    char *names[] = {"Jim", "Jack", "Joe"};
    int i;

    for (i = 0; i < 3; ++i)
    {
        printf(" %s", names[i]);
    }

    int list[] = {3,2,1,0,1,2,3};
    int *p = list;

    while (*p++)
    {
        printf("\n%d\n", *p);
    }
}



char *join(int n, const char *strs[], const char *sep)
{
    char **string = (char *)malloc(sizeof(char)*2*n);
    for (int i = 0; i < 2*n; i += 2)
    {
        string[i] = strs[i];
        string[i+1] = sep;
    }
    return string;
    //this is wrong :(
}