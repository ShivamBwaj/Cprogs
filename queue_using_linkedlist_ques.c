#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    if (front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    if (front == NULL)
        printf("Queue Empty\n");
    else if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    if (front == NULL)
        printf("Queue Empty\n");
    else
    {
        do
        {
            printf("V%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
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
