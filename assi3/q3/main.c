#include<stdio.h>
#include<string.h>

int check(char* a, char* b) //a is smaller than b
{
    if(strlen(b) % strlen(a) != 0)
        return 0;
      
    int count = strlen(b) /strlen(a);
    char str[10000] = "\0";
    for(int i = 0; i < count; i++)
    {
        strcat(str,a);
    }
    if(strcmp(str,b)==0)
        return 1;
      
    return 0; 
}
int main()
{
    char A[10000],B[10000];
    scanf("%s",A);
    scanf("%s",B);
    if(strlen(B)<strlen(A))
    {
        char C[10000];
        strcpy(C,A);
        strcpy(A,B);
        strcpy(B,C);
    }
    //printf("%s %s",A,B);
    int ctr=0;
    char str[10000]="\0";
    for(int i=0;i<strlen(A);i++)
    {
        str[i]=A[i];
    if(check(str,A)&&check(str,B))
        ctr++;
    }
    printf("%d",ctr);
    return 0;
}