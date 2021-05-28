#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


int main()
{
    char str[20],type;
    scanf("%s",str);
    int N, Q;
    HashTable myHt;
    if(strcmp(str,"separate-chaining")==0)
    {
        scanf("%d %d",&N,&Q);
        myHt = CreateHashTable(N);
        for(int i=0;i<Q;i++)
        {
            int val;
            scanf(" %c %d",&type,&val);
            if(type=='?')
            {
                Node temp=FindInTable(val,myHt);
                if(temp!=NULL)
                    printf("%d\n",chaining_search(val, myHt));
                else 
                    printf("-1");
            }
            else if(type=='+')
                chaining_insert(val,myHt);
        }
        DeleteHashTable(myHt);

    }
    if(strcmp(str,"linear-probing")==0)
    {
        scanf("%d %d",&N,&Q);
        myHt = CreateHashTable(N);
        for(int i=0;i<Q;i++)
        {
            int val;
            scanf(" %c %d",&type,&val);
            if(type=='?')
                printf("%d\n",linear_search(val, myHt));
            else if(type=='+')
                linear_insert(val,myHt);
        }
        DeleteHashTable(myHt);
    }
    if(strcmp(str,"quadratic-probing")==0)
    {
        scanf("%d %d",&N,&Q);
        myHt = CreateHashTable(N);
        for(int i=0;i<Q;i++)
        {
            int val;
            scanf(" %c %d",&type,&val);
            if(type=='?')
                printf("%d\n",quad_search(val, myHt));
            else if(type=='+')
                quad_insert(val,myHt);
        }
        DeleteHashTable(myHt);
    }
    return 0;
}
