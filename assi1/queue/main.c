#include"deque.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu()
{
    printf("\nOperations on Queue\n");
    printf("1.Push\n2.Inject\n3.Pop\n4.Eject\n5.Exit\n");
    printf("Enter your option:");
}

int main()
{
    int ch=0;
    double a,b;
    initstack();
    while(1)
    {
        while(1)
        {
            menu();
            scanf("%d",&ch);
            if(ch==5)
                exit(0);
            if(ch==1||ch==2||ch==3||ch==4)
                break;
            else{
                printf("Wrong input, retry\n");
                while ((getchar()) != '\n');
            }
        }
        switch (ch)
        {
        
        case 1:
            printf("Enter 2 numbers: ");
            scanf("%lf %lf",&a,&b);//pls don't input strings here
            push(a,b);
            break;

        case 2:
            printf("Enter 2 numbers: ");
            scanf("%lf %lf",&a,&b);
            inject(a,b);
            break;
        case 3:
            pop();
            break;
        case 4:
            eject();
            break;
        default:
            exit(0);
        }
    } 
    
    return 0;
}