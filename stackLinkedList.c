// stacks - linked lists implementation
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

node_t *top = NULL;

// initialize a node with given value
node_t *createNode(int value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->value = value;
        node->next = NULL;
        return node;
    }

    printf("coudnt create node lawl");
    return NULL;
}

// push a node into the stack
// returns new top of list
void push(node_t *node)
{
    if (top != NULL)
    {
        node->next = top;
    }

    top = node;
}

void pop()
{
    if (top == NULL)
    {
        printf("stack is empty dude, cant pop\n");
        return;
    }

    node_t *temp = top;
    free(top);
    top = temp->next;
}

// prints the stack
void printStack(node_t *startNode)
{
    node_t *temp = startNode;
    printf("stack: top -> ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node_t *tmp = NULL;

    for (int i = 0; i < 5; i++)
    {
        tmp = createNode(i);
        push(tmp);
    }

    printStack(top);

    pop();
    pop();

    printStack(top);

    tmp = createNode(69);
    push(tmp);

    printStack(top);

    return 0;
}