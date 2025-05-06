#include <stdio.h>

void set_even_to_zero(int *block, int size)
{
    for (int i = 0;i<size;i++) // you don't want the = sign because it's going to make it go out of bounds. 
    {
        if (i % 2 ==0) // you cannot apply a modulo directly to a pointer. Also in this question, you're looking at EVEN INDICES.
        // ON THAT NOTE, HOW WOULD YOU WRITE THIS FOR EVERY EVEN NUMBER, CHANGE IT TO 0... GIVEN INT *BLOCK??
        {
            block[i] = 0; //you've already initialized it in the arguments... don't have to again.
            //IMPORTANT NOTE: when you're passing an array to a function, you need to use pointers. 
        }
    }
}

int main()
{
    int arr[] = {5, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]); //if multiple choice question. Could you find the sie of an array generically. 
   //always put your sizeof function in the same function you created your array. Alternatively, can hardcode it to a number. 
    set_even_to_zero(arr,size);
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
    return 0;
}