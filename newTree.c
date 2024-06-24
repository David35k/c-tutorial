#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node node_t;

node_t *root = NULL;

node_t *createNode(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->left = NULL;
    result->right = NULL;
    return result;
}

// iterative
void insertNode(node_t *node)
{
    if (node == NULL)
    {
        printf("mate, the node you passed is null (insert)\n");
        return;
    }

    node_t *temp = root;

    while (temp != NULL)
    {
        if (node->value <= temp->value)
        {
            if (temp->left == NULL)
            {
                temp->left = node;
                return;
            }
            temp = temp->left;
        }
        else if (node->value > temp->value)
        {
            if (temp->right == NULL)
            {
                temp->right = node;
                return;
            }
            temp = temp->right;
        }
    }

    printf("somethin aint right bro\n");
    return;
}

void insertNodeRecur(node_t *head, node_t *node)
{
    if (node == NULL)
    {
        printf("mate, the node you passed is null (insert recur)\n");
        return;
    }

    if (head == NULL)
    {
        printf("mate, the head you passed is null (insert recur)\n");
        return;
    }

    if (node->value <= head->value)
    {
        if (head->left == NULL)
        {
            head->left = node;
            return;
        }

        insertNodeRecur(head->left, node);
    }
    else if (node->value > head->value)
    {
        if (head->right == NULL)
        {
            head->right = node;
            return;
        }

        insertNodeRecur(head->right, node);
    }
}

// iterative
node_t *search(int value)
{
    if (value == NULL)
    {
        printf("mate, the node you passed is null (search)\n");
        return NULL;
    }

    node_t *temp = root;

    while (temp != NULL)
    {
        if (value == temp->value)
        {
            return temp;
        }
        else if (value <= temp->value)
        {
            temp = temp->left;
        }
        else if (value > temp->value)
        {

            temp = temp->right;
        }
    }

    printf("couldnt find a node with that value\n");
    return NULL;
}

node_t *searchRecur(node_t *head, int value)
{
    if (head == NULL)
    {
        printf("mate, the head you passed is null (search recur)\n");
        return NULL;
    }

    if (value == NULL)
    {
        printf("mate, the value you passed is null (search recur)\n");
        return NULL;
    }

    if (value == head->value)
    {
        return head;
    }
    else if (head->left == NULL && head->right == NULL)
    {
        return NULL;
    }

    node_t *resultLeft = NULL;
    node_t *resultRight = NULL;

    if (head->left != NULL)
    {
        resultLeft = searchRecur(head->left, value);
    }

    if (head->right != NULL)
    {
        resultRight = searchRecur(head->right, value);
    }

    if (resultLeft == NULL)
    {
        return resultRight;
    }
    else if (resultRight == NULL)
    {
        return resultLeft;
    }
    else if (resultLeft != NULL && resultRight != NULL)
    {
        printf("uhhh, somethin aint right dude\n");
        return NULL;
    }
}

void printTreeRecur(node_t *node)
{

    if (node == NULL)
    {
        return;
    }

    printf("value: %i\n", node->value);
    printf("left\n");
    printTreeRecur(node->left);
    printf("right\n");
    printTreeRecur(node->right);
}

int main()
{
    root = createNode(10);
    insertNode(createNode(15));
    insertNode(createNode(8));
    insertNode(createNode(13));
    insertNode(createNode(3));

    insertNodeRecur(root, createNode(16));
    insertNodeRecur(root, createNode(9));
    insertNodeRecur(root, createNode(11));
    insertNodeRecur(root, createNode(4));

    printTreeRecur(root);

    printf("found: %i\n", search(11)->value);
    printf("found: %i\n", searchRecur(root, 11)->value);

    return 0;
}
