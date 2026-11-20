#include <stdio.h>

int main()
{
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    int a[r1][c1];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    int b[r2][c2];

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    do
    {
        printf("\n MENU \n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (r1 == r2 && c1 == c2)
                {
                    printf("\nAddition Result:\n");

                    for (int i = 0; i < r1; i++)
                    {
                        for (int j = 0; j < c1; j++)
                        {
                            printf("%d ", a[i][j] + b[i][j]);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("Addition not possible.\n");
                }
                break;

            case 2:
                if (c1 == r2)
                {
                    int sum;

                    printf("\nMultiplication Result:\n");

                    for (int i = 0; i < r1; i++)
                    {
                        for (int j = 0; j < c2; j++)
                        {
                            sum = 0;

                            for (int k = 0; k < c1; k++)
                            {
                                sum = sum + a[i][k] * b[k][j];
                            }

                            printf("%d ", sum);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("Multiplication not possible.\n");
                }
                break;

            case 3:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}
