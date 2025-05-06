#include <stdio.h>


//Question 1
int linear_search(int *a, int sz, int elem)
{
    for (int i = 0; i<sz;i++) // don't want to include the null character which is why you have < and not <=
    {
        if (a[i] == elem)
        {
            int index = i;
            return index; // you don't need to go further, although you can always wait till the end i suppose.
        }
    }
    return -1; // if it doesn't find anything. Once again, since 0 holds 'value' in C, it's better to write -1 when you have an actual error. 
}

void reverse_arr(int *arr, int sz)
{
    int i = 0;
    int j = (sz - 1); //this should work
    while (i<=j) //if it's an odd then they equal i think you want it to say. 
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i ++;
        j--;
    }
    /*for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }*/
//i think you can return arr altogether because you're making the changes to the same array as opposed to making another array.
    
}

int main()
{
    int a[] = {0,0,3,5,9,2,7,2};
    int elem = 2;
    int sz = sizeof(a)/sizeof(a[0]);
    int result = linear_search(a,sz,elem);
    //printf("%d\n",result); 
    //Question 2
    reverse_arr(a, sz); // you cannot initialize something when its caller function is a void because there is nothing being returned that the main function can use.
//you can't print things when you have a void function. But you can print things directly in the function itself if you want to double check
    return 0;
}