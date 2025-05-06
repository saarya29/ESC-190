#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int data; 
    struct Node* next; 
}Node;


struct Node* mergeLinkedList(struct Node* L1, struct Node* L2) {
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    // Save next pointers
    struct Node* next1 = L1->next;
    struct Node* next2 = L2->next;

    // Alternate
    L1->next = L2;
    L2->next = mergeLinkedList(next1, next2); // Recursive call with next nodes

    return L1; // Always return the current L1 as head of merged
}


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Helper to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Example test in main
int main() {
    // First sorted linked list: 1 -> 3 -> 5
    struct Node* L1 = createNode(5);
    L1->next = createNode(3);
    L1->next->next = createNode(7);

    // Second sorted linked list: 2 -> 4 -> 6
    struct Node* L2 = createNode(2);
    L2->next = createNode(4);
    L2->next->next = createNode(5);
    L2->next->next->next = createNode(1);
    L2->next->next->next->next = createNode(3);
    L2->next->next->next->next->next = createNode(2);

    printf("List 1: ");
    printList(L1);
    printf("List 2: ");
    printList(L2);

    // Merge the lists
    struct Node* merged = mergeLinkedList(L1, L2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}