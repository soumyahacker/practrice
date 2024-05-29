#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0]; 


    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
    }

    return max;
}

int main() {
    int arr[] = {10, 5, 7, 3, 15, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, size);
    printf("Maximum element in the array: %d\n", max);

    return 0;
}
