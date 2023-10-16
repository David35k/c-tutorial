#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} node;

node *createNode(int value)
{
    node *result = malloc(sizeof(node));

    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }

    return result;
}

void printTree(node *root)
{
}

int main()
{
    // sus
    return 0;
}