// in this implementation i dont use a pointer to the rear node
// as a result the dequeue function is O(n) time complexity, not O(1)

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

    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

node_t *createNode(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *enqueue(node_t *head, node_t *node)
{
    node->next = head;
    return node;
}

node_t *dequeue(node_t *head)
{
    node_t *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 10; i++)
    {
        tmp = createNode(i);
        head = enqueue(head, tmp);
    }

    printList(head);
    head = dequeue(head);
    printList(head);
    tmp = createNode(10);
    head = enqueue(head, tmp);
    printList(head);

    return 0;
}