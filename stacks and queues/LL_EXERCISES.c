#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab6.h"

void create_node(int n)
{
    //FUN FACT: the reason we have to declare it in the code is because we're not passing it as an argument. QUESTION: when do we know to pass it as an argument and when not to? Since we've done it both ways?
    node *new_node = (node *)malloc(sizeof(node)) //could also do sizeof
    new_node->data = n;
    new_node->next = NULL;
}

void insert_node(LL **p_ll, int new_elem, int index)
{
    node *n;
    create_node(new_elem);

    if (my_list->head == NULL) //the first thing and it's empty
    {
        my_list->head = n;
        my_list->size++ //you have to do this to incrememnt your size when you add something regardless. 
        return;
    }

    else
    {
        if (index == 0)
        {
            n->next = my_list->head; //the next of the list is going to be the head meaning that's going to be the satrat of the list. 
            my_list->head = n;
            my_list->size++; //that's it. 
        }
        else //the index is kind of like anywhere but the middle. 
        {
            node *cur = my_list->head; // initialize a pointer to the head of the list.
            for (int i = 0; i < index; i++)
            {
                cur = cur->next; 
            }
            n->next = cur->next;
            cur->next = n;
            my_list->size++;
        }
    }


}
