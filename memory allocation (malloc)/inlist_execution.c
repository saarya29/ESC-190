#include "inlist.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void create_list_from_data(IntList **p_IntList, int *data_arr, int size)
{
    //first need to create a malloc
    *p_IntList = (IntList *)malloc(sizeof(IntList));
    if (*p_IntList == NULL)
    {
        printf("There is some sort of error");
        exit(1);
    }
//you create a malloc and then check for malloc failures. 
    (*p_IntList)->capacity = 100; //I'm going to set this because it's a size I want to set
    (*p_IntList)->data = (int *)malloc(sizeof(int)*((*p_IntList)->capacity)); //however much memory you want to have needs to include the capacity. 
    (*P_IntList)->data[size -1] = '\0';

    memcpy((*p_IntList)->data, data_arr, size * sizeof(int));

    // Set size
    (*p_IntList)->size = size;
}//since the data is going to be a malloc of its own you want the size to be of the integers that are in intlist. 
//make sure to manually add the null character at teh end. 

void list_append(IntList *list, int new_elem)
{
    //you always have to check whether the size of the element and the list is good enough compared to the capacity of the list.
    if(list ->capacity < list->size + 1) //I don't think we initialize it here, but I'm going to let the code do its magic mostly because it makes sense. 
    //you need to create more capacity!!!!!!!!

    int new_capacity = list -> capacity*2;
    int *new_data = (int *)realloc(list -> data, new_capacity * sizeof(int));
    //what you are reallocating and the size of what you are reallocating. So new_capacity is the new amount of space you need and then the sie of each is integer based. 
        if (new_data == NULL){
            printf("ERROR: string is too large when appending\n");
            exit(1);
        } //malloc you need to print things, reallocate you don't have to print everything. 
        list -> capacity = new_capacity; 
        list ->data = new_data;
        list -> size++;//same as list->size = 1 + list -> size; //you're increasing the size by 1.
        list -> data[list->size - 1] =  new_elem; // we are accessing size and data together which is why you need list twice,
        //I'm going to trust my prof on the fact that it's size - 1. 
}//data is an array and you want to point it to a specific location in the array. 
    
void destroy_list(IntList *list)
{
    if (list)
    {
        free(list->data);
        free(list);
    }
}

{
    IntList *p_IntList
    int arr[] = {2,4,6,8,9};
    create_list_from_data(&p_IntList, arr, 5);
    return 0;
}