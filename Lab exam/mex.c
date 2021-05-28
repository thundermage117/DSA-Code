#include<stdio.h>
#include<stdlib.h>

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



int calculate(int* arr,int len)
{
    HeapSort(arr,len);
    int mex=0;
    for(int i=0;i<len;i++)
        if(arr[i]==mex)
            mex++;
    return mex;
}

int main()
{
    int Q;
    scanf("%d",&Q);
    int *arr=malloc(Q*sizeof(Q));
    int mex=0;
    int *check=malloc(Q*sizeof(int));
    for(int i=0;i<Q;i++)
        check[i]=100000+1;
    int ctr=0;
    for(int i=0;i<Q;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a==1)
        {
            check[ctr]=b;
            ctr++;
        }
        if(a==2)
        {
            for(int j=0;j<ctr;j++)
                if(check[j]==b)
                    check[j]=100000+1;
        }
        if(a==1&&b==mex)
            mex=calculate(check,ctr);
        if(a==2&&b<mex)
            mex=b;
        arr[i]=mex;
    }
    for(int i=0;i<Q;i++)
        printf("%d ",arr[i]);
    return 0;
}