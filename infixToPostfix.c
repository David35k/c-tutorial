#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// define the stack size
#define STACK_SIZE 10

// stack array
char stack[STACK_SIZE];
int top = -1; // keep track of size of arrray

// adds new value to top of stack
void push(char value)
{
    top++;

    // check if stack overflow
    if (top >= STACK_SIZE)
    {
        printf("STACK OVERFLOW!!!");
        return;
    }

    stack[top] = value;
}

// pops topmost element off the stack
void pop()
{
    if (top == -1)
    {
        printf("stack is already empty bro");
        return;
    }

    top--;
}

// cheeky helped function
int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}

// checks if c1 has precedence over c2
// make sure c1 is always the left one
int hasPrecedence(char c1, char c2)
{
    if (c1 == '^')
    {
        return 1;
    }
    else if ((c1 == '*' || c1 == '/') && c2 != '^')
    {
        return 1;
    }
    else if ((c1 == '+' || c1 == '-') && c2 != '*' && c2 != '/' && c2 != '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixToPostfix(char *str)
{
    char *result = calloc(50, sizeof(char)); // final length should be the same as the original infix expression
    // loop through the string
    for (int i = 0; i < strlen(str); i++)
    {
        // if its an operand can add it straight into result
        if (isalnum(str[i]))
        {
            strncat(result, &str[i], 1);
        }
        else if (isOperator(str[i]))
        {
            // if opening bracket add to stack and go next
            if (str[i] == '(')
            {
                push(str[i]);
                continue;
            }

            // keep adding from stack as long as it has precedence
            while (top > -1 && hasPrecedence(stack[top], str[i]))
            {
                strncat(result, &stack[top], 1);
                pop();
            }

            if (str[i] != ')')
            {
                // add the new operand to the stack
                push(str[i]);
            }
            else
            {
                pop();
            }
        }
    }

    // leftover operators
    while (top > -1)
    {
        strncat(result, &stack[top], 1);
        pop();
    }

    return result;
}

int main()
{
    char str[50];
    printf("enter an expression in infix notation (max length 50 chars)\n");
    fgets(str, 50, stdin);
    printf("in postfix: %s", infixToPostfix(str));
}