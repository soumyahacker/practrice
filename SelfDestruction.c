#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For readlink and unlink functions
#include <limits.h>  // For PATH_MAX
#include <string.h>  // For snprintf

// Define PATH_MAX if it's not defined
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "This is a test file.\n");
    fclose(file);
    printf("File '%s' created and written to successfully.\n", filename);
}

int main() {
    const char *filename = "example.txt";

    // Step 1: Create and write to a file
    createFile(filename);

    // Step 2: Get the path of the currently running executable
    char executablePath[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", executablePath, sizeof(executablePath) - 1);
    if (len == -1) {
        perror("Error getting executable path");
        exit(EXIT_FAILURE);
    }
    executablePath[len] = '\0';

    printf("Executable path: %s\n", executablePath);

    // Step 3: Schedule self-deletion
    char deleteCommand[PATH_MAX + 10];
    snprintf(deleteCommand, sizeof(deleteCommand), "rm -f %s &", executablePath);

    if (system(deleteCommand) == 0) {
        printf("Program '%s' will delete itself.\n", executablePath);
    } else {
        perror("Error scheduling program for deletion");
    }

    return 0;
}
