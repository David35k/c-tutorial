// simple calculator program
// take two numbers and an operation

#include <stdio.h>

int main() {

    // two numbers and operation and solution
    double a;
    double b;
    char op;
    double sol;

    // ask the user for the calculation
    printf("\nEnter your calculation in format (a+b or a*b)");
    scanf("%lf %c %lf", &a, &op, &b);

    // give the right solution depending on the operation
    switch(op) {
        case '+':
            sol = a + b;
            printf("= %.2lf", sol);
            break;
        case '-':
            sol = a - b;
            printf("= %.2lf", sol);
            break;
        case '*':
            sol = a * b;
            printf("= %.2lf", sol);
            break;
        case '/':
            sol = a / b;
            printf("= %.2lf", sol);
            break;
        default:
            printf("%c is not a valid operation(+, -, *, /)");
            break;
    }

    return 0;
}