#include <stdio.h>
#include <stdlib.h>

void writeReadExample(const char *filename) {
    FILE *file = fopen(filename, "w+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write to the file
    fprintf(file, "Hello, World!\n");

    // Move the file pointer to the beginning to read the content
    fseek(file, 0, SEEK_SET);

    // Read the content
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from file: %s", buffer);
    }

    fclose(file);
}

int main() {
    const char *filename = "example_w+.txt";
    writeReadExample(filename);
    return 0;
}
