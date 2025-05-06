#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumFib(int n, int s)
{//this is not going to be the sum up till date but rather the term up to which the Fibonacci sequence is summed. 
    if (n == 0)
    {
        return 0; //base case also because the sum is going to be 0. 
    }
    if (n == 1)
    {
        return 1;
    }
    if (s == 0)
    {
        return sumFib(n-1,0)+sumFib(n-2,0);
    }
    else
    {
        return sumFib(n-1, 0) +sumFib(n,0);
    }

}

int another(int n, int s)
{
    if (n <= 0) //there are no terms. 
    {
        return 0;
    }
    if (n == 1) //you have the 1st integer, which we know is going to be 1. 
    {
        return 1;
    }
    if (s == n) // you need to sum up all the terms from the list. 
    {
        return another(n-1, s) + another(n-2,s);
    }
    //while s != n
    return another(n-1, s+1) + another(n-2, s+1);

}


// you can actually just use the helper function. 


int fib(int n)
{
    if (n == 0 )
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

//uisng the solution that we made from part A. 

int sumFib(int n)
{
    if (n<= 0)
    {return 0;}
    if (n==1)
    {return 1;}
    return sumFib(n - 1) + fib(n);
}

int **initStructure(int r, int *a)
{
    //r is the number of rows and a how much to allocate in that place. 
    //1. You need to implement a malloc that can take in 3 and is in row 1. 
    int i, j;
    int **s = (int **)malloc(sizeof(int *)*r);//because that's the number of mallocs you're going to have. Not sure what the j loop is for then. 
    for (i = 0; i < r; i ++)
    //I think you need to malloc all of the mallocs into a bigger malloc. 
    {
        //you're in the zeroth row.. you need to get to the first row. 
        int num = a[i]; 
        s[i]=(int *)malloc(sizeof(int)*num);
        //you need to malloc each of the lines and the arrays. 
        for (j = 0; j<a[i]; j++)
        {
            s[i][j] = 0; //you're going to go in each of the lines and then each of the blocks in each ot hte lines. This NEEDS to be as a nested loop. and then you're oging to set them all = 0
        }
    }
    //s is kind of a pointer, so you need another pointer to make it into a double pointer. 
    

    //Now after all of this, you're going to have to set them to 0. 
    
    return s;
}


