#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void trav();
int max=8;top=-1,stack[100];
void main()
{
    int c;
    menu:
        printf("\npress 1 for push operation");
        printf("\npress 2 for pop operation");
        printf("\npress 3 for travs operation");
        printf("\npress 1 for push operation");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            push();
            goto menu;
        case 2:
            pop();
            goto menu;
        case 3:
            trav();
            goto menu;
        default:
            printf("Invalid Choice\n");
            goto menu;
        }
}
void push()
{
    int d,i;
    printf("\nInput the data value");
    scanf("%d",&d);
    if(top==max)
    {
         printf("\nOverflow");
         return 0;
    }
    else
    {
        top=top+1;
        stack[top]=d;
    }
}
void pop()
{
    int d;
    if(top==-1)
    {
        printf("\nunderflow");
    }
    d=stack[top];
    top--;
    printf("\n%d is popped",d);
    return 0;
}
void trav()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\n Stack Elements:\t");
        for(i=top;i>=0;i--)
            printf("\t%d",stack[i]);
    }
}
