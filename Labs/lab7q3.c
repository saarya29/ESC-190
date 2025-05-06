#include <stdio.h>


//classes in python are similar to structs in C
typedef struct queue{
    int size; //C does not allow initializations to be made inside structs
    int array[5]; //arbitrarily set. This is going to be the max number of integers I can have in my queue
    int back; 
    int front;
}queue;

void init_queue( queue *q)
{
    q->front = -1;
    q->back = 0;
    q->size = 5; //i am pretty sure this is where I would initialize my function
}

int is_full(queue *q)
{
    return(q->back == q->size);
}

int is_empty(queue *q)
{
    return(q->front == q->back);
}

/*int is_empty() //should it be queue? Or Int?
{
    for (int i = 0; i< size; i++)
    {
        if (array[i] == " ") //meaning it's empty at the moment
        {
            i ++;
            if (i == size) //you've reached the end
            {
                return True; //empty
            }//else hopefully it's going to just continue through the for loop
        }
        return False; 
    }
}*/
//apparently from another algorithm, you have to initislize your front as read - 1
//and then an efficient way of implementing rear is front == rear - 1

void print_queue(queue *q)
{
    printf("Queue: ");
    for (int i = q->front; i < q->back; i++) {
        printf("%d ", q->array[i]);
        }
        printf("\n");
}

void enqueue(queue *q, int new_elem)
{
    if (is_full(q)) //i think it's full?
    {
        printf("Not enough space in the queue\n");
        return; //you cannot do anything
    }
    q->array[q->back] = new_elem;  //remembre you still need ot go into your array which is declared inside a struct
    q->back ++; // i think we initialize what back is in initmain but i'm not sure if you can still get that value from there. 
    print_queue(q); 
    //rationale behind q->back is because you can't increase the size.... you do have to increase the index that you are backing from... 
}


void dequeue(queue *q)
{
    if (is_empty(q))
    {
        printf("There are no elements to delete in this queue\n");
        return; //similar to is_full. 
    }
    //q->array[q->front]; you don't need to write this because you're not adding or anything. You don't need to look at it anymore. Although ig you can keep it?
    q->front ++; //your new front is now 1 ahead. 

    if (q->front == q->back)
    {
        q->front = 0;
        q->back = 0;
    }
    print_queue(q);
}

int main() {
    queue q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    //enqueue(&q, 50); // Last valid insertion
    //enqueue(&q, 60); // Should print "Not enough space in the queue"

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}