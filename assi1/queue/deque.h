#ifndef __my_queue_h
#define __my_queue_h



typedef struct node* Nodeptr;
typedef Nodeptr Queue;

struct node
{
    double x;
    double y;
    Nodeptr Next;
    Nodeptr Prev;//doubly linked for O(1) complexity
};
Nodeptr front, rear;

void initstack();
void push(double x,double y);
void pop();
void print();

void inject(double x,double y);
void eject();




#endif