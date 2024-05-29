#include <stdio.h>

int main()
{
    int n, i, isPrime = 1; // Assuming the number is prime initially

    printf("Enter a number to check if it's prime or not: ");
    scanf("%d", &n);

    // Corner cases
    if (n <= 1)
    {
        printf("%d is not a prime number.\n", n);
        return 0;
    }

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = 0; // If n is divisible by any number, it's not prime
            break;
        }
    }

    if (isPrime)
    {
        printf("%d is a prime number.\n", n);
    }
    else
    {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}
