#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct maxsubarray{
    int *subarray;
    int size;
}maxsubarray; 


//ok maybe not the best implementation... need to look more into it. 
maxsubarray findlargestsum(int *array, int n, int *a, int *b)
{
    int max_sum = -1000000;
    int current_sum = 0;
    int start = 0;int end = 0; int temp_start = 0;

    for (int i = 0; i < n; i++)
    {
        current_sum += array[i];

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    *a = start;
    *b = end;

    maxsubarray result;
    result.size = end - start + 1;

    result.subarray = (int *)malloc(result.size * sizeof(int));
    if (!result.subarray)
    {
        printf("Memory Allocation Failed");
        exit(1);
    }
    for (int i = 0; i < result.size; i++)
    {
        result.subarray[i] = array[start + i];
    }
    return result;
}

int main()
{
    int array[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(array)/ sizeof(array[0]);

    int a, b;

    maxsubarray result = findlargestsum(array, n, &a, &b);

    printf("Maximum sum subarray: ");
    for (int i = 0; i < result.size; i++) {
        printf("%d ", result.subarray[i]);
    }
    printf("\n");

    // Free allocated memory
    free(result.subarray);

    return 0;
}