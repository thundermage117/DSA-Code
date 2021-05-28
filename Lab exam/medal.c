#include<stdio.h>
#include<stdlib.h>

struct medal
{
    char state[3];
    int a,b,c,d;
};

int compare(const void * C,const void * D)
{
    struct medal *A=(struct medal *)C; 
    struct medal *B=(struct medal *)D;
    if(A->a!=B->a)
        return (A->a > B->a);
    else if(A->b!= B->b)
        return (A->b > B->b);
    else if(A->c!= B->c)
        return (A->c > B->c);
    else
        return (A->d > B->d);
}

typedef struct medal ElementType;
typedef ElementType* ElemTypePtr;



int main()
{
    int N;
    scanf("%d",&N);
    struct medal* data=malloc(N*sizeof(ElementType));
    for(int i=0;i<N;i++)
        scanf("%s %d %d %d %d",data[i].state,&data[i].a,&data[i].b,&data[i].c,&data[i].d);
    qsort(data,N,sizeof(struct medal), compare);
    for(int i=N;i>=0;i--)
        printf("%s ",data[i].state);
    return 0;
}