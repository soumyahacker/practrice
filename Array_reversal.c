#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reversal(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - i - 1]);
    }
}

int main() {
    int arr[] = {1, 3, 4, 0, 5, 4, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    reversal(arr, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
