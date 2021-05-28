#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
  struct Node *left, *right;
};

typedef struct Node* nodeptr;


nodeptr newNode(int val) 
{
  nodeptr temp = (nodeptr)malloc(sizeof(struct Node));
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}



void bstsort(nodeptr root) 
{
  if (root != NULL) 
  {
    
    bstsort(root->left);

    printf("%d ", root->data);

    bstsort(root->right);
    
    
  }
}

int main() 
{
    nodeptr root = NULL;
    root = newNode(8);
    root->left=newNode(3);
    root->left->left=newNode(1);
    root->left->right=newNode(6);
    root->left->right->left=newNode(4);
    root->left->right->right=newNode(7);
    root->right=newNode(10);
    root->right->right=newNode(14);
    root->right->right->left=newNode(13);
    bstsort(root);
}