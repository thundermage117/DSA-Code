#include<stdio.h>
#include<stdlib.h>

int checker(int k,int n, int x,int *A)
{
    int ctr=0;
    if (k > n) 
        return 0;
    int d[n],e[k];
    for(int i=0;i<n;i++)
        d[i]=k*A[i];
    e[0]=0;
    for(int i=0;i<k;i++)
        e[0]+=d[i];
    for(int i=1;i<n-k+1;i++)
        e[i]=e[i-1]-d[i-1]+d[i-1+k];
    if(k==1)
    {
    for (int i=0; i<n-k+1; i++)
    {  
        for(int j=i;j<n-k+1;j++)
        {   if((e[i]+e[j])==x)
                ctr+=2;
            //printf("%d ",sum);
        }
        //printf("\n");
    }
    }
    else 
        ctr=checker(1,n-k+1,x,e);
   return ctr;
}

int main()
{
    int N,K,*A,X;
    scanf("%d %d",&N,&K);
    A=(int *)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    //setup(A,N);
    scanf("%d",&X);
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<N;j++)
    //         printf("%d ",M[i][j]);
    //     printf("\n");
    // }
    printf("%d",checker(K,N,X,A));
    return 0;
}