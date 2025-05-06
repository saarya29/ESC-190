#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab6.h"

void create_node(node **p_n, int data)
{
    *p_n = (node *)malloc(sizeof(node));
    (*p_n)->data = data; 
    (*p_n)->next = NULL;
}

void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;

    node *tail = 0;
    for (int i = 0; i < size; i++) //traversing the list. This is very common I think 
    {
        node *n;
        create_node(&n, data_arr[i]);

        if (tail == 0)
        {
            (*p_LL)->head = n;
        }
        else 
        {
            tail->next = n;
        }
        tail = n;
        (*p_LL)->size++;

    }
}

void LL_insert(LL *my_list, int new_elem, int index)
{
    node *n;
    create_node(&n, new_elem);

    if (my_list->head == NULL)
    {
        my_list->head = n;
        my_list->size++;
        return;  
    }
    if (index == 0)
    {
        n->next = my_list->head;
        my_list->head = n;
        my_list->size++;
        return;
    }

    if (index <0 || index > my_list->size-1)
    {
        fprintf("ERROR: INVALID INDEX");
        exit(1);
    }

    node *cur = my_list->head;
    for (int i - 0; i < index; i++)
    {
        cur = cur->next
    }
    n->next = cur->next; ///you kind of keep on moving it 
    cur->next = n;
    my_list->size++;
    ///To insert at the beginning. The index is telling you where the node wants to be inserted. If it doesn't I guess you can kind of just insert it anywhere. 
}



void gett_i(LL *p_LL, int i)
{
    if (p_LL->size <=i)
    printf("ERROR: cannot get the element");
    exit(1);
}

int j = 0;
node *cur = p_LL->head;
while (j<i)
{
    cur = cur->next;
}
return cur->data;

void append(LL *p_LL, int data)
{//instead of repeating, you could have just called it to create_node. 

    node *cur = p_LL->head; 
    if (p_LL-> head == NULL)
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        p_LL->head = new_node
    }
    while(cur->next != NULL)
    {
        cur = cur->next;
        //nnow cur-> is Null, so you need to replace cur->next with a new node that contains data. 
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        cur->next = new_node;
        p_LL-> size +=1;
        //what happens is p_LL is empty. You need to set p_ll to the new node,becaues there is no current next.  
    }
}