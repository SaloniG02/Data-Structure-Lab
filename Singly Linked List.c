
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node NODE;

NODE *start = NULL;

void create();
void Insertlast();
void Dellast();
void trav();

int main()
{
    int c;

    while (1)
    {
        printf("\n\nPress 1 for Creation");
        printf("\nPress 2 for Insertion");
        printf("\nPress 3 for Deletion");
        printf("\nPress 4 for Traversal");
        printf("\nPress 5 for Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
            case 1:
                create();
                break;

            case 2:
                Insertlast();
                break;

            case 3:
                Dellast();
                break;

            case 4:
                trav();
                break;

            case 5:
                exit(0);

            default:
                printf("\nWrong Choice");
        }
    }

    return 0;
}

void create()
{
    int n, i, data;
    NODE *newNODE, *ptr;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        newNODE = (NODE *)malloc(sizeof(NODE));

        if (newNODE == NULL)
        {
            printf("\nMemory allocation failed");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newNODE->info = data;
        newNODE->link = NULL;

        if (start == NULL)
        {
            start = newNODE;
        }
        else
        {
            ptr = start;

            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }

            ptr->link = newNODE;
        }
    }

    printf("\nLinked List Created");
}

void Insertlast()
{
    NODE *ptr, *newNODE;
    int data;

    newNODE = (NODE *)malloc(sizeof(NODE));

    if (newNODE == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nInput data: ");
    scanf("%d", &data);

    newNODE->info = data;
    newNODE->link = NULL;

    if (start == NULL)
    {
        start = newNODE;
    }
    else
    {
        ptr = start;

        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }

        ptr->link = newNODE;
    }

    printf("\nElement Inserted");
}

void Dellast()
{
    NODE *ptr, *prev;

    if (start == NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }

    if (start->link == NULL)
    {
        printf("\n%d is deleted", start->info);
        free(start);
        start = NULL;
        return;
    }

    ptr = start;

    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    prev->link = NULL;

    printf("\n%d is deleted", ptr->info);
    free(ptr);
}

void trav()
{
    NODE *ptr;

    if (start == NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }

    ptr = start;

    printf("\nLinked List: ");

    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
}
