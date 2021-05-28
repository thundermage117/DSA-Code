#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElementType;
typedef int* ElemTypePtr;

void swap_array_elems(ElemTypePtr A,int i,int j)
{
    ElementType tmp;

    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

void DownHeap(ElemTypePtr a,int i,int n)
{
	// Establish heap property first at a[i]
	int w = i*2 + 1; // First descendant of i (0-based indexing)
	while( w < n ) {
		if ( w+1 < n )
			if ( a[w+1] > a[w] ) w++;
		if ( a[i] >= a[w] ) return;
		swap_array_elems(a,i,w);		
		i = w; // we swapped with this node ; subtree below it may need fixing
		w =i*2+1; // Get first descendant of 'i' and repeat loop procedure
	}
}

void HeapSort(ElemTypePtr a,int n)
{
	int i;

	// perform heap adjustment for non-leaf elements
        // starting from leaf parents and going up level
        // by level towards root
	for(i = n/2-1 ; i >= 0 ; i--)
		DownHeap(a,i,n);	

	while( n > 1 ) {		
		n--;
		swap_array_elems(a,0,n); 
		DownHeap(a,0,n);
	}
}

int main()
{
    int N;
    scanf("%d",&N);
    int *P=malloc(2*N*sizeof(int));
    for(int i=0;i<2*N;i++)
        scanf("%d",&P[i]);
    HeapSort(P,2*N);
    long long int sum=0;
    for(int i=0;i<N;i++)
        sum+=P[i+N]-P[i];
    printf("%lld",sum);
    return 0;
}