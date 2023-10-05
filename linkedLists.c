#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node node_t;

void printList(node_t *head) {
    node_t *temp = head;

    // n1.next = NULL so it will stop after the last element very gud
    while(temp != NULL) {
        printf("%d - ", temp->value);
        temp = temp->next;
    }

    printf("\n"); // pwetty fowmatting :3
}

int main() {
    // three nodes in the list
    node_t n1,n2,n3;
    node_t *head; // head of the list so we know where the list starts

    n1.value = 69;
    n2.value = 420;
    n3.value = 14;

    // link them together
    // going to put them in order 2,3,1 (420,14,69)
    head = &n2;
    n2.next = &n3;
    n3.next = &n1;
    n1.next = NULL; //so we know when to stop

    printList(head);

    // reorder them
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    printList(head);

    // add a new node somewhere in the middle
    node_t n4;
    n4.value = 11;

    n2.next = &n4;
    n4.next = &n3;
    
    printList(head);

    return 0;
}