#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void insertFront(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (isEmpty()) {
        rear = newNode;
    } else {
        front->prev = newNode;
    }

    front = newNode;
    printf("Inserted at front: %d\n", value);
}

void insertRear(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (isEmpty()) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    rear = newNode;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    int value = front->data;
    struct Node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
    printf("Deleted from front: %d\n", value);
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    int value = rear->data;
    struct Node *temp = rear;

    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
    printf("Deleted from rear: %d\n", value);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE (DLL) ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}