

#include "my_stack.h"
#include <stdlib.h>
#include <stdio.h>

void initstack()
{
    top=NULL;//defining variables in .h file won't work
}

void push(double x,double y)
{
    Nodeptr tmp = (Stack)malloc(sizeof(struct node));

    if(!tmp)
    {
        printf("Stack Overflow\n");
        return;
    }
    tmp->x=x;
    tmp->y=y;
    tmp->Next=top;
    top=tmp;
    print();
}

void pop()
{
    Nodeptr tmp;
    if(top==NULL)
    {
        printf("The stack is empty\n");
        return;
    }
    tmp=top;
    top=top->Next;
    free(tmp);
    print();
}

void print()
{
    Nodeptr tmp = top;
    printf("Stack: ");
    while(tmp!=NULL)
    {
        printf("{%g, %g} ",tmp->x,tmp->y);
        tmp=tmp->Next;
    }
    printf("\n");

}