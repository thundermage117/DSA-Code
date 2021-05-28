#include "complex.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char type[4]; int n;
    scanf("%s %d",type,&n);
    
    if(strcmp(type,"DOT")==0)
        printf("%lld",DOT(n,createcomp(n),createcomp(n)));

    else if(strcmp(type,"MOD")==0)
        printf("%.2f",MOD(n,createcomp(n)));
    
    else if(strcmp(type,"ADD")==0)
        printcomp(n,ADD(n,createcomp(n),createcomp(n)));
    
    else if(strcmp(type,"SUB")==0)
        printcomp(n,SUB(n,createcomp(n),createcomp(n)));//note that the right-most createcomp() is executed first

    printf("\n");
    return 0;
}