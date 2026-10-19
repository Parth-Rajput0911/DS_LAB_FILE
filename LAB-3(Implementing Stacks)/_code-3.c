//WAP TO EVALUATE A POSTFIX EXPRESSION USING STACK.
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    top++;
    stack[top] = value;
}

int pop()
{
    int value;

    if (top == -1)
    {
        printf("Invalid Expression!\n");
        return 0;
    }

    value = stack[top];
    top--;

    return value;
}

int evaluatePostfix(char exp[])
{
    int i, a, b, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero!\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 0;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char exp[SIZE];

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}
