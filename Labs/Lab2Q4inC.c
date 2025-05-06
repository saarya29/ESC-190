#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int binary_search_left(int L[],int target, int size)
{
    int left = 0;
    int right = (size - 1);
    while (left <= right){
        int mid = (left + right) /2;
        if(L[mid] < target){
            left = mid + 1;}
        else{
            right = mid - 1;}}
    return left;
}

int binary_search_right(int L[],int target, int size)
{
    int left = 0;
    int right = (size - 1);
    while (left <= right){
        int mid = (left + right) /2;
        if(L[mid] <= target){
            left = mid + 1;}
        else{
            right = mid - 1;}}
    return right;}
// you need the indices from before... adding the star also in a way makes it into a global variable
int* binary_search_deluxe(int L[], int target, int size, int *indices) //I need this to return an array, so I need to use the pointer logic like how for integers it's going to return an integer. 
{ //you already defined it in main and when calling so you don't have to do it again...
    indices[0] = binary_search_left(L, target, size);
    indices[1] = binary_search_right(L, target, size);
    return indices; }
int main()
{
    int L[] ={1, 2, 3, 10, 10, 10, 12, 12};
    int target = 10;
    int size = sizeof(L)/ sizeof(L[0]);
    int indices[2];

    int *res = binary_search_deluxe(L, target, size, indices);
    printf("Leftmost index: %d\n", res[0]); 
    printf("Rightmost index: %d\n", res[1]); 

    return 0;
}