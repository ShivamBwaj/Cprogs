#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % SIZE == front)
        printf("Queue Full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue Empty\n");
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    int i = front;
    if (front == -1)
        printf("Queue Empty\n");
    else
    {
        while (1)
        {
            printf("V%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    dequeue();      
    enqueue(7);
    dequeue();      
    enqueue(8);

    display();      
    return 0;
}
