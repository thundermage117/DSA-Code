#include<stdio.h>
#include<string.h>
#include "hash.h"
#include<stdlib.h>



int main()
{
    int N,M,p=32;
    scanf("%d",&N);
    char str[33];
    HashTable myHt=CreateHashTable(1000);
    int collision=0;
    for(int i=0;i<N;i++)
    {
        scanf("%s",str);
        unsigned long long int t=polyhash(str,strlen(str),p)%1000000007;
        InsertElement(t,myHt);
    }
    scanf("%d",&M);
    char ** words=malloc (M*sizeof (char *));
    int ctr=0;
    for(int i=0;i<M;i++)
    {
        scanf(" %s",str);
        unsigned long long int t=polyhash(str,strlen(str),p)%1000000007;
        Node temp=FindInTable(t,myHt);
        if(temp==NULL)
        {
            //printf("%s\n",str);
            words[ctr]=(char*) malloc(sizeof(str));
            strcpy(words[ctr],str);
            ctr++;
        }
        

    }   
    printf("%d\n",ctr);
    for(int i=0;i<ctr;i++)
        printf("%s\n",words[i]);
    free(words);

    return 0;
}
