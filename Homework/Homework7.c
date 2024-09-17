// Michael Santoro
// CS 355
// Homework 7

#include <stdio.h>
#define DEVICENAME "/dev/random"
#define len 10

int main(void){
    size_t total = 0;
    char data[len];                                                     // Array to hold data
    FILE * f = fopen(DEVICENAME, "r");                                  // Open the /dev/random in read mode
    if (NULL == f)                                                      // Check if opening of file was unsuccessfull (fopen returns NULL if failed)
        fprintf(stderr, "Failed to open '%s'.\n", DEVICENAME);          // Print Error
    else {                                                              // Opening of Device File was successful
        total = fread(data, 1, sizeof(data), f);                        // Read Data into array and increment total counter (data[i] holds a random value)
        if (total==0){                                                  // Check if bytes were read (If total == 0, Then no bytes were read)
            fprintf(stderr, "Error reading from '%s'.\n", DEVICENAME);  // Print Error
            fclose(f);                                                  // Close File
        }
        for (int i=0; i<len; i++)
            printf(" %d \n", data[i]);                                  // Print elements of array
        fclose(f);                                                      // Close File
    }   
printf("Read %d bytes from '%s'.\n", total, DEVICENAME);                // Print total number of bytes read from file
}