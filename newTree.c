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

// void deleteNode(int value)
// {
//     if (value == NULL)
//     {
//         printf("mate the value you passed is null!!!!! (delete)\n");
//         return;
//     }

//     node_t *temp = root;

//     printf("somethin aint right bro\n");
//     return;
// }

// recursive
void printTreeRecur(node_t *node)
{

    if (node == NULL)
    {
        return;
    }

    printf("value: %d\n", node->value);
    printf("left\n");
    printTreeRecur(node->left);
    printf("right\n");
    printTreeRecur(node->right);
}

// recursive
int getHeight(node_t *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int heightLeft = getHeight(node->left);
    int heightRight = getHeight(node->right);

    return (heightLeft > heightRight ? heightLeft : heightRight);
}

int main()
{
    root = createNode(10);
    insertNode(createNode(15));
    insertNode(createNode(8));
    insertNode(createNode(13));
    insertNode(createNode(3));

    return 0;
}
