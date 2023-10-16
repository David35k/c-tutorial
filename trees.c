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
    if (root == NULL)
    {
        printf("---<empty>---\n");
        return;
    }

    //epik recursion incoming!!!

    //preorder shinenigans
    printf("value = %d\n", root->value);

    printf("left\n");
    printTree(root->left);
    printf("right\n");
    printTree(root->right);
    printf("done\n");
}

int main()
{
    node *n1 = createNode(1);
    node *n2 = createNode(2);
    node *n3 = createNode(3);
    node *n4 = createNode(4);
    node *n5 = createNode(5);
    node *n6 = createNode(6);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n3->left = n5;
    n3->right = n6;

    printTree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    return 0;
}