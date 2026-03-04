#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        // If operand → add to postfix
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        // If '(' → push
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        // If ')' → pop until '('
        else if (infix[i] == ')')
        {
            while (peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // If operator
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
                postfix[j++] = pop();

            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infix[strcspn(infix, "\n")] = '\0';  // remove newline

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}