#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void initArray(int **a, int n)
{
    *a = (int *)malloc(n*sizeof(int));
    //the reason you can't do *a itself is because you want to proved 
    for (int i = 0; i<n; i++)
    {
        a[i] = 0; //because you want to see everythinghte 0. 
    }
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int Palindrome(int *a, int n)
{
    int res = 1;
    for (int i = 0; i < n/2; i++)
    {
        if (a[i] != a[n-1-i])
        {
            res = 0;
        }
    }
    return res; 
}