#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    node_t *next;
} node_t;

// typedef struct node node_t;

void printList(node_t *head) {
    node_t *temp = head;

    // n1.next = NULL so it will stop after the last element very gud
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n"); // pwetty fowmatting :3
}

node_t *createNode(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insertHead(node_t *head, node_t *node) {
    node->next = head; // make the new node in front of current head
    return node;
}

node_t *reverseList(node_t *head) {
    
}

int main() {
    node_t *head = NULL;
    node_t *tmp;

    //this adds a new nodes at the start of the list
    for(int i = 0;i < 10;i++) {
        tmp = createNode(i); //create a new node
        head = insertHead(head, tmp); // set head to the new node
    }

    printList(head);

    head = reverseList(head);

    printList(head);
    
    return 0;
}