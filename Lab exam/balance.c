#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef char ElementType;

typedef struct StackInfo* Stack;

struct StackInfo {    
    long int MaxNumItems;
    long int TopId;
    ElementType *StackItem;
};
Stack InitStack(unsigned long int max_items)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct StackInfo));    
    assert(S != NULL);

    S->MaxNumItems = max_items;
    S->StackItem = (ElementType*)malloc(S->MaxNumItems*sizeof(ElementType));
    assert(S->StackItem != NULL);

    S->TopId = -1;

    return S;
}

void Push(Stack S,ElementType E)
{
    if(S->TopId < S->MaxNumItems)
    {
        ++S->TopId;
        S->StackItem[S->TopId] = E; // CopyItem(S,TopId,E)
    }
}


int IsEmpty(const Stack S)
{
    return (S->TopId == -1);
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
        --S->TopId;
}

ElementType Top(const Stack S)
{
    if(!IsEmpty(S))
        return S->StackItem[S->TopId];
       
}



void ClearStack(Stack S)
{
    S->TopId = -1;
}

void DeleteStack(Stack* SP)
{ 
    if(*SP)
    {
        free((*SP)->StackItem);
        free(*SP);   
        *SP = NULL;
    }
}

int balance(char* arr,int size)
{

    Stack S=InitStack(size);
    for(int i=0;i<size,i++)
    {
        if(arr[i]=='{'||arr[i]=='('||arr[i]=='['||(arr[i]=='\\' &&arr[i+1]=='\\'))
            return 0;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    char *arr=malloc(N*sizeof(char));
    scanf("%s",arr);

}