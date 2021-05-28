#include<stdio.h>
#include<stdlib.h>

int checker(int k,int n, int x,int *A)
{
    int ctr=0;
    if (k > n) 
        return 0;
    int **b=(int **)malloc(n*sizeof(int *));
    for (int i=0; i<n; i++)
        b[i] = (int *)malloc(n*sizeof(int));
    int c[n-k+1],d[n];
    for(int i=0;i<n;i++)
        d[i]=k*A[i];
    for(int i=0;i<n-k+1;i++)
        c[i]=0;
    for(int i=0;i<k;i++)
        c[0]+=A[i];
    for(int i=1;i<n-k+1;i++)
        c[i]+=c[i-1]-A[i-1]+A[i+k-1];
    for (int i=0; i<n; i++)
    {
        for(int j=0;j<n-k+1;j++)
        {    b[j][i]=d[i]+c[j];
        //printf("%d ",b[j][i]);
        }
        //printf("\n");
    }

    for (int i=0; i<n-k+1; i++)
    {
        int sum=0;
        for (int j = 0;j<k;j++)
            sum+=b[i][j];
        //printf("%d ",sum);
        if(sum==x)
            ctr++;
        for (int j=1;j<n-k+1;j++)
        {
            sum+=(b[i][j+k-1]-b[i][j-1]);
            if(sum==x)
                ctr++;
          //  printf("%d ",sum);
        }
        //printf("\n");
    }
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