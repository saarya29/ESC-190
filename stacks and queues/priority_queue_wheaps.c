// a binary heap is a binary tree where each node is either smaller 
//or larger than its children (min or max heaps respectively.)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct PriorityQueue{
    int items[MAX];
    int size;
}PriorityQueue;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue *pq, int index) //this for insertion
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (pq->items[parent] > pq->items[index])
        {
            swap(&pq->items[parent], &pq->items[index]);
            index = parent;
        }
        else 
        {
            break;
        }
    }
}

// do need practice qith this but I believe this is a generic thing for heaps. 


//you're still going to have a queue implementation. 
 void enqueue(PriorityQueue *pq, int value)
 {
    if (pq->items == MAX)
    {
        printf("Priority Queue is Full!");
        exit(1);
    }
    pq->items[pq->size++] = value;
    heapify(pq, pq->size - 1);
}

///what's different between queue and priority queue is that you need a swapping function. 

void heapdown(PriorityQueue *pq, int index)
{
    int smallest = index; 
    int left = 2 * index + 1;
    int right = 2 * index +2;

    if (left < pq->size && pq->items[right] < pq->items[smallest])
    {
        smallest = left;
    }

    if (right < pq->size && pq->items[right] < pq->items[smallest])
    {
        smallest = right; 
    }

    if (smallest != index)
    {
        swap(&pq->items[index], &pq->items[smallest]);
        heapdown(pq, smallest);
    }

    int dequeue(PriorityQueue *pq)
    {
        if (!pq->size)
        {
            ("Priority Queue is Empty");
            exit(1);
        }

        int item = pq->items[0];
        pq->items[0] = pq->items[pq->size - 1];  // move last to root
        pq->size--;
        //pq->items[0] = pq->items[--pq->size]; //FIFO I believe what you're adding and that's just the size, but then you have to go the other way for dequeu??
        // not 100% sure. 
        heapdown(pq, 0);
        return item;
    }

    int peek(PriorityQueue *pq)
    {
        if(!pq->size)
        {
            printf("Priority Queue is Empty");
            return -1;
        }
        return pq->items[0];
    }
}


///In python, when you have heapq you're going to need to importn
// heapq module so that it can let you implement a heap

// heapq.heappush allows you to add the elements while maintingin
// an __ORDER_BIG_ENDIAN__
// heap.heappop allows you to remove the smallest element 

// after all that, you peek at the smallest element in 0(1)
// You want that the collection with the lowest priority item is always quickly accessible. 