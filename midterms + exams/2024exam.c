#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void f(int *p)
{
    *p = 42;
}

int sum_odd(int *arr, int n){
    int sum = 0;
    for (int i = 0; i<n; i++)
    {
        if (arr[i] %2 !=0)
        {
            sum += arr[i];
        }
    }
    return sum;
}
//qsorts always need a helper function. 
int compare(const void *a, const void *b)//qsort always prefers void... int and it's going to give you an error. 
{
    return (*(int *)a - *(int *)b);
}
void increasing_order(int *arr, int n){
    int *term = (int *)malloc(n*sizeof(int));
    for (int i = 0; i<n; i++)
    {
        term[i] = arr[i]; //this is going to add the block of the array into the malloc. 
    }
    qsort(term, n, sizeof(int), compare);

    for (int i = 0; i < n; i++){
        printf("%d",term[i]);
        if (i < n - 1){
            printf(",");
        }
    }
    free(term);
}


int main(){
    int a = 43;
    printf("%d\n", a); //43
    f(&a);
    printf("%d\n", a); //recognizing that when you have hte pointer, it changes it such that you can see i tafterwards. 
      //the second one would print 42.

    //Question 2: What I need to call
    int arr[6] = {4,3,2,1,5};
    int n = sizeof(arr)/sizeof(arr[0]); //you should always make the sizing where you create teh array. It's always the smaller amount on the bottom. Please don't forget. 
    int res = sum_odd(arr, n);
    printf("The sum is %d\n", res);
    increasing_order(arr, n);
    return 0;  

}