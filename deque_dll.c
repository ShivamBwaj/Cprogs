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

void pushFront(struct Deque *dq, int songID) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = songID;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq))
        dq->rear = newNode;
    else
        dq->front->prev = newNode;

    dq->front = newNode;
    dq->count++;
}

void pushRear(struct Deque *dq, int songID) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = songID;
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

/* ---------- MAIN ---------- */
int main() {
    struct Deque dq;
    initDeque(&dq);

    pushFront(&dq, 201);
    pushRear(&dq, 202);
    pushFront(&dq, 203);

    printf("Front: %d\n", peekFront(&dq));
    printf("Rear: %d\n", peekRear(&dq));
    printf("Removed Front: %d\n", popFront(&dq));
    printf("Removed Rear: %d\n", popRear(&dq));
    printf("Size: %d\n", size(&dq));

    return 0;
}
