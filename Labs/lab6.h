#if !defined(LAB6_H)
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

//from lecture: LL will contain the head pointers; the address of the first node. 
/// in The linked list 

//Each node has data, as well as the address of the next node. 

     // 123->567->123->NULL
    //  ^
   // |
// LL[head, size]

//the 567 node is the data 567, and the address of teh 213 node 
#endif
    