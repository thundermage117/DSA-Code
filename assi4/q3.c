#include<stdio.h>

void calculator(int **a,int n,int k)
{
    int b[n-k+1][n][k];
    for()
}

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    int **A=(int **)malloc(N*sizeof(int *));
    for (int i=0; i<N; i++)
        A[i] = (int *)malloc(N*sizeof(int));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&A[i][j]);
    calculator(**A,N,K);


    return 0;
}