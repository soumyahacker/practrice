#include <stdio.h>

#define MAX_SIZE 3 // Maximum size for row and column
#define MIN_SIZE 2 // Minimum size for row and column

// Function to input matrix from the user
void inputMatrix(int rows, int cols, int matrix[][MAX_SIZE])
{
    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// logic for matrix multiplication
void multiplyMatrix(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int rows1, int cols1, int cols2, int result[][MAX_SIZE])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// logic for display matrix
void displayMatrix(int rows, int cols, int matrix[][MAX_SIZE])
{
    printf("Resultant matrix after multiplication is :\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows1, cols1, rows2, cols2;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Input matrix 1
    printf("Enter the number of rows for the first matrix (2 or 3): ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix (2 or 3): ");
    scanf("%d", &cols1);
    if (rows1 < MIN_SIZE || cols1 < MIN_SIZE || rows1 > MAX_SIZE || cols1 > MAX_SIZE)
    {
        printf("Invalid input. Number of rows and columns must be between 2 and 3.\n");
        return 1; // Returning error code
    }
    inputMatrix(rows1, cols1, mat1);

    // Input matrix 2
    printf("Enter the number of rows for the second matrix (2 or 3): ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix (2 or 3): ");
    scanf("%d", &cols2);
    if (rows2 < MIN_SIZE || cols2 < MIN_SIZE || rows2 > MAX_SIZE || cols2 > MAX_SIZE)
    {
        printf("Invalid input. Number of rows and columns must be between 2 and 3.\n");
        return 1; // Returning error code
    }

    // Check if multiplication is possible
    if (cols1 != rows2)
    {
        printf("Matrix multiplication not possible. Number of columns in matrix 1 must be equal to number of rows in matrix 2.\n");
        return 1; // Returning error code
    }

    inputMatrix(rows2, cols2, mat2);

    // Perform matrix multiplication
    multiplyMatrix(mat1, mat2, rows1, cols1, cols2, result);

    // Display the result
    displayMatrix(rows1, cols2, result);

    return 0;
}
