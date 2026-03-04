#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int isFull();
int isEmpty();
void inject(int); //rear side
void push(int); //front side
int eject();
int pop();
void display();

int n=5;
int dq[5]={0};
int rear=-1;
int front=-1;

int main(){
    int ch,ele;
    do{
        printf("\n1. Inject[insert from rear] \n 2.eject[delete from rear]\n 3.Push[insert from front]\n 4.Pop[insert from front] \n 5.Display\n6.Exit");
        printf("\nEnter Your choice \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(isFull()){
                    printf("\nDequeue is FUll\n");
                }
                else{
                    printf("\n Enter Element to Insert \n");
                    scanf("%d",&ele);
                    inject(ele);
                }
                break;
            case 2:
                if(isEmpty()){
                    printf("\nDequeue is Empty\n");
                }
                else{
                    
                    ele=eject();
                    printf("\n Element ejected is %d \n",ele);
                    
                }
                break;
            case 3:
                if(isFull()){
                    printf("\nDequeue is FUll\n");
                }
                else{
                    printf("\n Enter Element to Insert \n");
                    scanf("%d",&ele);
                    push(ele);
                }
                break;
            case 4:
                if(isEmpty()){
                    printf("\nDequeue is Empty\n");
                }
                else{
                    
                    ele=pop();
                    printf("\n Element Popped is %d \n",ele);
                    
                }
                break;
            case 5:
                display();
                break;
            
        }
        
    }while(ch!=6);
}

//user def function

int isFull(){
    if(((front==0)&&(rear==(n-1)))||(front==rear+1)){
        return 1;

    }
    else return 0;
}

int isEmpty(){
    if(front==-1)
        return 1;
    else
        return 0;

}

void inject(int ele){
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==(n-1)){
        rear=0;
    }
    else{
        rear=rear+1;

    }
    dq[rear]=ele;
}
int eject(){
    int ele;
    ele=dq[rear];
    dq[rear]=0;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(rear==0){
        rear=n-1;
    }
    else
        rear=rear-1;
    return ele;
}
void push(int ele){
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front=n-1;
    }
    else{
        front=front-1;
    }
    dq[front]=ele;
}
int pop(){
    int ele;
    
    ele=dq[front];
    dq[front]=0;
    if(front==rear){
        front=-1;
        rear=-1;

    }
    else if(front==n-1){
        front=0;
    }
    else{
        front = front+1;
    }
    return ele;

}

void display(){
    int I;
    printf("\n front= %d and rear= %d",front,rear);
    printf("\n De-queue :- ");
    for(I=0;I<n;I++){
        printf("| %d |",dq[I]);
    }
}