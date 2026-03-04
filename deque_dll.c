#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
    int count;
};

void initDeque(struct Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->count = 0;
}

int isEmpty(struct Deque *dq) {
    return dq->front == NULL;
}

int size(struct Deque *dq) {
    return dq->count;
}

void pushFront(struct Deque *dq, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq))
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
    dq->count++;
}

void pushRear(struct Deque *dq, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq))
        dq->front = newNode;
    else
        dq->rear->next = newNode;

    dq->rear = newNode;
    dq->count++;
}

int popFront(struct Deque *dq) {
    if (isEmpty(dq)) return -1;

    struct Node *temp = dq->front;
    int val = temp->data;

    dq->front = temp->next;
    if (dq->front)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->count--;
    return val;
}

int popRear(struct Deque *dq) {
    if (isEmpty(dq)) return -1;

    struct Node *temp = dq->rear;
    int val = temp->data;

    dq->rear = temp->prev;
    if (dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->count--;
    return val;
}

int peekFront(struct Deque *dq) {
    return isEmpty(dq) ? -1 : dq->front->data;
}

int peekRear(struct Deque *dq) {
    return isEmpty(dq) ? -1 : dq->rear->data;
}

void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *temp = dq->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ---------- MAIN ---------- */

int main() {
    struct Deque dq;
    initDeque(&dq);

    int choice, value;

    while (1) {
        printf("\n===== DEQUE MENU =====\n");
        printf("1. Push Front\n");
        printf("2. Push Rear\n");
        printf("3. Pop Front\n");
        printf("4. Pop Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Display\n");
        printf("8. Size\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                pushFront(&dq, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                pushRear(&dq, value);
                break;

            case 3:
                value = popFront(&dq);
                if (value == -1)
                    printf("Deque Underflow!\n");
                else
                    printf("Removed from front: %d\n", value);
                break;

            case 4:
                value = popRear(&dq);
                if (value == -1)
                    printf("Deque Underflow!\n");
                else
                    printf("Removed from rear: %d\n", value);
                break;

            case 5:
                value = peekFront(&dq);
                if (value == -1)
                    printf("Deque is empty!\n");
                else
                    printf("Front element: %d\n", value);
                break;

            case 6:
                value = peekRear(&dq);
                if (value == -1)
                    printf("Deque is empty!\n");
                else
                    printf("Rear element: %d\n", value);
                break;

            case 7:
                display(&dq);
                break;

            case 8:
                printf("Size of deque: %d\n", size(&dq));
                break;

            case 9:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}