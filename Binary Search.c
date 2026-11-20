
#include <stdio.h>

int data[100], n, se;

int bs(int data[], int n, int se)
{
    int lb = 0, ub = n - 1, mid;

    while (lb <= ub)
    {
        mid = (lb + ub) / 2;

        if (data[mid] == se)
            return mid;

        if (se > data[mid])
            lb = mid + 1;
        else
            ub = mid - 1;
    }

    return -1;
}

int binarySearchrec(int data[], int lb, int ub, int se)
{
    int mid;

    if (lb > ub)
        return -1;

    mid = (lb + ub) / 2;

    if (data[mid] == se)
        return mid;

    if (se > data[mid])
        return binarySearchrec(data, mid + 1, ub, se);
    else
        return binarySearchrec(data, lb, mid - 1, se);
}

int main()
{
    int i, pos, ch;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("Enter search element: ");
    scanf("%d", &se);

    printf("\n1. Binary Search Without Recursion");
    printf("\n2. Binary Search With Recursion");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    if (ch == 1)
        pos = bs(data, n, se);
    else if (ch == 2)
        pos = binarySearchrec(data, 0, n - 1, se);
    else
    {
        printf("Invalid choice");
        return 0;
    }

    if (pos == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", pos + 1);

    return 0;
}
