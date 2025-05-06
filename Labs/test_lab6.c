#include "lab6.c"
#include <stdio.h>

int main()
{
    LL my_list;
    //you need to define the different parts of my_list as head and size. 
    my_list.head = NULL;
    my_list.size = 0;
    
    LL_append(&my_list,10);
    LL_append(&my_list, 20);
    LL_append(&my_list, 30);
    LL_append(&my_list, 40);
    LL_print(&my_list);
    validate_list_length(&my_list, 4);
    LL_print(&my_list);
    delete_node(&my_list, 2); //i think the 30 will be gone. 
    LL_print(&my_list);
    return 0;
}//I am pretty sure I did this correctly. Not quite sure why it doesn't print. 
