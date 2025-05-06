#include <stdlib.h>
#include <stdio.h>


struct node{
    int value; 
    struct node* next; 
};

typedef struct node node_t;
//Q: what's the difference between struct and typdefed structu

void printlist(node_t *head)
{
    node_t *temporary = head;

    while (temporary != NULL)
    {
        printf("%d -", temporary->value);
        temporary = temporary-> next;
    }
    printf("\n");
}
node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value; 
    result->next = NULL;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    return node_to_insert;
}
void insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
    newnode->next  =node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}
node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
       if (tmp -> value == value) 
       {
        return tmp;
        tmp = tmp-> next;}
    }
    return NULL;
}


int main()
{
    node_t *head = NULL;
    node_t *tmp;
//this is another way i guess you can do it without
//initializing them all into your main. 
//or you can take it one step further. Create a loop

for (int i = 0; i<25; i++)
{
    tmp = create_new_node(i);
    insert_at_head(&head, tmp);
    //it's in the reverse order because when you add things, you're going to add them to the front. In this place, pointers are going to be a benefit because they are going to allow us to keep track of the placements and everything.
}

tmp = find_node(head, 13);
printf("found node with value %d\n", tmp->value);

insert_after_node(tmp, create_new_node(75));
    /*tmp = create_new_node(32);
    head = tmp;
    tmp = create_new_node(8);
    tmp->next = head;
    head = tmp;
    tmp = create_new_node(34);
    tmp->next = head;
    head = tmp;*/

    /*node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    //linking them up
    head = &n1; //you can play around with the orders and how you want to call NULL and all. 
    n3.next = NULL;
    n2.next = &n3;
    n1.next = &n2;

    node_t n4; 
    n4.value = 13;
    n4.next = &n3;
    n2.next = &n4;*/
    printlist(head);
 //making teh head into teh next?????
    //although we don't really use this because we don't know how many notdes we're going to need them. We dynamically allocate them based off malloc. 
    return 0;
}