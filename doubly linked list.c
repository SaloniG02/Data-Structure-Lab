

#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *back;
    int info;
    struct node *forw;
};
void insfirst();
void inslast();
void delfirst();
void dellast();
void fortrav();
void backtrav();
typedef struct node NODE;
NODE *first = NULL;
NODE *last = NULL;
int main()
{
    int c;
menu:
    printf("\nDOUBLY LINKED LIST");
    printf("\nPress 1 for Insertion at first");
    printf("\nPress 2 for Insertion at last");
    printf("\nPress 3 for Deletion of first node");
    printf("\nPress 4 for Deletion of last node");
    printf("\nPress 5 for Forward Traversing");
    printf("\nPress 6 for Backward Traversing");
    printf("\nPress 7 for Exit");
    printf("\nInput your choice: ");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            insfirst();
            goto menu;
        case 2:
            inslast();
            goto menu;
        case 3:
            delfirst();
            goto menu;
        case 4:
            dellast();
            goto menu;
        case 5:
            fortrav();
            goto menu;
        case 6:
            backtrav();
            goto menu;
        case 7:
            printf("\nProgram Terminated.");
            exit(0);
        default:
            printf("\nInvalid Choice.");
            goto menu;
    }
    return 0;
}
void insfirst()
{
    NODE *newNODE;
    int data;
    newNODE = (NODE *)malloc(sizeof(NODE));
    if(newNODE == NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nInput the data to be inserted: ");
    scanf("%d", &data);
    newNODE->info = data;
    newNODE->back = NULL;
    newNODE->forw = NULL;
    if(first == NULL)
    {
        first = newNODE;
        last = newNODE;
    }
    else
    {
        newNODE->forw = first;
        first->back = newNODE;
        first = newNODE;
    }
    printf("\nNode inserted at first successfully.");
}
void inslast()
{
    NODE *newNODE;
    int data;
    newNODE = (NODE *)malloc(sizeof(NODE));
    if(newNODE == NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nInput the data to be inserted: ");
    scanf("%d", &data);
    newNODE->info = data;
    newNODE->forw = NULL;
    newNODE->back = NULL;
    if(first == NULL)
    {
        first = newNODE;
        last = newNODE;
    }
    else
    {
        newNODE->back = last;
        last->forw = newNODE;
        last = newNODE;
    }
    printf("\nNode inserted at last successfully.");
}
void delfirst()
{
    NODE *temp;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is Empty.");
        return;
    }
    temp = first;
    if(first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->forw;
        first->back = NULL;
    }
    printf("\nDeleted element = %d", temp->info);
    free(temp);
}
void dellast()
{
    NODE *temp;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is Empty.");
        return;
    }
    temp = last;
    if(first == last)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->back;
        last->forw = NULL;
    }
    printf("\nDeleted element = %d", temp->info);
    free(temp);
}
void fortrav()
{
    NODE *temp;
    if(first == NULL)
    {
        printf("\nDoubly Linked List is Empty.");
        return;
    }
    temp = first;
    printf("\nForward Traversing:\n");
    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->forw;
    }
}
void backtrav()
{
    NODE *temp;
    if(last == NULL)
    {
        printf("\nDoubly Linked List is Empty.");
        return;
    }
    temp = last;
    printf("\nBackward Traversing:\n");
    while(temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->back;
    }
}
