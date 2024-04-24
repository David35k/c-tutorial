#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

// keeps track of the top-most element in the stack (its index)
// -1 means the list is empty
int top = -1;

struct node
{
    int data;
    struct node *next;
};

typedef struct node node_t;

node_t *stack[STACK_SIZE];

// push a node onto the stack (its address)
void push(node_t *node)
{
    top++;
    if (STACK_SIZE <= top)
    {
        printf("yo, the stack is full, can't push");
        return;
    }
    stack[top] = node;
}

// pop a node off the stack
void pop()
{
    if (-1 >= top)
    {
        printf("yo dude, the stack is empty, cant pop");
        return;
    }
    top--;
}

void printList(node_t *head)
{
    // prints out the values of each node in order

    node_t *temp = head;

    // n1.next = NULL so it will stop after the last element very gud
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n"); // pwetty fowmatting :3
}

// reverse list
// returns the new head of the linked list
node_t *reverse(node_t *head)
{
    printf("reversing!!\n");
    if (head == NULL)
    {
        printf("yo dude, head is null");
        return;
    }

    node_t *temp = head;

    while (NULL != temp)
    {
        push(temp);
        temp = temp->next;
    }

    // lesson learned!!
    // at first i thought the below code wouldnt work without the initial pop() call befor the while loop
    // however, it works even without it because the head->next just gets reassigned, this means that
    // there is no double 0 at the start like i thought there would be
    // however it is better to keep it there to reduce the amount of times the loop is called

    head = stack[top];
    temp = stack[top];
    pop();
    while (-1 < top)
    {
        temp->next = stack[top];
        temp = temp->next;
        pop();
    }
    temp->next = NULL;

    return head;
}

// linked list shinenigans

node_t *createNode(int data)
{
    // creates a node with specified value and next pointer of NULL

    node_t *result = malloc(sizeof(node_t));
    result->data = data;
    result->next = NULL;
    return result;
}

node_t *insertHead(node_t *head, node_t *node)
{
    node->next = head; // make the new node in front of current head
    return node;
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    // this adds a new nodes at the start of the list
    for (int i = 0; i < 20; i++)
    {
        tmp = createNode(i);          // create a new node
        head = insertHead(head, tmp); // set head to the new node
    }

    printList(head);

    head = reverse(head);

    printList(head);

    return 0;
}