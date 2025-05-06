#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//when you have enqueue, you're going to move the end. When you have dequeue, you're going to move the start.

typedef struct queue{
    int size; //not sure I really need this anymore, along with capacity. 
    int *array;
    int capacity;
    int front;
    int back;
}queue;

void init_queue( queue **q_block)
{
    //you would have to initialize your malloc in here... this is the amount of size i am estimating the size to be. 
    *q_block = (queue *)malloc(sizeof(queue));
    if (*q_block == NULL)
    {
        printf("Error in allocating memory");
        exit(1);
    }
    (*q_block)->size = 0;
    (*q_block)->capacity = 1; //enough for one element;
    (*q_block)->array = (int *)malloc(sizeof(int)* (*q_block)->capacity);
    //the reason why you want to create a malloc as an array is becuase if oyu used a fixed size
    //which you could also do, you may not end up using all the space as initialized, and then you're
    //going to be wasting memory. 
    (*q_block)->front = 0;
    (*q_block)->back = 0;
}
//since I'm going to include front and back, i'm going to need the is full and isempty. 
//i doubt this stuff would really change. 


int is_empty(queue *q_block)
{
    return q_block->size ==0;
}

void print_queue(queue *q)
{
    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d", q->array[(q->front + i) % (q->capacity)]); // even when printing, you need ot make sure you are still wrapping aroud. Or else it will just print the first index. 
        printf("-> ");
        }
    printf("\n");
}

void enqueue1(queue *q_block, int elem)
{
    
    (q_block)->array[(q_block)->back] = elem;
    (q_block)->size++; //you always need to increment your size.
    if (q_block->size == q_block->capacity)
    {
                //you need to reallocate in here. You already have your malloc hopefully. 
        int temp = (q_block)->capacity;
        (q_block)->capacity *=2; //similar to what we learnt in class. 
        (q_block)->array = (int *)realloc((q_block)->array, sizeof(int)*(q_block)->capacity);
        //and then you have to insert your elements
        memmove(&(q_block->array[q_block->capacity - q_block->front]), &(q_block->array[temp - q_block->front]), sizeof(int)*(q_block->capacity - q_block->front));
        //q_block->capacity - q_block->front is now your new front. 
        q_block->front = q_block->capacity - q_block->front;
    }

    
    (q_block)->back = ((q_block)->back + 1) % (q_block)->capacity;
    print_queue(q_block);
}

//you always need to free your block. 
void free_queue(queue *q_block)
{
    free(q_block->array);
    free(q_block);
}


int dequeue1(queue *q_block)//you're going to delete from your first element... you can use memove. 
{
    int dequeued = (q_block)->array[(q_block)->front];
    //i don't want to overwrite so maybe not memmove. 


    (q_block)->front = ((q_block)->front + 1) % (q_block)->capacity;
    (q_block)->size--;
    /*//if ((*q_block)-> front == (*q_block)->back) //this basicallmeans that it's empty although this is such a long way of doing it. 
    if ((*q_block)->size== 0);
    {
        (*q_block)->front = 0;
        (*q_block)-> back = 0;
    }*/
    print_queue(q_block); //review note: when you're removing a pointer, you have to dereference it by giving a pointer. When you want to add a pointer, you have to use the ampersand.
    return dequeued;
}


int main()
{
    printf("Hello World!");
    
    queue *q_block;
    init_queue(&q_block);
    enqueue1(q_block, 5);
    enqueue1(q_block, 10);
    enqueue1(q_block, 15);
    enqueue1(q_block, 20);
    enqueue1(q_block, 25);
    printf("%d ",dequeue1(q_block));
    printf("%d ",dequeue1(q_block));
    printf("%d ",dequeue1(q_block));
    printf("%d ",dequeue1(q_block));
    printf("%d ",dequeue1(q_block));
    return 0;

}
