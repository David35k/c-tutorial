// stacks!!!!
// array implementation

#include <stdio.h>

#define STACK_SIZE 10

int nums[STACK_SIZE];
int top = -1; // keeps track of index of top of stack, -1 when empty

// print the stack
void printStack()
{
    for (int i = 0; i < top + 1; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("<- top\n");
}

// push value x into the stack
void push(int x)
{
    top++;
    if (top >= STACK_SIZE)
    {
        printf("erm, stack overflow!!!\n");
        return;
    }

    nums[top] = x;
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

int main()
{
    push(1);
    push(2);
    push(69);
    push(3);
    push(4);
    push(5);
    printStack();
    pop();
    pop();
    printStack();
    return 0;
}