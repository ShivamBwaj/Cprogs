#include <stdio.h>

int push(int stack[], int top, int n) {
    int x;
    if (top == n - 1) {
        printf("Stack is full\n");
        return top;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
    return top;
}

int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return top;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
    return top;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void display(int stack[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;
    int top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int stack[n];

    while (1) {
        printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(stack, top, n);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}