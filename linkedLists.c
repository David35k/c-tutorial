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
    // prints out the values of each node in order

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
    // creates a node with specified value and next pointer of NULL

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
    // returns pointer to the node

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

// my own solution yessir!!!
node_t *removeNode(node_t *head, int value)
{
    // removes node with specified value and returns the head of the list

    node_t *temp = head;
    node_t *prev = NULL;

    while (temp != NULL)
    {
        if (temp->value == value)
        {
            // found the node that needs to be removed

            // if it is the only node remove it and return NULL
            if (prev == NULL && temp->next == NULL)
            {
                free(temp);
                return NULL;
            }

            // if it is the head then remove it an make second node the head
            if (prev == NULL)
            {
                node_t temptemp = *temp;
                free(temp);
                return (temptemp.next);
            }

            // if it is the last node just make previous point to NULL
            if (temp->next == NULL)
            {
                free(temp);
                prev->next = NULL;
                return head;
            }

            // if it is a node in the middle remove it and make prev point to next
            if (prev != NULL && temp->next != NULL)
            {
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }

        prev = temp;
        temp = temp->next;
    }
}

void insertAfterNode(node_t *nodeAfter, node_t *nodeInsert)
{
    // inserts a new node after the specified node

    nodeInsert->next = nodeAfter->next;
    nodeAfter->next = nodeInsert;
}

node_t *reverseListIterative(node_t *head)
{
    // reverses a list iteratively and returns the new head

    node_t *curr = head;
    node_t *next = NULL;
    node_t *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

node_t *bruh = NULL;

node_t *reverseListRecursive(node_t *head)
{
    // reverses a list recursively

    if (head->next == NULL)
    {
        // printf("%d ", head->value);
        bruh = head;
        return head;
    }

    node_t *temp = head->next;

    insertAfterNode(reverseListRecursive(head->next), head);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // printf("%d ", temp->value);

    return temp;
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

    // node_t *sus = findNode(head, 4);
    // printf("node with value %d is at %p\n", sus->value, sus);

    // printf("removing value 4 from list:\n");
    // head = removeNode(head, 4);
    // printList(head);

    // printf("removing value 8 from list:\n");
    // head = removeNode(head, 8);
    // printList(head);

    // printf("adding new node with value 69 after node 6\n");
    // node_t *newNode = createNode(69);
    // insertAfterNode(findNode(head, 6), newNode);
    // printList(head);

    // printf("reversing the list iteratively:\n");
    // head = reverseListIterative(head);
    // printList(head);

    printf("reversing the list recursively:\n");
    head = reverseListRecursive(head);
    printList(bruh);

    return 0;
}