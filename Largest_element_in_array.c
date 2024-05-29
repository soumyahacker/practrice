#include <stdio.h>

int returnMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}


int main()
{
    int arr[] = {9, 4, 56, 76, 8, 7, 54, 3, 23, 59, 5, 0};
    int length = sizeof(arr)/sizeof(arr[0]);
    int max = returnMax(arr, length);
    printf("The maximum element in array is:%d", max);
    return 0;
}
