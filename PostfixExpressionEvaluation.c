#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char exp[])
{
    int i = 0;

    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else if (isspace(exp[i]))
        {
            i++;
        }
        else
        {
            if (exp[i] == '%')
            {
                int rate = pop();
                int balance = pop();
                int interest = (balance * rate) / 100;
                push(balance);
                push(interest);
            }
            else
            {
                int b = pop();
                int a = pop();

                switch (exp[i])
                {
                    case '+': push(a + b); break;
                    case '-': push(a - b); break;
                    case '*': push(a * b); break;
                    case '/': push(a / b); break;
                }
            }
            i++;
        }
    }
    return pop();
}

int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);

    printf("Final Balance = %d\n", evaluatePostfix(exp));

    return 0;
}
