#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char value;
    struct node *next;
};

typedef struct node node_t;

node_t *top = NULL;

// creates a linked list node
node_t *createNode(char c)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (node != NULL)
    {
        node->value = c;
        node->next = NULL;
        return node;
    }
    else
    {
        printf("\nerm, can't make a node lawl (malloc failed)");
        return NULL;
    }
}

// pushes a node to the stack
void push(node_t *node)
{
    if (top != NULL)
    {
        node->next = top;
    }
    top = node;
}

// pops a node off the stack
void pop()
{
    if (top != NULL)
    {
        node_t *temp = top;
        top = top->next;
        free(temp);
    }
    else
    {
        printf("can't pop eks dee (top is null)");
    }
}

bool isValid(char *s)
{
    node_t *temp = NULL;

    for (int i = 0; i < strlen(s); i++)
    {
        printf("\ns[i]: %c, ", s[i]);

        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            // if it is an opening bracket it should be pushed to the stack
            temp = createNode(s[i]);
            push(temp);
            break;
            // if closing bracket, it should match the value of top
        case ')':
            if (top != NULL && top->value == '(')
            {
                pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (top != NULL && top->value == '{')
            {
                pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (top != NULL && top->value == '[')
            {
                pop();
            }
            else
            {
                return false;
            }
            break;
        }

        if (top != NULL)
            printf("top->value: %c", top->value);
    }

    return (top == NULL);
}

int main()
{
    char *sus = "(){}[()]{{((()))}}";
    printf("\n%d", isValid(sus));
}