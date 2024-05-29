#include <stdio.h>

void genarateFibonacci(int n)
{
    int first = 0, second = 1, next;

    printf("Fibonacci series:");

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("%d ", first);
            continue;
        }
        else
        {
            if (i == 1)
            {
                printf("%d ", second);
                continue;
            }
            else
            {
                next = first + second;
                first = second;
                second = next;
                printf("%d ", next);
            }
        }
    }
    printf("\n");
}

// recursion process
int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
void printFibonacci(int n, int i)
{
    if (i < n)
    {
        printf("%d ", Fibonacci(i));
        printFibonacci(n, i + 1);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter a valid positive number..\n");
    }
    else
    {
        genarateFibonacci(n);

        printFibonacci(n,0);
    }

    return 0;
}
