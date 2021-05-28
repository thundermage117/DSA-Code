#include "complex.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

complex createcomp(int n)
{
    complex a;
    a = (complex) malloc(n*sizeof(complex));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    return a;
}

complex ADD(int n,complex a, complex b)
{
    complex c=(complex) malloc(n*sizeof(complex));
    for(int i=0;i<n;i++)
        c[i]=a[i]+b[i];
    return c;
}

complex SUB(int n,complex a, complex b)
{
    complex c=(complex) malloc(n*sizeof(complex));
    for(int i=0;i<n;i++)
        c[i]=b[i]-a[i];
    return c;
}

double MOD(int n,complex a)
{
    double sum=0;
    for(int i=0;i<n;i++)
        sum+=(double)a[i]*a[i];
    return sqrt(sum);
}

big_no DOT(int n, complex a,complex b)
{
    big_no sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i]*b[i];
    return sum;
}

void printcomp(int n,complex a)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

}