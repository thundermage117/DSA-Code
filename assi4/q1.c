#include<stdio.h>

struct data
{
    int num;
    char name[24];
};

void RadixCountSort(struct data* A,int n,int pwr_ten)
{
    int i;
    unsigned long int count[10]; // [0..9]    
    struct data B[n];

    for(i=0;i<10;i++)
        count[i] = 0;

    for(i=0;i<n;i++) {
        ++count[ (A[i].num/pwr_ten) % 10];
        B[i].num = 0;
    }
    
    for(i=1;i<10;i++)
        count[i] = count[i] + count[i-1];
    
    for(i= n -1; i >= 0 ; i--)
    {
        --count[(A[i].num/pwr_ten) % 10];
        B[count[(A[i].num/pwr_ten) % 10]] = A[i];
        //PrintArray(B,n);
    }

    for(i=0;i< n ;i++)
        A[i] = B[i]; 
}

void RadixSort(struct data* A,int n)
{
    int pwr_ten;
    struct data max_elem = A[0];    
    for(int i = 0 ; i < n ; i++)
        if (A[i].num > max_elem.num)
            max_elem.num = A[i].num;
    
    // Loop as many times as the digits in the maximum element
    pwr_ten = 1;
    while( max_elem.num / pwr_ten > 0)
    {
        RadixCountSort(A,n,pwr_ten);
        pwr_ten *= 10;
    }
        
}
int main()
{
    int N;
    scanf("%d",&N);
    struct data patient[100000];
    for(int i=0;i<N;i++)
    {
        scanf("%d %s", &patient[i].num,patient[i].name);
    }
    RadixSort(patient,N);
    for(int i=0;i<N;i++)
    {
        printf("%d %s\n", patient[i].num,patient[i].name);
    }
    return 0;
}