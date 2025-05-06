#include "inlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void create_list_from_data(IntList **p_IntList, int *data_arr, int size)
{
    *p_IntList = (IntList *)malloc(sizeof(IntList)); // remember you want to use your struct type in your malloc. 
    if (*p_IntList == NULL)
    {
        printf("ERROR: failed to create IntList");
        exit(1);
    }
    (*p_IntList)-> capacity = 100; //order of operations. You awnt to dereference before using capacity...
    (*p_IntList)->data = (int *)malloc((sizeof(int)* ((*p_IntList)->capacity))); // how much space you want to create. 
    (*p_IntList)-> data[size -1] = '\0'; //the size of the array is 3, and you want to add it to the second index/element i think and that's 2. Not quite sure I need this though

    memcpy((*p_IntList) -> data, data_arr, size*sizeof(int)); //memcpy works more when you don't have things that are already in the malloc and don't need to overrride. Memmove is better when you need to override things. 
}

void list_append(IntList *list, int new_elem) // whenever you want to add something to an element. 
{
    if(list ->capacity < list->size + 1)
    {
        int new_capacity = list -> capacity*2; //incase you want to ensure you're not going to run out of memor
        list -> data = (int *)realloc(list -> data, new_capacity * sizeof(int));
        if (list -> data == NULL){
            printf("ERROR: string is too large when appending\n");
            exit(1);
        } //malloc you need to print things, reallocate you don't have to print everything. 
        list -> capacity = new_capacity; 
        list -> size = 1 + list -> size;
    }
    list -> data[list->size - 1] =  new_elem; // we are accessing size and data together which is why you need list twice,
}

/*void list_insert(IntList *list, int new_elem, int index){
    if ((index >= list -> size)||(index < 0)){ // you can't really have an index there... out of bounds
        printf("ERROR: Your %d is out of bounds", index);
        exit(1);
    }
    memmove(& list-> data[index + 1], list ->data[index], size*sizeof(int)-1); // you're going to be shifting in this room. 
}
void list_delete(IntList *list, int index)
{
    memmmove(& list -> data[index], & list -> data[index + 1], size*sizeof(int)-1);
}

//the order in which you free list->data and list
// itself is important (how?). It's like you have to first clear teh garbage cans and then the garbage truck takes
//everything away... if you wait for teh garbage truck to come and clear something before clearning the garbage cans , then that doesn't really work. 
//Similarly, you need ot create het subthings in the malloc first so it kind of goes into the list and it is like a heirarchy in a wya. 
void list_destroy(IntList *list)
{
    free(list);//is this it?
}*/

