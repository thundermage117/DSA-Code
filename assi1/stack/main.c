#include"my_stack.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu()
{
    printf("\nOperations on Stack\n");
    printf("1.Push\n2.Pop\n3.Exit\n");
    printf("Enter your option:");
}


int main()
{
    initstack();
    int ch=0;
    double a,b;
    while(1)
    {
        while(1)
        {
            menu();
            scanf("%d",&ch);
            if(ch==1||ch==2||ch==3)
                break;
            else{
                printf("Wrong input, retry\n");
                while ((getchar()) != '\n');
            }
        }
        switch (ch)
        {
        case 1:
        {
            printf("Enter 2 numbers: ");
            scanf("%lf %lf",&a,&b);//pls don't input strings here
            push(a,b);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            exit(0);
        }
        
    }
    return 0;
}


/*this program can be extended to n- dimensional complex numbers 
 by taking n as input, then using a dynamic array as seen in 
 problem 1
 */