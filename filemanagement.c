#include <stdio.h>
#include <stdlib.h>

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");
    fclose(file);
    printf("Data written to file successfully.\n");
}

void readFile(const char *filename) {
    char buffer[256];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    printf("Contents of the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Appending a new line to the file.\n");
    fclose(file);
    printf("Data appended to file successfully.\n");
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }
}

int main() {
    const char *filename = "example.txt";

    // Write to file
    writeFile(filename);

    // Read from file
    readFile(filename);

    // Append to file
    appendFile(filename);

    // Read from file again to see appended content
    readFile(filename);

    // Delete file
    deleteFile(filename);

    return 0;
}
