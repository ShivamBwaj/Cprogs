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

void pushFront(struct Deque *dq, int songID) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = songID;

    if (isEmpty(dq)) {
        newNode->next = newNode;
        dq->tail = newNode;
    } else {
        newNode->next = dq->tail->next;
        dq->tail->next = newNode;
    }
    dq->count++;
}

void pushRear(struct Deque *dq, int songID) {
    pushFront(dq, songID);
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


int main() {
    struct Deque dq;
    initDeque(&dq);

    pushFront(&dq, 101);
    pushRear(&dq, 102);
    pushFront(&dq, 103);

    printf("Front: %d\n", peekFront(&dq));
    printf("Rear: %d\n", peekRear(&dq));
    printf("Removed Front: %d\n", popFront(&dq));
    printf("Removed Rear: %d\n", popRear(&dq));
    printf("Size: %d\n", size(&dq));

    return 0;
}
