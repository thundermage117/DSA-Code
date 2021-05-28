#include<stdio.h>
#include<stdlib.h>

struct info
{
    int risk;
    int val;
};


int main()
{
    int Q,ct;
    scanf("%d %d",&Q,&ct);
    int ctr=0;
    int total_patients=0;
    struct info *arr=malloc(Q*sizeof(struct info));//can be optimized, if space
    for(int i=0;i<Q;i++)
    {   
        arr[i].risk=-1;
        arr[i].val=-1;
    }
    for(int i=0;i<Q;i++)
    {
        char ch;int a,b;
        scanf(" %c",&ch);
        if(ch=='?')
        {
            scanf("%d",&a);
            int ctr1=0,ctr2=0;
            for(int k=0;k<ctr;k++)
            {    if(arr[k].val>a && arr[k].risk==1)
                    ctr1++;
                if(arr[k].risk==1)
                    ctr2++;

            }
            float t=(float)ctr2/ctr1;
            if(t>1)
                t=1/t;
            printf("%g\n",t);
            
        }
        else if(ch=='+')
        {
            scanf("%d %d",&b,&a);
            if(b>ct)
            {    arr[ctr].risk=1;
                total_patients++;
            }
            else
                arr[ctr].risk=0;
            arr[ctr].val=a;
            ctr++;
            
        }
        else
        {
            scanf("%d %d",&b,&a);
            int t=0;
            if(b>ct)
            {   t=1;total_patients--;}
            for(int j=0;j<ctr;j++)
                if(arr[j].val==a&&arr[j].risk==t)
                {
                    arr[j].val=-1;
                    arr[j].risk=-1;
                    break;
                }
            
        }


    }



    return 0;
}
/*
14 5
+ 8 8
? 7
+ 8 4
? 7
+ 8 5
? 7
- 8 4
? 7
- 8 8
? 7
+ 3 9
+ 5 9
+ 5 3
? 4

10 5
+ 7 8
? 4
+ 7 9
? 4
+ 7 3
? 4
+ 7 2
? 4
+ 3 9
? 4

1
1
0.666667
0.5
0.5
*/