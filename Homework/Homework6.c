// Michael Santoro
// CS 355
// Homework 6

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Not Enough/Too Many Arguments Passed/n Correct Syntax: ./Homework6 fileName openMode");
        return 1;
    }

    char *file = argv[1];           // File we want to get inode of is in argv[1]
    int openMode = atoi(argv[2]);   // Open mode for file is in argv[2]

    int fd, inode;
    fd = open(file, openMode);      // Open the File
    if (fd == -1) {                 // If fd == -1, then the file did not open successfully 
        perror("Error opening the file");
        return 1;
    }

    struct stat fileStat;
    int stat;
    stat = fstat(fd, &fileStat);
    if (stat == -1) {               // If stat == -1, then the stats for the file were not successfully stored in stat
        perror("Error getting file stat");
        return 1;
    }

    inode = fileStat.st_ino;                                  // Get the file's inode number and store it in inode

    printf("Inode number of the file: %ld\n", (long)inode);   // Display the inode number of the file

    close(fd);                                                // Close the File

    return 0;
}
