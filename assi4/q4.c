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
    for (int i=0; i<n; i++)
    {
        int sum = 0;
        for (int j=0; j<k; j++)
            sum+=A[j]+A[i];
        b[0][i] = sum;
        for(int j=1;j<n-k+1;j++)
        {
            sum+=(A[j+k-1]-A[j-1]);
            b[j][i] = sum;
        }
    }
    for (int i=0; i<n-k+1; i++)
    {
        int sum=0;
        for (int j = 0;j<k;j++)
            sum+=b[i][j];
        if(sum==x)
            ctr++;
        for (int j=1;j<n-k+1;j++)
        {
            sum+=(b[i][j+k-1]-b[i][j-1]);
            if(sum==x)
                ctr++;
        }
    }
   return ctr;
}

int main()
{
    int N,*A,X;
    scanf("%d",&N);
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
    int ctr=0;
    for(int i=1;i<N;i++)
        ctr+=checker(i,N,X,A);
    printf("%d",ctr);
    return 0;
}