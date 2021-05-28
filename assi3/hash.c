#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

/////////////////////////////////////////////
/////////////////// HashTable.c ////////////
// This file containts implemnetaion of HashTable
/////////////////////////////////////////////



/////////////////////////////////////////////
// Function CreateHashTable
// Inputs   TableSize/Max poss keys
// Outputs  Pointer to the the hashtable, namely HashTable
/////////////////////////////////////////////
HashTable   CreateHashTable(int iTableSize)
{
    int i=0;
    HashTable myHt;
    // First allocate memory to hold table size and starting buckets
    myHt= malloc(sizeof(struct stHT));
    if( myHt == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }
    myHt->iTableSize = iTableSize;
    myHt->pStart = malloc(iTableSize*sizeof(Node));
    if( myHt->pStart == NULL)
    {
        printf("Memory Full!!\n");
        exit(0);
    }

    // Now allocate memory to have a linked list in each bucket
    for(i=0;i<iTableSize;i++)
    {
        myHt->pStart[i] = malloc(sizeof(struct stNode));
        if( myHt->pStart[i] == NULL)
        {
            printf("Memory Full!!\n");
            exit(0);
        }
        (myHt->pStart[i])->pNext= NULL;
        myHt->pStart[i]->iElement = _invalid;

    }
    return myHt;
}
/////////////////////////////////////////////
Key         getHash(Element n,HashTable myHT)
{
    if (myHT->iTableSize !=0)
        return n%myHT->iTableSize;
    else
    {
        printf("Table Size 0\n");
        return -1;
    }
}
/////////////////////////////////////////////
Node        FindInTable(Element n, HashTable myHT)
{
    Node Position=NULL;
    Key k;
    k= getHash(n,myHT);
    Position = myHT->pStart[k]->pNext;
    while((Position != NULL) && (Position->iElement != n ))
        Position = Position->pNext;

    return Position;
}


/////////////////////////////////////////////
void        InsertElement(Element n, HashTable myHt)
{
    Node Position;
    Key k;
    Position = FindInTable(n, myHt);
    if(Position == NULL)
    {
        Position = malloc(sizeof(struct stNode));
        if (Position == NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        k= getHash(n,myHt);
        Position->pNext         = myHt->pStart[k]->pNext;
        Position->iElement      = n;
        myHt->pStart[k]->pNext  = Position;
    }

    return;
}


/////////////////////////////////////////////


int         GetNoElements(Element iKey, HashTable myHt)
{
    int num_elems=0;
    Key k;
    Node Search;
    k=getHash(iKey,myHt);
    Search = myHt->pStart[k];
    while(Search != NULL)
    {
        if(Search->iElement == iKey)
            num_elems++;
    }
    return num_elems;
}

/////////////////////////////////////////////
void         DeleteElement(Element iKey, HashTable myHt)
{
    Key k;
    Node Search,prev;
    k=getHash(iKey,myHt);
    Search = myHt->pStart[k];
    //prev=Search;
    while (Search != NULL)
    {
        if (Search->pNext  !=NULL && Search->pNext->iElement == iKey)
        {
            Search->pNext = Search->pNext->pNext;
            //next = 
            free(Search->pNext);
        }
        Search = Search->pNext;

        
    }
    return;
}
/////////////////////////////////////////////
void        DeleteHashTable(HashTable myHT)
{
    int i;
    EmptyTable(myHT);
    for(i=0;i<myHT->iTableSize;i++)
    {
      //free(myHT->pStart[i]);
    }
    free(myHT);
    return;
}
/////////////////////////////////////////////
void        EmptyTable(HashTable myHT)
{
    int i;
    Node Curr, Next;
    for(i=0;i<myHT->iTableSize;i++)
    {
        Curr = myHT->pStart[i];//->pNext;
        while (Curr != NULL)
        {
            Next = Curr->pNext;
            free(Curr);
            Curr = Next;
        }
    }
    return;
}



/////////////////////////////////////////////
HashTable   ReHash(HashTable myHT)
{
    HashTable NewTable,temp;
    int iNewSize=0,i=0,iOldSize;

    iOldSize = myHT->iTableSize;
    iNewSize = 2*iOldSize;
    NewTable = CreateHashTable(iNewSize);

    for(i=0;i<iOldSize;i++)
    {
        if(myHT->pStart[i]->iElement!=-5555)
            quad_insert(myHT->pStart[i]->iElement,NewTable);
    }
    return NewTable;

    

}

int        chaining_search(Element n, HashTable myHT)
{
    Node Position=NULL;
    Key k;
    int num=0;
    k= getHash(n,myHT);
    Position = myHT->pStart[k]->pNext;
    while((Position != NULL) && (Position->iElement != n ))
    {    Position = Position->pNext;num++;}

    return num;
}

void        chaining_insert(Element n, HashTable myHt)
{
    Node Position;
    Key k;
    Position = FindInTable(n, myHt);
    if(Position == NULL)
    {
        Position = malloc(sizeof(struct stNode));
        if (Position == NULL)
        {
            printf("Out of Memory\n");
            exit(0);
        }
        k= getHash(n,myHt);
        Position->pNext=NULL;
        Position->iElement      = n;
        Node temp=myHt->pStart[k];
        while(temp!=NULL&&temp->pNext!=NULL)
            temp=temp->pNext;
        temp->pNext=Position;
    }

    return;
}

int        linear_insert(Element n, HashTable myHt)
{
    Node Position;
    Key k;
    Position = FindInTable(n, myHt);
    int probes=1;
    if(Position == NULL)
    {
        
        k= getHash(n,myHt);
        while((myHt->pStart[k]->iElement)!= -5555)
        {
            probes++;
            k++;
            if(k==myHt->iTableSize)
                k=0;
        }
        myHt->pStart[k]->iElement=n;
        
    }

    return probes;
}

int        quad_insert(Element n, HashTable myHt)
{
    Node Position;
    Key k;
    int ctr=1,temp;
    Position = FindInTable(n, myHt);
    if(Position == NULL)
    {
        k= getHash(n,myHt);
        temp=k;
        while((myHt->pStart[k]->iElement)!= -5555)
        {
            k=temp;
            k+=ctr*ctr;
            ctr++;
            if(k>=myHt->iTableSize)
                k%=myHt->iTableSize;
        }
        myHt->pStart[k]->iElement=n;
        
    }

    return ctr;
}

int linear_search(Element n, HashTable myHt)
{
    int k= getHash(n,myHt);int t=k;
    while((myHt->pStart[k]->iElement)!= n)
    {
        k++;
        if(k==myHt->iTableSize)
            k=0;
        if(k==t)
            return -1;
    }
    return k;
}

int quad_search(Element n, HashTable myHt)
{
    int k= getHash(n,myHt);int t=k,ctr=1;
    while((myHt->pStart[k]->iElement)!= n)
    {
        k=t;
        k+=ctr*ctr;
        ctr++;
        if(k>=myHt->iTableSize)
            k%=myHt->iTableSize;
        if(k==t)
            return -1;
    }
    return k;
}

unsigned long long int polyhash(char poly[], int n, int x)
{
    unsigned long long int result = poly[0]-'a'+1;
    for (int i=1; i<n; i++)
        result = result*x + poly[i]-'a'+1;
  
    return result;
}
