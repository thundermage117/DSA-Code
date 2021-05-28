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

int Height(nodeptr T)
{
    if(T==NULL)
        return -1;
    if(Height(T->left)>Height(T->right))
        return Height(T->left)+1;
    else 
        return Height(T->right)+1;
}



int main() 
{
    nodeptr root = NULL;
    root = newNode(100);
    root->left= newNode(200);
    root->right=newNode(50);
    root->left->left=newNode(20);
    root->left->left->left=newNode(90);
    root->left->left->left->left=newNode(10);
    bstsort(root);
    
    printf("\n%d",Height(root));
}