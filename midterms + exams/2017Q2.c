#include <stdio.h>



struct Node{
    int data; 
    struct Node* next;
};

float averageNodeList(struct Node *L, int *n)
{

    if (L == NULL) // in general
    {
        return 0.0; //assuming that n keeps track of how many nodes there are.
    }
    //I am going to insert the node which keeps track of what the sum is and then we divide it all at the end. 

    (*n)++;
    float sum = (L->data) + averageNodeList(L->next, (n)); //hopefully. 
//and then you compute the average based off what n is since this is only the sum. 
}




///Question3: 

struct Node{
    int data; 
    struct Node * lChild;
    struct Node * rChild; 
}

int sumBST(struct Node*root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0; // I am thinking we can have dfs recursion or we can have dfs. 
    if (root->data > 10)
    {
        sum = root->data;
    }
    //the reason you want this outside the for loop is because if you don't have a root that is greater than 10 
    // then it's not going to recurse, and so for our case, it would be false. 
    sum += sumBST(root->lChild);
    sum += sumBST(root->rChild);
    return sum;
}
// this is an example of dfs recursion



//Question 4: 

#define NODES 6
struct adjMat{
    int matrix[NODES][NODES];
    int vNodes[NODES];
};
struct Data{
    int value;
};

struct Stack * initStack();
void push(struct Stack * s, struct Data d);
struct Data pop(struct Stack * s);
int isEmpty(struct Stack * s);
void deleteStack(struct Stack * s); 

void dfTraversal(struct adjMat aN, int n)
{
    int visited[NODES] = {0};

    struct Stack *stack = createStack(); 

    while (!isEmpty(stack))
    {
        struct Data curr = pop(stack);
        int currLabel = curr.value; 

        if (!visited[currLabel])
        {
            visited[currLabel] = 1;
            printf("%d", currLabel);
            //print hte node as it is being traversed. 
        }
        for (int j = NODES - 1; j >= 0; j--)
        {
            if (aN.matrix[currLabel][j] && !visited[j])
            {
                struct Data next; 
                next.value = j;
                push(stack, next);
            }
        }
    }
    // at the very end of it all, you're going to free everything
    deleteStack(stack);
}




//2016 QUestion 2: 
struct Node{
    int data; 
    struct Node *lChild; 
    struct Node *rChild; 
}

//whenever it asks to return a pointer, you have to return like this. 
struct Node* insertnode(struct Node* root, int value)
{
    if (root == NULL)
    {
        struct Node* new_child = ( struct Node *)malloc(sizeof( struct Node));
        if (new_child == NULL)
        {
            exit(1);
        }
        //you're going to have to create hte node.
        new_child->data = value;
        new_child->rChild = NULL; 
        new_child->lChild = NULL; 
        return new_child; // this is what's actually going to get returned in the end
        //becaue it's inside the if loop that is not going to get accessed until the very end. 
    }
    // you need to define that it's a struct Node, not just a a node. 
    
 
    //you would have to traverse until you find a right or left that is
    //greater than or less than what you have.
    //there are small loigc things although most of it makes sense.  

    if (value > root->data) // you can recurse through the left or else you can recurse through the right. 
    {
        root->rChild = insertnode(root->rChild, value);
    }
    else
    {
        root->lChild = insertnode(root->lChild, value);
    }
    //this is the vase if the root we are looking at is NULL. 
    return root;
    //what pointer should I be returning and how do I exactly do that. 
}
