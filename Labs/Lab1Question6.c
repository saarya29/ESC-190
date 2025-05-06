#include <stdio.h>
//take in two arrays and their sizes and replaces every appaearance of arr2 in arr1 with Os.
void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) // i think they're taking in the addresses? *arr is pointer. 
{
    for (int i = 0; i< arr1_sz;i++)
    {
        for (int j = 0; j < arr2_sz; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr1[i] = 0;
                //break; // you want to exit the loop s.t. if doesn't continue to that element again... but i think you shold get the same output even if you don't break. 
            }
        }
    }
}
//IMPORTANT: when you need to pass arrays to functions in C, you need to pass them as pointers. By using *arr1/2, you pass the pointers to the first elements of the arrays so the function can access + modify the actual elements in the original array as you iterate through them.
//Since this is a nested loop targetting different arrays, the runtime complexity if O(m*n)
int main()
{
    int arr[] = {5,7,6,8,6,7};
    int b[] = {6,7}; //output should be {5,0,0,8,0,0}
    //printf("%p\n",&arr[0]);//to get the address of the array, you need to do that. 
    int size1 = sizeof(arr)/sizeof(arr[0]);
    int size2 = sizeof(b)/sizeof(b[0]);
    seq_replace(arr,size1,b,size2);
    for (int i = 0; i < size1; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
//address in seq_replace meaning that the 0s should be stored in the same address. 
//logic ideas: you have a nested loop in a way that goes through arr1 addresses and arr2 addresses and compares them