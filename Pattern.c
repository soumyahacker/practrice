#include <stdio.h>

void Pattern(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void Reverse_star_pattern(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int rows, type;
    printf("Enter 0 for star pattern, 1 for reverse star pattern, and 2 for both: \n");
    scanf("%d", &type);
    printf("How many rows do you want?\n");
    scanf("%d", &rows);

    switch (type)
    {
    case 0:
        printf("Star pattern:\n");
        Pattern(rows);
        break;
    case 1:
        printf("Reverse star pattern:\n");
        Reverse_star_pattern(rows);
        break;
    case 2:
        Pattern(rows);
        Reverse_star_pattern(rows);
        break;
    default:
        printf("Invalid choice!\n");
    }

    return 0;
}
