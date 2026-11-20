#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push();
void pop();
void trav();

int main()
{
    int c;

    while (1)
    {
        printf("\n\nPress 1 for Push");
        printf("\nPress 2 for Pop");
        printf("\nPress 3 for Traversal");
        printf("\nPress 4 for Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                trav();
                break;

            case 4:
                printf("\nProgram Terminated.");
                exit(0);

            default:
                printf("\nWrong Choice");
        }
    }

    return 0;
}

void push()
{
    int data;

    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
        return;
    }

    printf("\nInput the data to be stored: ");
    scanf("%d", &data);

    top++;
    stack[top] = data;

    printf("\n%d is inserted", data);
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
        return;
    }

    printf("\n%d is deleted", stack[top]);
    top--;
}

void trav()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is Empty");
        return;
    }

    printf("\nStack Elements: ");

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}
