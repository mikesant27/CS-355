// Michael Santoro
// CS 355
// Homework4

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main() {
    int file_descriptor;
    struct utmp currentRecord;

    int length = sizeof(struct utmp);
    file_descriptor = open(UTMP_FILE, O_RDONLY);                              // Open the UTMP File and put it into the file descriptor
    if (file_descriptor == -1) {                                              // Check to make sure the UTMP file was opened and put into the file descriptor successfully
        printf("Error Opening UTMP File!\n");
        return 1;
    }
    while (read(file_descriptor, &currentRecord, length) > 0) {
        struct tm *timeInfo;
    
        time_t time = currentRecord.ut_tv.tv_sec;                             // Get the time from record
        timeInfo = localtime(&time);                                          // Use the computer's local time for timestamp
        char timeFormat[20];                                                  // Holds timestamp as string
        strftime(timeFormat, sizeof(timeFormat), "%Y-%m-%d %H:%M", timeInfo); // Change format to year, month, day, hours, minutes and store in timeFormat

        printf("%-8s %-12s %s (%s)\n", currentRecord.ut_user, currentRecord.ut_line, timeFormat, currentRecord.ut_host); // Print the Current Record
    }
    close(file_descriptor);                                                   // Close the file descriptor after reading and printing all the records
}