#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(int *p)
{
    *p = 42;
}

int sum(int *arr, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        if ( arr[i] % 2 != 0)
        {
            total += arr[i];
        }        
    }
    return total;
}

int sorter(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

int main()
{
    int a = 43;
    printf("The value of a is %d\n",a);
    f(&a);
    printf("The value of a is: %d\n",a);

    int arr[] = {4,5,1,2,3}; //9
    int size = sizeof(arr)/sizeof(arr[0]);
    int res = sum(arr, size); //i am pretty sure it's just arr. 
    printf("The sum of the odd elements in the array are: %d\n", res);
    qsort(arr, size, sizeof(int), sorter); 
    for (int i = 0; i < size; i ++ )
    {
        printf("%d, ", arr[i]);
    }
    //probably not going to be on the test. 
    return 0;
}