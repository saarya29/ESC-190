#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node{
    int val; 
    struct Node* next; 
}Node; 

void moveToEnd( Node ** front, Node ** end, int k)
{
    if (k <= 0 || *front == NULL || *front = *end)
    {
        Node * curr = *front;
        Node *prev = NULL;
    }

    for (int i = 0; i<k; i++)
    {
        if (curr == NULL)
        {
            return;
        }
        prex = curr; 
        curr = curr->next;
    }

    Node *oldFront = *front; 
    Node *oldEnd = *end;

    (*end)->next = oldFront;
    *end = prev;
    (*end)->next = NULL;
    *front = *curr;
}
// The reason you want to have a double pointer is so yo can 
// actually modify the head (front) and the tail(end) pointers 
// outside of the function. 

// You know from linked listst that you need to make them into a 
// single pointer when creating. 
// But now we already have a linked list. (almost like a list of pointers)
// and we want to be able to change things and add thiings so while (are d)
// are essentially dealing with its memory. 

// That's why we need to use a double pointer.


// Recap: a copy of the front pointer is passed when you provide a 
// single start. If you change it, the original stays the __SIG_ATOMIC_TYPE__
// In node **, you're passing teh address of the pointer, so it changes
// to update the original pointer from the calling code. 


// I guess some assumptions we're making about k is that
// it's not less than 0. It is not greater than or equal to the 
// size of hte list because if it is then this idea is counterproductive
// although it might still be able to work. 



//Question 4: Binary Search Tree

// you're trying to construct a tree but for them, you
//also want them to be connected together.

struct Node2 {
    int min, max:
    Node *next; 
    Node *left; 
    Node *right;
};

//1. Will create a min/max
//node is  the linked list, which we know. You want to return a part of the tree, which is why you're going to get Node called 

Node *buildPF (Node * front)
{
    if (!front || front->next)
    {
        return front; //you're done. 
    }
// the front is actually the top. If you only have one thing
// or no nodes, then you're at the top and there is no paiiring which 
// is why there is not going to be a front. 
    
    //first we need to creat the list. 
    //yoou need a dummy node to build the new level
    Node dummy(0);
    Node* tail = &dummy;
    // you want to make a new list of only the parents
    //like ([3], [7], etc)

    // The reasoning behind a dummy node is that we don't want
    // to treat the first node separately. 
    //     //Reasoning behind a dummy node: 
    //     when buliding a new linked list (like here)
    //     you usually have moments where you don't really know 
    //     if something is the first node or not. When something is 
    //     going to be the first node, you need to set
    //     head = newNode;

    //     you'd otherwise have to write extra logic for
    //     the first node, like: 
    //     if (head == NULL)
    //     head = newNode;
    //     else: 
    //     tail-> next = newNode; 


    // This is messy. Instea,
    // say: 
    // tail->next = newNode; 
    // tail = newNode;


//     Let’s say you’re merging [1], [2], [3]...

//     Instead of trying to track head, you do this:
    
//     vbnet
//     Copy
//     Edit
//     dummy: [0] → NULL
//     tail: points to dummy
//     Now you add [1]:

// // c
// Copy
// Edit
// tail->next = new Node(1);
// tail = tail->next;
// Now you have:

// vbnet
// Copy
// Edit
// dummy: [0] → [1]
// tail: points to [1]
// return dummy.next;

    while (front && front->next)
    { // you want to traverse two nodes at a time
        Node* a = front;
        Node* b = front->next;
        front = b->next; // you have a new front each time I think?
//the reason two is because you have two chlidren. We're defining only two nodes for that reason. 
//Keep this in mind.

        Node* parent = new Node(a->val + b->val);
        parent->left = a;
        parent->right = b;

            //Add parent to the new list
        tail->next = parent;
        tail = parent;
    }
    if (front)
    {
        //if you have an odd number of nodes, you're going 
        //to append the last one. 
        tail->next = front;
        tail = front;
        front = front->next;
        tail->next = NULL;
    }
    else
    {
        tail->next = NULL;
    }
    return buildPF(dummy.next);
}

//basic idea: you are going to pair two adjacent nodes
// making thme chlidren of a new Node
// That new node's value is the sum of hte two children's val


//Repeat until there is only one node left, which is the root of the tree. 

// 1. Pair up the nodes: 
// [1] + [2] → new node [3] with left = [1], right = [2]

// [3] + [4] → new node [7] with left = [3], right = [4]

// it's this idea that even though they are both smaller 
// than 3, one is bigger so it's going to end up on the
// right while the other one is going to end up on the left. 

// I guess something to keep in mind because many types of questions have something like this. 

// that is going to be your base. Now,  let's create the second base. 
// [3] + [7] → new node [10] with left = [3], right = [7]

// since you only have 1 node ( i guess this is kind of like the base case
// you're going to mkae it the root and return it. )
