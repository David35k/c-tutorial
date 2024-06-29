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

// using a queue to do breadth first traveersal, pretty epic

#define QUEUE_SIZE 20

node_t *queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

// returns 1 if the queue is empty, 0 if it has elements in it
int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        printf("yeah mate, pretty empty\n");
        return 1;
    }

    return 0;
}

// returns 1 if the queue is full, 0 if it there is free space
int isFull()
{
    if ((rear + 1) % QUEUE_SIZE == front)
    {
        return 1;
    }

    return 0;
}

void enqueue(node_t *node)
{
    // cant add more if the queue is full
    if (isFull())
    {
        printf("yo g, cant't enqueue because the queue is full! maybe dequeue?\n");
    }
    else if (isEmpty())
    {
        // set both front and rear to 0 cos there is only one element
        front = 0;
        rear = 0;
        queue[rear] = node;
    }
    else
    {
        // insert at rear
        rear = (rear + 1) % QUEUE_SIZE;
        queue[rear] = node;
    }
}

node_t *dequeue()
{
    if (isEmpty())
    {
        printf("yo g cant dequeue cos there is nothing to dequeue!!\n");
    }
    else if (front == rear)
    {
        // only one element so dequeue will make the queue empty
        node_t *temp = queue[front];
        front = -1;
        rear = -1;
        return temp;
    }
    else
    {
        node_t *temp = queue[front];
        front = (front + 1) % QUEUE_SIZE;
        return temp;
    }
}

void printQueue()
{
    printf("queue: ");
    if (!isEmpty())
    {
        int i = front;
        while (i != rear)
        {
            printf("%i,", queue[i]->value);
            i = (i + 1) % QUEUE_SIZE;
        }
        printf("%i", queue[rear]->value);
    }
    printf("\n");
}

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

// recursive cos recursive is epic🔥
int findMax(node_t *root)
{
    if (root == NULL)
    {
        printf("braz, the node you passed is null (findmax)");
        return 0;
    }

    if (root->right == NULL)
    {
        return root->value;
    }
    else
    {
        return findMax(root->right);
    }
}

int findMin(node_t *root)
{
    if (root == NULL)
    {
        printf("braz, the node you passed is null (findmin)");
        return 0;
    }

    if (root->left == NULL)
    {
        return root->value;
    }
    else
    {
        return findMin(root->left);
    }
}

int height(node_t *root)
{
    if (root == NULL)
    {
        printf("braz, the node you passed is null (height)");
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int heightLeft = 0;
    int heightRight = 0;

    if (root->left != NULL)
    {
        heightLeft = height(root->left) + 1;
    }
    if (root->right != NULL)
    {
        heightRight = height(root->right) + 1;
    }

    return (heightLeft > heightRight ? heightLeft : heightRight);
}

void breadthFirst(node_t *root)
{
    if (root == NULL)
    {
        printf("dawg that node is null (breadthFirst thing)");
        return;
    }

    printf("%i\n", root->value);

    if (root->left != NULL)
    {
        enqueue(root->left);
    }

    if (root->right != NULL)
    {
        enqueue(root->right);
    }

    // printQueue();

    breadthFirst(dequeue());
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
    insertNodeRecur(root, createNode(2));
    insertNodeRecur(root, createNode(19));
    insertNodeRecur(root, createNode(69));
    insertNodeRecur(root, createNode(50));
    insertNodeRecur(root, createNode(420));

    // printTreeRecur(root);

    printf("found: %i\n", search(11)->value);
    printf("found: %i\n", searchRecur(root, 11)->value);
    printf("max value in tree: %i\n", findMax(root));
    printf("min value in tree: %i\n", findMin(root));
    printf("height: %i\n", height(root));

    printf("breadth first: \n");
    breadthFirst(root);

    return 0;
}
