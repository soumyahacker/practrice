#include <stdio.h>
#include <stdlib.h>

void writeBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int numbers[] = {1, 2, 3, 4, 5};
    fwrite(numbers, sizeof(int), 5, file);

    fclose(file);
}

void readBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int numbers[5];
    fread(numbers, sizeof(int), 5, file);

    for (int i = 0; i < 5; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    fclose(file);
}

int main() {
    const char *filename = "example_binary.dat";

    // Write to the binary file
    writeBinaryFile(filename);

    // Read from the binary file
    readBinaryFile(filename);

    return 0;
}
