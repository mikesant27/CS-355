// Michael Santoro
// CS 355
// Homework 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

// Sort files in lexicographical order
int sortLexico(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Sort files in reverse lexicographical order
int sortRevLexico(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

int main(int argc, char *argv[]) {
    bool listHidden = false;     // Variable to tell if we should list hidden files
    bool sort = false;           // Variable to tell if we should sort the files
    bool reverseSort = false;    // Variable to tell if we should do reverse sorting
    char *currentDir = ".";      // Pointer to current directory
                                 
    // Parse arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {                         // If user added a '-' for extra arguments such as -a, -s, or -r
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if (argv[i][j] == 'a') {                 // Display Names of Hidden Files
                    listHidden = true;
                } else if (argv[i][j] == 's') {          // Display File Names in Lexicographical Order
                    sort = true;
                } else if (argv[i][j] == 'r') {          // Display File Names in Reverse Lexicographical Order
                    reverseSort = true;
                }
            }
        } else {
            currentDir = argv[i];
        }
    }

    DIR *dir = opendir(currentDir);                               // Open directory
    if (dir == NULL) {                                            // If the pointer is NULL, then the directory was not opened successfully
        printf("Error Opening Directory\n");                        // Print Error to User
        return 1;
    }

    struct dirent *currentFile;                                  // Pointer to Current File in Directory
    char *files[1000];                                           // Array of Strings to Store File Names
    int numFiles = 0;

    // Read the directory and collect filenames
    while ((currentFile = readdir(dir)) != NULL) {
        if (!listHidden && currentFile->d_name[0] == '.')        // Skip hidden files if the listHidden is false
            continue;
        files[numFiles] = strdup(currentFile->d_name);           // Add File to Array
        numFiles++;                                              // Increate numFiles Counter
    }

    closedir(dir);                                               // Close the directory

    // Sort the filenames if the sort is true
    if (sort) {
        if (reverseSort) {                                       // Sort in Reverse Lexicographical Order
            qsort(files, numFiles, sizeof(char *), sortRevLexico);
        } else {                                                 // Sort in Lexicographical Order
            qsort(files, numFiles, sizeof(char *), sortLexico);
        }
    }

    // Print Filenames
    for (int i = 0; i < numFiles; i++) {
        printf("%s\n", files[i]);
    }

    return 0;
}