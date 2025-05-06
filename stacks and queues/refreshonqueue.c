#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
    int back;
    int front; 
    int size; 
    int capacity; 
    int array*
};

void init_queue( queue **q)
{
    *q = (queue *)malloc(sizeof(queue));
    (*q)->back = 0;
    (*q)->front = 0;
    (*q)->size = 0; 
    (*q)->capacity = 1;
    (*q)->array = (int *)malloc(sizeof(int)*(*q)->capacity);
}

void enqueue(queue *q, int value)
{

    q->array[q->back] = value; 
    //the place you're adding it to is the one that's going to get wrapped.
    q->size++;

    if (q->size == q->capacity) // you want to do this befor eenqueing again I would like to think. 
    {
        int new_capacity = capacity*2;
        //although not 100% always necessary, good to typecast.
        q->array = (int *)realloc(q->array, new_capacity*sizeof(int));
        // you memmove your front. 
        memmove(&(q->array[q->front - q->new_capacity]), &(q->array[q->capacity- q->front], sizeof(int)*(q->new_capacity - q->front)));
        //although I'm pretty sure my new_capacity should work, might want to keep it using thte tepm thing just because new_capacity is not defined in the 
        //struct whereas capacity is (and we don't really need the old capacity so you can give it a garbage name)
        q->front = q->capacity - q->front;
    }

    q->back = ((q)->back + 1) % (q->capacity);
    // please be carreful. It's the back that's going to get wrapped in enqueue and then it's the front getting wrapped in dequeue. 
}

int dequeue(queue *q)
{
    int dequeued = (q)->array[(q)->front];

    q->size--;
    //q->back = q->back - q->capacity; acctually apparently this doesn't matter
    q->front = ((q)->front + 1) % (q->capacity);
    return dequeued;
}