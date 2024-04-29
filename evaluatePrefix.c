#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_SIZE 10

// define the stack array
float stack[STACK_SIZE];
int top = -1; // -1 when stack is empty

// push value onto stack
void push(float value)
{
    top++;

    // make sure there is no overflox
    if (top >= STACK_SIZE)
    {
        printf("dude, stack overflow!!!");
        return;
    }

    stack[top] = value;
}

// pop item off the stack
void pop()
{
    if (top <= -1)
    {
        printf("aye man, stack is empty cant pop!!!");
        return;
    }

    top--;
}

// evaluate a postfix expression and return result
float evaluatePrefix(char *str)
{
    // get length of string
    int length = strlen(str);

    // have to store the operator
    char operator;

    // loop through the string (except the null character at the end)
    for (int i = 0; i < length - 1; i++)
    {
        // check if operator
        if (str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            if (top > -1)
            {
                // this means there are operands before the operator which is sus
                printf("dawg, you didnt write the expression properly\n");
                printf("failed at %c\n", str[i]);
                return 0;
            }

            operator= str[i];
        }
        else
        {
            // if not an operator, make sure it is a number
            if (isdigit(str[i]))
            {
                push(str[i] - '0'); // c uses ascii codes, so have to subtract 0 code lawl (48)
            }
            else
            {
                printf("dude, why are there letters in your expression!?!? %c\n", str[i]);
                return 0;
            }

            // if there are two elements
            if (top == 1)
            {
                float result;

                // push the result
                switch (operator)
                {
                case '^':
                    result = pow(stack[top - 1], stack[top]);
                    break;
                case '*':
                    result = stack[top - 1] * stack[top];
                    break;
                case '/':
                    result = stack[top - 1] / stack[top];
                    break;
                case '+':
                    result = stack[top - 1] + stack[top];
                    break;
                case '-':
                    result = stack[top - 1] - stack[top];
                    break;

                default:
                    printf("what the sus, thats a funky error, looks like operator isnt recognized\n");
                    break;
                }

                // pop off the two last elements
                pop();
                pop();

                // push the result
                push(result);
            }
        }
    }

    return stack[top];
}

int main()
{
    char str[51];
    printf("dude, enter an expression in prefix notation\n");
    fgets(str, 50, stdin);
    printf("= %.2f\n", evaluatePrefix(str));
}