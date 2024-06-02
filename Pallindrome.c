#include <stdio.h>

int main()
{
    int num, originalNum, reversedNum = 0, remainder;

    // Input number from user
    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    // Reversed integer is stored in reversedNum
    while (num != 0)
    {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    // Palindrome if originalNum and reversedNum are equal
    if (originalNum == reversedNum)
    {
        printf("%d is a palindrome.\n", originalNum);
    }
    else
    {
        printf("%d is not a palindrome.\n", originalNum);
    }

    return 0;
}
