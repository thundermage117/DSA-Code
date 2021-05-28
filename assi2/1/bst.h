#ifndef __bst_h_
#define __bst_h_

typedef struct Node
{
int data;
int height;
struct Node* left;
struct Node* right;
}Node;

typedef struct Node* nodeptr;

nodeptr newNode(int val);
void bstsort(nodeptr root);
void finddepth(nodeptr T, nodeptr P);
void Height(nodeptr T);
void isbst(nodeptr root);
void inRange(nodeptr root,int k1,int k2);

#endif