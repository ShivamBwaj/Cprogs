#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Deque {
    struct Node *tail;
    int count;
};

void initDeque(struct Deque *dq) {
    dq->tail = NULL;
    dq->count = 0;
}

int isEmpty(struct Deque *dq) {
    return dq->tail == NULL;
}

int size(struct Deque *dq) {
    return dq->count;
}

void pushFront(struct Deque *dq, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;

    if (isEmpty(dq)) {
        newNode->next = newNode;
        dq->tail = newNode;
    } else {
        newNode->next = dq->tail->next;
        dq->tail->next = newNode;
    }
    dq->count++;
}

void pushRear(struct Deque *dq, int value) {
    pushFront(dq, value);
    dq->tail = dq->tail->next;
}

int popFront(struct Deque *dq) {
    if (isEmpty(dq)) return -1;

    struct Node *head = dq->tail->next;
    int val = head->data;

    if (head == dq->tail) {
        dq->tail = NULL;
    } else {
        dq->tail->next = head->next;
    }

    free(head);
    dq->count--;
    return val;
}

int popRear(struct Deque *dq) {
    if (isEmpty(dq)) return -1;

    struct Node *curr = dq->tail->next;

    if (curr == dq->tail) {
        int val = dq->tail->data;
        free(dq->tail);
        dq->tail = NULL;
        dq->count--;
        return val;
    }

    while (curr->next != dq->tail)
        curr = curr->next;

    int val = dq->tail->data;
    curr->next = dq->tail->next;
    free(dq->tail);
    dq->tail = curr;

    dq->count--;
    return val;
}

int peekFront(struct Deque *dq) {
    return isEmpty(dq) ? -1 : dq->tail->next->data;
}

int peekRear(struct Deque *dq) {
    return isEmpty(dq) ? -1 : dq->tail->data;
}

void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node *temp = dq->tail->next;
    printf("Deque elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != dq->tail->next);

    printf("\n");
}

/* ---------- MAIN ---------- */

int main() {
    struct Deque dq;
    initDeque(&dq);

    int choice, value;

    while (1) {
        printf("\n===== CIRCULAR DEQUE MENU =====\n");
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