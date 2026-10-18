//WAP TO CHECK BALANCED PARENTHESES USING STACK
#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    if (top < SIZE - 1)
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int checkBalanced(char exp[])
{
    int i;
    char ch, open;

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
                return 0;

            open = pop();

            if (!isMatching(open, ch))
                return 0;
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[SIZE];

    printf("Enter an expression: ");
    scanf("%99s", exp);

    top = -1;

    if (checkBalanced(exp))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");

    return 0;
}
