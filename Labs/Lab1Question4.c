#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) // you want to look at the integer that's after, so start at 1. 
    {
        key = a[i]; // comparison factor.
        j = i - 1;
    // smart... you move the elements of the array that are greater than your key value a[0] at first and then switch around
    while (j >= 0 && a[j] > key) //both conditions must be satisfied. It's like bubble sort in a way... you know you'd need a nested loop.
    {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[j+1] = key;
    }
} // my placement of brackets messed this up. 
void printArray(int a[],int size)
{
    int i;
    for (i = 0; i < size; i++) //i think for loops are like from the start to the end, and the increment size. Like MATLAB.
    {
        printf("%d ",a[i]);
    }
    printf("\n"); //unsure about the need of this statement
}

int main()
{
    int a[5] = {4,3,2,5,6};
    int n = sizeof(a)/sizeof(a[0]); // always 5/1... i feel like a better way would have been to just say the length of a. 


    insertion_sort(a,n);
    printArray( a,n);
    return 0;
}
