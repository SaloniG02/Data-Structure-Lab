#include <stdio.h>

int stack[50];
int top = -1;

void push(int a);
int pop();

int main()
{
    char postexp[50];
    int i, res;
    int a, b;

    printf("Enter the postfix expression: ");
    scanf("%49s", postexp);

    for (i = 0; postexp[i] != '\0'; i++)
    {
        if (postexp[i] >= '0' && postexp[i] <= '9')
        {
            push(postexp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postexp[i])
            {
                case '+':
                    res = a + b;
                    break;

                case '-':
                    res = a - b;
                    break;

                case '*':
                    res = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Error: Division by zero.\n");
                        return 1;
                    }
                    res = a / b;
                    break;

                default:
                    printf("Invalid operator.\n");
                    return 1;
            }

            push(res);
        }
    }

    res = pop();

    printf("Result = %d\n", res);

    return 0;
}

void push(int a)
{
    if (top == 49)
    {
        printf("Stack Overflow.\n");
        return;
    }

    top++;
    stack[top] = a;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return 0;
    }

    return stack[top--];
}
