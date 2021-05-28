#ifndef __stack_h
#define __stack_h

typedef struct node* Nodeptr;
typedef Nodeptr Stack;

struct node
{
    double x;
    double y;
    Nodeptr Next;
};

Nodeptr top;

void initstack();

void push(double x,double y);
void pop();
void print();


#endif