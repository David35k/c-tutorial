#include <stdio.h>
#include <string.h>

#define STACK_SIZE 50

char chars[STACK_SIZE];
int top = -1; // keeps track of index of top of stack, -1 when empty

// print the stack
void printStack()
{
    for (int i = 0; i < top + 1; i++)
    {
        printf("%c ", chars[i]);
    }

    printf("<- top\n");
}

// push value x into the stack
void push(char x)
{
    top++;
    if (top >= STACK_SIZE)
    {
        printf("erm, stack overflow!!!\n");
        return;
    }

    chars[top] = x;
}

// pop a value from top of list
void pop()
{
    if (top == -1)
    {
        printf("list is empty, cant pop\n");
        return;
    }
    top--;
}

void reverseString(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        str[i] = chars[top];
        pop();
    }
}

int main()
{
    char str[51];
    printf("enter a string:\n");
    fgets(str, 50, stdin);
    reverseString(str, strlen(str));
    printf("output: %s", str);

    return 0;
}