#include <stdio.h>
#include <stdlib.h>

void appendReadExample(const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Append to the file
    fprintf(file, "Appended line\n");

    // Move the file pointer to the beginning to read the content
    fseek(file, 0, SEEK_SET);

    // Read the content
    char buffer[256];
    printf("Contents of the file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    const char *filename = "example_a+.txt";
    appendReadExample(filename);
    return 0;
}
