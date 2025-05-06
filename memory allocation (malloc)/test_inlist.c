#include <stdio.h>
// #include "lab5.c"
#include "inlist.h"


int main()
{
    IntList *p_IntList;
    int arr[4] = {2,4,6};
    int size = 3;
    create_list_from_data(&p_IntList, arr, 3); //the size of the array
    printf("array\n ");
    for (int i = 0; i < 3; i++) // I think capacity beacuse it's teh "size of teh block"
    {
        printf("%d ", (p_IntList -> data)[i]);
    }

    //Question 2: 
    list_append(p_IntList, 8);
    printf("new array\n: ");
        for (int i = 0; i < 3; i++) // I think capacity beacuse it's teh "size of teh block"
    {
        printf("%d ", (p_IntList -> data)[i]);
    }
    return 0;
}
