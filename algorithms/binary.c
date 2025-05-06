#include <stdio.h>
#include <stdlib.h>

int binary_search_left(int L[], int target, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (L[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int binary_search_right(int L[], int target, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (L[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}

// Function to return an array containing the leftmost and rightmost indices
int* find_occurrences(int L[], int target, int size, int* indices) {
    indices[0] = binary_search_left(L, target, size);
    indices[1] = binary_search_right(L, target, size);
    return indices; 
}

//doing l + (r - i)

int binary(int arr[], int size, int target)
{
    int left = 0; int right = size -1; int result = -1;
    while (left <= right)
    {
        int mid = left +(right - left)/2;
        if (arr[mid] == target) //you can just add this for
        {
            result = mid;
            left = mid + 1;
        }
        else if (arr[mid]<= target) //it's basically the same thing as biary search left. 
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int L[] = {1, 2, 3, 10, 10, 10, 12, 12};
    int arr[] = {2,3,4,10,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    int answer = binary_search_right(arr, n, target);
    if (answer != -1)
    {
        printf("Element found at index %d\n", answer);
    }
    int size = sizeof(L) / sizeof(L[0]);
    int indices[2]; // Declare the indices array locally

    int* result = find_occurrences(L, target, size, indices); 

    printf("Leftmost index: %d\n", result[0]); 
    printf("Rightmost index: %d\n", result[1]); 

    return 0;
}