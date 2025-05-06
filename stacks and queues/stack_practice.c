#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct stack{
    int *array; 
    int size; 
    int back; 
}stack; 

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

void __init__(stack **a_stack)
{// you only need to allocate memory for one stack struct
    *a_stack = (stack *)malloc(sizeof(stack)); //you're not goint to increase the size. 
    (*a_stack)->size = 5;
    (*a_stack)->back = 0; 
    (*a_stack)->array = (int *)malloc(sizeof(int)*(*a_stack)->size);
}
void push(stack **a_stack, int elem)
{
    //you're going to add your elements in the end until it's full and then return an error. 
    if ((*a_stack)->back == (*a_stack)->size)
    {
        printf("Your stack is full");
        exit(1);
    }
    (*a_stack)->array[(*a_stack)->back] = elem; //make sure your back or front is always accompanied by (*a_stack)
    (*a_stack)->back++; 
}

void pop(stack **a_stack)
{
    //apparently you don't need to set somethng to zero... when you decrease the back, apparently that also works. 

    //(*a_stack)->array[(*a_stack)->back] = None; // apparently you don't need to do this. 
    (*a_stack)->back--;
}
// and then when you are going to push another element, you're going to be overwriting it 
// so apparently iy gets taken care of. 



//Question 2: createing a stack w linked lists.

//everytime you're going to push, you think of it as you're creating a node. 
