#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node{
    int value; 
    int priority;
    struct Node* next;
}Node;

typedef struct priorityQueue{
    int size;
    Node *head;
    int back;
    int front;
}priorityQueue;

void __init__(priorityQueue *pq)
{
    pq->head = NULL; 
    pq-> size = 5;
    pq->front = 0;
    pq->back = 0;
    //can't tell if i need this or not. I'm fine with just initializing in my main function
}
// every element you have has a priority when you define it. You could make it into a linked list. 
// or you could manually sort your queue each time. 

void append_element(struct priorityQueue *pq, int value, int priority)
{
    //1 we create our element. 
    struct Node *new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->priority = priority;
    new->next = NULL;

    //now instead of an index, you're going to append it based on priority but traverse through the list the same way. 
    if (pq->head == NULL)
    {
        //empty just add it to the front. 
        pq->head = new;
        pq->back++;
    }
    if (pq->back == pq->size)
    {
        printf("Full Capacity. Try again later");
        exit(1);
    }
    else
    {
        Node *cur = pq->head;
        // a while loop might be better than a for loop .
        while (cur->next != NULL && cur->next->priority >= priority)
        {
            cur = cur->next;
        }
        new->next = cur->next;
        cur->next = new;
        pq->back++;
    }
}

int dequeue(priorityQueue *pq)
{
//you have it sorted from most priority to least priority already. You 
// just need to remove the last node and then you need to decremenet the 
//back.
    if (pq->front == pq->size)
    {
        printf("Undercapacity");
        return -1;
    }
    Node *temp = pq->head; 
    int val = temp->value;
    pq->head = pq->head->next;
    free(temp);
    pq->front++;
//idk hoow to remove the first element of the pq.9-p 
    return val;
}

void print_queue(priorityQueue *pq) {
    Node* current = pq->head;
    while (current != NULL) {
        printf("(Val: %d, Prio: %d) -> ", current->value, current->priority);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    priorityQueue pq;
    __init__(&pq);

    append_element(&pq, 10, 2);
    append_element(&pq, 5, 5);
    append_element(&pq, 7, 1);
    append_element(&pq, 15, 3);

    print_queue(&pq); // should print in order of priority

    printf("Dequeued: %d\n", dequeue(&pq));
    print_queue(&pq);

    return 0;
}
