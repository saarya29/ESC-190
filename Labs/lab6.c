#include "lab6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//when you need to append a node to a linked list, you first need 
//create the node, which is going to point to a value and then you need to 
//append it to the nodes. You're going to need a while loop for
//sure until you reach the Null character. 

void LL_append(LL *my_list, int new_elem)
{
    //1st we create a node. 
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_elem; //what you choose in your main function
    new_node->next = NULL;

    if (my_list->head == NULL)
    {
        my_list->head = new_node; //if the list is empty, you need to set the head to the new node. The new node is the reulsts. 
    }
    else //if it's not the first node, then we need to have this domino effect where each node kind of have to override in a way. 
    {
        node *current_node = my_list->head; //you start at the head of the list (from the newest till the oldest)
        while (current_node->next != NULL)
        {
            current_node = current_node->next; //you have to move to the next node.
        }
        current_node->next = new_node; //this is at the end where you're at the final onde and you need to make the new_node. 
    //you might also have to add the next of that to be the Null

    //The only difference between inserting at the end and inserting it in the midddle is when you insert it in the middle, you need this gap that's not null so you need to connect your nexts. 
    //cur->next = n; Otherwise, at the end it remains as null so it's the equivalent of saying agin cur->next = NULL. 
    }
    my_list->size++; //i think i have to memorize this from last time. 
    
}

void LL_print(LL *my_list) 
{
    node *current = my_list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int validate_list_length(LL *my_list, int recorded_length)
{
    //we know for every value in the linked list, it has a next and a datat itself. We can either count one of the nexts or we can count the data. We need to travese through the list. 
    int count = 0;
    node *current = my_list->head;
    //RECALL: the "head" acts as the entry point or the starting point of the lnked list. It allows you to access the entire list
    while (current != NULL)
    {
        count ++; 
        current= current->next;
    }
    if (count == recorded_length)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void delete_node(LL *my_list, int index)//could we use something like memmove which will just override everything. 
{
    if (my_list->head == NULL || index < 0) //you have an empty list or you're out of bounds somehow... 
    {
        return; //ERROR
    }
    node *temp = my_list->head; //usually when you have to remove things, it's a smart idea to have a temp because that way
    //we're not going to making a direct impact on the actual list. 

    if (index ==0)
    {
        my_list->head = temp->next;
        free(temp);
        my_list->size--;
        return;
    }
    //what if you need to find the previous node. 
    node *prev = NULL;
    for (int i = 0; i<index && temp != NULL; i++) //we want i to stop when we're at the index to be deleted. it's not actually anywhere in the function
    {
        prev = temp;
        temp = temp->next; //that's teh one you actually want to delete. So the next of temp is the data of the one to be deleted and at the moment, we're saying that temp is the previous one. 
    }
      //you're stopping one before!! It's not equal. 
    prev->next = temp->next;
    my_list->size--;
    free(temp);
}
//temp points at the index we want to delete whereas prev points at the endex right before. 