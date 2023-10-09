#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

void printList(node_t *head)
{
    node_t *temp = head;

    // n1.next = NULL so it will stop after the last element very gud
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n"); // pwetty fowmatting :3
}

node_t *createNode(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insertHead(node_t *head, node_t *node)
{
    node->next = head; // make the new node in front of current head
    return node;
}

node_t *findNode(node_t *head, int value)
{
    node_t *temp = head;
    while (temp->next != NULL)
    {
        if (temp->value == value)
        {
            return temp;
        }
        temp = temp->next;
    }

    // if the node doesn't exist return NULL
    return NULL;
}

node_t *reverseList(node_t *head)
{
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    // this adds a new nodes at the start of the list
    for (int i = 0; i < 10; i++)
    {
        tmp = createNode(i);          // create a new node
        head = insertHead(head, tmp); // set head to the new node
    }

    printList(head);

    node_t *sus = findNode(head, 4);

    printf("node with value %d is at %p\n", sus->value, sus);

    head = reverseList(head);

    return 0;
}