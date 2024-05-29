#include <stdio.h>
#include <stdlib.h>

void readWriteExample(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the first line
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from file: %s", buffer);
    }

    // Move the file pointer to the beginning and write to the file
    fseek(file, 0, SEEK_SET);
    fprintf(file, "Updated line\n");

    fclose(file);
}

int main() {
    const char *filename = "example_r+.txt";

    // Create and write initial content to the file
    FILE *file = fopen(filename, "w");
    fprintf(file, "Original line\n");
    fclose(file);

    // Read and update the file using r+ mode
    readWriteExample(filename);

    return 0;
}
