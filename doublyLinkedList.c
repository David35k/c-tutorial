#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node node_t;

node_t *createNode(int value)
{
    // create a node with given value and return it, returns null if error

    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->value = value;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }

    printf("couldnt allocate memory bozo");
    return NULL;
}

// since working with a doubly linked list the tail is actually useful
node_t *getTail(node_t *head)
{
    // given the head of linked list returns pointer to tail node

    node_t *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    printf("%d", temp->value);

    return temp;
}

node_t *setPrev(node_t *node)
{
    return node->prev;
}

node_t *setNext(node_t *node)
{
    return node->next;
}

void printList(node_t *startNode, node_t *(*setNode)(node_t *))
{
    // prints a list from startNode to last node depending on which function is passed
    // if setPrev is passed it will go in reverse and follow prev pointers
    // if setNext is passed it is the opposite

    node_t *temp = startNode;
    while (temp != NULL)
    {
        printf("value: %d\n", temp->value);
        temp = setNode(temp);
    }
}

node_t *insertHead(node_t *head, node_t *node)
{
    // insert given node at head of list

    head->prev = node;
    node->next = head;
    node->prev = NULL; // making sure
    return node;
}

int main()
{
    node_t *head = NULL;
    node_t *tail = NULL;
    node_t *tmp = NULL;

    for (int i = 0; i < 15; i++)
    {
        tmp = createNode(i);
        head = insertHead(head, tmp);
    }

    // tail = getTail(head);

    printList(head, setNext);

    return 0;
}