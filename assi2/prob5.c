#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

nodeptr insert(nodeptr node, int data) //bst insert
{
  
  if (node == NULL) 
    return newNode(data);

  if (data < node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);

  return node;
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

void shuffle(int *array, size_t n) {    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);


    if (n > 1) {
        size_t i;
        for (i = n - 1; i > 0; i--) {
            size_t j = (unsigned int) (drand48()*(i+1));
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

nodeptr randomBST(int n)
{
  nodeptr root = NULL;
  int *arr;
  arr=(int *)malloc(n*sizeof(int));
  for(int i=0;i<n;i++)
  {
    arr[i]=i+1;
  }
  shuffle(arr,n);
   for(int j=0;j<5;j++)
   {
    shuffle(arr,n);
  // for(int i=0;i<n;i++)
  // {
  //   printf("%d ",arr[i]);
  // }
  // printf("\n");
   }
  for(int i=0;i<n;i++)
  {
      root=insert(root,arr[i]);
  }
  return root;
 }

int Height(nodeptr T)
{
    if(T==NULL)
        return -1;
    int left=Height(T->left);
    int right=Height(T->right);
    if(left>right)
        return left+1;
    else 
        return right+1;
}


void avgdepth()
{
  //N=10
  //printf("m=           10      50      100    1000\n");
  float avg=0.0;int arr[4]={10,50,100,1000};
  // for(int j=0;j<4;j++)
  // {
  //   //printf("n=%4d  ",arr[j]);
  // for(int k=0;k<4;k++)
  // {
  //   avg=0.0;
  // for(int i=0;i<arr[k];i++)
  //   avg+=(float)Height(randomBST(arr[j]));
  
  // printf("%g ",avg/arr[k]);
  // }
  // printf("\n");
  // }
  FILE *ptr= fopen("graph.txt","w");
  for(int i=0;i<4;i++)
  { 
    for(int j=0;j<4;j++)
    {
      avg=0;
      for(int k=0;k<arr[i];k++)
        avg+=(float)Height(randomBST(arr[j]));
      fprintf(ptr,"%g ",avg/arr[i]);
    }
      fprintf(ptr,"\n");
  }
  fclose(ptr);
}

int main() 
{
  
    nodeptr root = NULL;
    // root = insert(root, 100);
    // root = insert(root, 40);
    // root = insert(root, 50);
    // root = insert(root, 20);
    // root = insert(root, 90);

  // printf("Enter n: ");
  // int n, *arr;
  // scanf("%d",&n);
  // root=randomBST(n);
  // bstsort(root);
  avgdepth();
    
    //printf("\n%d",finddepth(root,root->left->left->left));
}
