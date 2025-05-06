#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Queue ADT (abstract data type)

//Queue : a list with FIFo (first in first out) operations. 
            //--random access: ability to get any element by index. 

//operations: 
//enqueue: add an element to the end of the queue. 
//dequeue: remove the first element from the queue.

//LOOK AT TEH LAB HANDOUT FOR A VISUAL REPRESENTATION OF HOW ENQUEUE WORKS. 


void reverse_queue(queue **q_block, queue **temp){
    *temp = (queue *)malloc(sizeof(queue));

    (*temp)->size = (*q_block)->size;
    (*temp)->capacity = (*q_block)->capacity;
    (*temp)->array = (int *)malloc(sizeof(int)*((*temp)->capacity));
    for (int i = ((*q_block)->size - 1), j = 0; i >= 0; i--, j++)
    {
        (*temp)->array[j] = (*q_block)->array[i]; //you're pointing to a specific element in your array. this is how you're supposed to do it. 
    }
    //if you still want to incorporate the wrap around technique
    (*temp)->front = 0;
    (*temp)->back = (*temp)->size % (*temp)->capacity;
}


int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void sort_queue(queue **q_block)
{
    // you need to flatetn out our circular queue to maintain proper order. You have to do this by creating 
    //a temp block.
    if (q->front != 0) {
        int *temp = malloc(sizeof(int) * q->size);
        for (int i = 0; i < q->size; i++) {
            temp[i] = q->array[(q->front + i) % q->capacity];
        }
        memcpy(q->array, temp, sizeof(int) * q->size);
        free(temp);
        q->front = 0;
    }
    qsort((*q_block)->array, (*q_block)->size, sizeof(int), compare);
    (*q_block)->back = (*q_block)->size % (*q_block)->capacity;
}

int find_max(**q_block)
{
    int current_max = (*q_block)->array[0]; // or some ridiculously large number,
    for (int i = 1; i < (*q_block)->size; i++)
    {
        if ((*q_block)->array[i] > current_max)
        {
            (*q_block)->array = current_max;
        }
    }
    return current_max;
}

//This would work for a queue, but for a circular queue, you need to account for wrapping. 
int find_max2(**q_block)
{
    int max = (*q_block)->array[(*q_block)->front]; //you start everything at your front.
    int i = (*q_block)->front;
    //you now have to iterate through front and back so the wrapping can be handled. 
    while (i != (*q_block)->back)
    {
        if ((*q_block)->array[i] > max)
        {
            (*q_block)->array[i] = max; // this is the same as regular queues. 
        }
        i = (i + 1) % (*q_block)->capacity;
    }
        // Check the last element (back element)
    if (q->array[q->back] > max) {
        max = q->array[q->back];
    } // because of the wrapping around nature, you need to account for your back case separately. 
    return max;
}