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

int *arr,count=0;


void bstsort(nodeptr root) 
{
  if (root != NULL) 
  {
    
    bstsort(root->left);

    //printf("%d ", root->data);
    arr=(int*)realloc(arr,sizeof(int)*(count+1));
    if(arr==NULL)
    {
        printf("malloc fail");
        exit(0);
    }
    arr[count]=root->data;
    count++;

    bstsort(root->right);
    
    
  }
}

void delete()
{
    free(arr);
    count=0;
    arr=NULL;
}

int isbst(nodeptr root)
{   
    delete();
    bstsort(root);
    for(int i=1;i<count;i++)
        if(arr[i]<arr[i-1])
            return 0;
    return 1;
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
    //root->right->left=newNode(20); //include this to make non bst
    printf("\n%d",isbst(root));
    printf("\n%d",isbst(root));
    
}