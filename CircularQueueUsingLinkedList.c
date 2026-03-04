#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    int value = front->data;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        struct Node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    printf("Deleted: %d\n", value);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- CIRCULAR QUEUE (LINKED LIST) ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}