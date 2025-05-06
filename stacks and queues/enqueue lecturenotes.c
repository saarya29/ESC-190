#if !defined(Q)
#include "ArrayList.h"
#define Q

typedef struct queue {
    AL *list; 
}queue; 

void create_queue( queue **p_q);
void destroy_queue(queue *p);

void enqueue(queue *q, int data);
int dequeue( queue *q);

void create_queue( queue **p_q)
{
    *p_q = (queue *)malloc(sizeof(queue));
    create_list(&((*p_q)->list));
}

void destroy_queue(queue *q)
{
    destroy_list(q->list);
    free(q);
}

void enqueue(queue *q, int data)
{
    insert_list(q->list, data);
}

int dequeue(queue *q)
{
    int ret = q->list->array[0];
    delete_list_ind(q->list, 0);
    return ret;
    //we're basically wrapping the list I think?  
    //these functions I'm pretty sure are form arraylist in lecture notes. 
}
