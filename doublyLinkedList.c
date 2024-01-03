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

// create a node with given value and return it, returns null if error
node_t *createNode(int value)
{
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
// given the head of linked list returns pointer to tail node
node_t *getTail(node_t *head)
{
    node_t *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

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

// prints a list from startNode to last node depending on which function is passed
// if setPrev is passed it will go in reverse and follow prev pointers
// if setNext is passed it will go forward and follow next pointers
void printList(node_t *startNode, node_t *(*setNode)(node_t *))
{

    node_t *temp = startNode;
    while (temp != NULL)
    {
        printf("value: %d\n", temp->value);
        temp = setNode(temp);
    }

    printf("\n");
}

// insert given node at head of list
node_t *insertHead(node_t *head, node_t *node)
{
    if (head != NULL)
    {
        head->prev = node;
        node->next = head;
        node->prev = NULL;
    }

    return node;
}

// finds a node with given value and returns pointer to it
// if cant find the node returns NULL
node_t *findNodeUsingHead(node_t *head, int value)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// inserts a new node after the specified node/
void insertNodeAfter(node_t *nodeToInsert, node_t *nodeToInsertAfter)
{
    nodeToInsert->next = nodeToInsertAfter->next;
    nodeToInsertAfter->next = nodeToInsert;
    nodeToInsert->prev = nodeToInsertAfter;
    nodeToInsert->next->prev = nodeToInsert;
}

// deletes a node with given value
// returns the new head of the list
node_t *deleteNodeUsingHead(node_t *head, int value)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {

            if (temp->prev == NULL && temp->next == NULL)
            {
                free(temp);
                return NULL;
            }

            if (temp->prev == NULL)
            {
                node_t *temptemp = temp->next;
                temptemp->prev = NULL;
                free(temp);
                return (temptemp);
            }

            if (temp->next == NULL)
            {
                temp->prev->next = NULL;
                free(temp);
                return head;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return head;
        }

        temp = temp->next;
    }

    printf("ermm, something aint right!!☝🤓");
    return NULL;
}

int main()
{
    node_t *head = NULL;
    node_t *tail = NULL;
    node_t *tmp = NULL;

    for (int i = 1; i < 16; i++)
    {
        tmp = createNode(i);
        head = insertHead(head, tmp);
    }
    printf("\n");

    tail = getTail(head);

    printList(head, setNext);
    printList(tail, setPrev);

    tmp = findNodeUsingHead(head, 11);
    node_t *randomNode = createNode(69);
    insertNodeAfter(randomNode, tmp);

    printList(head, setNext);
    printList(tail, setPrev);

    head = deleteNodeUsingHead(head, 13);

    printList(head, setNext);
    printList(tail, setPrev);

    return 0;
}