// linear search on a linked list 

#include <stdio.h>
#include <stdlib.h>
void Insertlast();
void trav();
void Dellast();
void Search_Link();
struct node
{
    int info;
    struct node *link;
};
typedef struct node NODE;
NODE *start = NULL;
void main()
{
    int c;
menu:
    printf("\nPress 1 for Insertion");
    printf("\nPress 2 for Deletion");
    printf("\nPress 3 for Traversal");
    printf("\nPress 4 for Search");
    printf("\nPress 5 for Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            Insertlast();
            goto menu;
        case 2:
            Dellast();
            goto menu;
        case 3:
            trav();
            goto menu;
        case 4:
            Search_Link();
            goto menu;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice");
            goto menu;
    }
}
void Insertlast()
{
    NODE *ptr, *newNODE;
    int data;
    newNODE = (NODE *)malloc(sizeof(NODE));
    printf("Input the data to be stored in Linked List: ");
    scanf("%d", &data);
    newNODE->info = data;
    newNODE->link = NULL;
    if(start == NULL)
    {
        start = newNODE;
    }
    else
    {
        ptr = start;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newNODE;
    }
}
void trav()
{
    NODE *ptr;
    if(start == NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    ptr = start;
    printf("\nLinked List: ");
    while(ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
}
void Dellast()
{
    NODE *ptr, *prev;
    if(start == NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }
    if(start->link == NULL)
    {
        printf("\n%d is deleted", start->info);
        free(start);
        start = NULL;
        return;
    }
    ptr = start;
    while(ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = NULL;
    printf("\n%d is deleted", ptr->info);
    free(ptr);
}
void Search_Link()
{
    NODE *ptr;
    int se, pos = 1, flag = 0;
    printf("Input Search Element\n");
    scanf("%d", &se);
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->info == se)
        {
            flag = 1;
            break;
        }
        else
        {
            ptr = ptr->link;
            pos++;
        }
    }
    if(flag == 1)
        printf("Element found at %d", pos);
    else
        printf("Element not found");
}
