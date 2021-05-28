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

int finddepth_help(nodeptr T,nodeptr P, int flag)
{
    if(P==NULL)
        return -1;
    if(T == P)
    {   
        flag=1;//so that fn is not called again
        return 0;  
    } 
    int temp;
    if(T->left != NULL && flag==0) 
        temp= finddepth_help(T->left,P,0)+1;
        
    if(T->right != NULL && flag==0)
        temp= finddepth_help(T->right,P,0)+1;
    return temp;

}

int finddepth(nodeptr T, nodeptr P)
{
  return finddepth_help(T,P,0);

}




int main() 
{
    //binary tree not bst
    nodeptr root = NULL;
    root = newNode(100);
    root->left= newNode(200);
    root->right=newNode(50);
    root->left->left=newNode(20);
    root->left->left->left=newNode(90);
    root->left->left->left->left=newNode(10);
    root->left->right=newNode(30);
    root->left->right->left=newNode(4);
    bstsort(root);
    
    printf("\n%d",finddepth(root,root->left->right->left));
}