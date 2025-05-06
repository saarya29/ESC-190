#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int findLargestSum(int *array, int n, int *a, int *b)
{
    int max_sum = -1000000;
 //for each for loop it's going to turn back into 0.
    int start = 0; int end = 0;
    for (int i = 0; i<n; i++) //you want to traverse through the first element, and then compute the sum. 
    {
        int sum = array[i]; //i'm pretty sure I'm going to have to initialize it here so that it becomes 0 after each iteration

        for (int j =i; j < n; j++) //I realized that checking 4 from -1 is unecessary when you already check -1 from 4. 
        {
            sum += array[j]; 
            if (sum > max_sum)
            {
                max_sum = sum; //and this would go on until you reach the actual maximum sum. 
                start = i;
                end = j; //this is going to tell you where the maximum and the minimum are.... it's similar to binary search left and binary search right.
            }
        }
    }

    *a = start;
    *b = end;

    int *SubarraySize = end - [start + 1];

    int *subarray = (int *)malloc((*SubarraySize)*sizeof(int));
    if (!subarray)
    {
        printf("Memory Allocation Failed \n");
        exit(1);
    }

    for (int i = 0;i < *subarraySize; i++)
    {
        subarray[i] = array[start + i];
    }
    return subarray;   
}

//ok i guess you can kind of just remember this type of algorithm. 
int findLargestSum1(int *array, int n, int *a, int *b)
{
    int currSum = array[0], sum = 0;
    int i, j;
    *a = 0;
    *b = 0;
    for (i = 0; i < n; i ++)
    {
        for (j = i; j <n; j++)
        {
            sum = sum + array[j];
            if (sum > currSum)
            {
                *a = i;
                *b = j;
            }
        }
        sum = 0;
    }
    return CurrSum
}//there you were just lost on how to return the array. Make the currsums into the first one...



int main()
{
    int array[] = -2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(array)/sizeof(array[0]);
    int *a = 0;
    int *b = 0;
    int *maxSubarray = findLargestSum(array, n, &a, &b);

    printf("Maximum sum subarray: ");
    for (int i = 0; i < subarraySize; i++) {
        printf("%d ", maxSubarray[i]);
    }
    printf("\n");

    free(maxSubarray); // Free dynamically allocated memory
    return 0;
}