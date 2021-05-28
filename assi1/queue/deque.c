#include "deque.h"
#include <stdlib.h>
#include <stdio.h>


void initstack()
{
    front=NULL;
    rear=NULL;
}


void push(double x,double y)
{
    Nodeptr tmp = (Queue)malloc(sizeof(struct node));

    if(!tmp)
    {
        printf("Stack Overflow\n");
        return;
    }
    tmp->x=x;
    tmp->y=y;
    
    tmp->Prev=NULL;
    if(front==NULL)
        rear=tmp;
    else 
        front->Prev=tmp;
    tmp->Next=front;
    front=tmp;
    print();
}


void inject(double x,double y)
{
    Nodeptr tmp = (Queue)malloc(sizeof(struct node));

    if(!tmp)
    {
        printf("Queue Overflow\n");
        return;
    }
    tmp->x=x;
    tmp->y=y;
    
    tmp->Next=NULL;
    if(rear==NULL)
        front=tmp;
    else 
        rear->Next=tmp;
    tmp->Prev=rear;
    rear=tmp;
    print();
}
void pop()
{
    Nodeptr tmp;
    if(front==NULL)
    {
        printf("The queue is empty\n");
        return;
    }
    tmp=front;
    front=front->Next;
    if(front!=NULL)
        front->Prev=NULL;
    else 
        rear=NULL;
    free(tmp);
    print();
}

void eject()
{
    Nodeptr tmp;
    if(rear==NULL)
    {
        printf("The queue is empty\n");
        return;
    }
    tmp=rear;
    rear=rear->Prev;
    if(rear!=NULL)
        rear->Next=NULL;
    else 
        front=NULL;
    free(tmp);
    print();
}

void print()
{
    Nodeptr tmp = front;
    printf("Queue: ");
    while(tmp!=NULL)
    {
        printf("{%g, %g} ",tmp->x,tmp->y);
        tmp=tmp->Next;
    }
    printf("\n");

}