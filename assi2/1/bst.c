#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

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
int flag=0;

int finddepth_help(nodeptr T,nodeptr P)
{
    if(P==NULL)
        return -1;
    if(T == P)
    {   
        flag=1;//so that fn is not called again
        return 0;  
    } 
    int temp=0;
    if(T->left != NULL && flag==0) 
        temp= finddepth_help(T->left,P)+1;
        
    if(T->right != NULL && flag==0)
        temp= finddepth_help(T->right,P)+1;
    return temp;

}

void finddepth(nodeptr T, nodeptr P)
{
    flag=0;
    printf("%d\n" ,finddepth_help(T,P));
}

int Height_help(nodeptr T)
{
    if(T==NULL)
        return -1;
    int hlef=Height_help(T->left);
    int hrig=Height_help(T->right);
    if(hlef>hrig)
        return hlef+1;
    else 
        return hrig+1;
}

void Height(nodeptr T)
{
    printf("%d\n",Height_help(T));
}

int *arr,count=0;


void bstsort_new(nodeptr root) 
{
  if (root != NULL) 
  {
    
    bstsort_new(root->left);

    //printf("%d ", root->data);
    arr=(int*)realloc(arr,sizeof(int)*(count+1));
    if(arr==NULL)
    {
        printf("malloc fail");
        exit(0);
    }
    arr[count]=root->data;
    count++;

    bstsort_new(root->right);
    
    
  }
}

void delete()
{
    free(arr);
    count=0;
    arr=NULL;
}
int isbst_help(nodeptr root)
{   
    delete();
    bstsort_new(root);
    for(int i=1;i<count;i++)
        if(arr[i]<arr[i-1])
            return 0;
    return 1;
}

void isbst(nodeptr root)
{   
    printf("%d\n",isbst_help(root));
}

void inRange(nodeptr root,int k1,int k2) 
{
  if (root != NULL) 
  {
    
    inRange(root->left,k1,k2);

    if((root->data>=k1)&&(root->data<=k2))
        printf("%d ", root->data);

    inRange(root->right,k1,k2);
    
    
  }
}