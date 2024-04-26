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
float evaluatePostfix(char *str)
{
    // get length of string
    int length = strlen(str);
    // loop through the string (except the null character at the end)
    for (int i = 0; i < length - 1; i++)
    {
        // check if operator
        if (str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            printf("aye its an operator!! %c \n", str[i]);

            // this means there arent two operands before the operator which is sus
            if (top < 1)
            {
                printf("dawg, you didnt write the expression properly\n");
                printf("failed at %c\n", str[i]);
                return 0;
            }

            float result;

            // push the result
            switch (str[i])
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
                printf("what the sus, thats a funky error\n");
                break;
            }

            // pop off the two last elements
            pop();
            pop();

            // push the result
            push(result);
        }
        else
        {
            // if not an operator, make sure it is a number
            if (isdigit(str[i]))
            {
                printf("yippee, not a latter %c\n", str[i]);
                push(str[i] - '0'); // c uses ascii codes, so have to subtract 0 code lawl (48)
            }
            else
            {
                printf("dude, why are there letters in your expression!?!? %c\n", str[i]);
                return 0;
            }
        }
    }

    return stack[top];
}

int main()
{
    char str[51];
    printf("dude, enter an expression in postfix notation\n");
    fgets(str, 50, stdin);
    printf("%f\n", evaluatePostfix(str));
}