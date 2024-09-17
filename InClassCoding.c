#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

void main(void) {
    int f_d = 0;
    struct stat st;
    f_d = open("./Homework4.c",O_RDONLY);                // Open the File
    if(-1 == f_d) printf("\n NULL File descriptor\n");   // If File is null/doesnt exist
        errno = 0;                                       // Set errno to 0
    if(fstat(f_d, &st)){                                 // If fstat returns 0, then there was an error 
        printf("\nfstat error: [%s]\n",strerror(errno)); // Print the Error
        close(f_d);                                      // Close the file
    }
    printf("\n The userID and the GroupID of the owner of the file are [%d] and [%d] respectively \n",(int)st.st_uid, (int)st.st_gid); // 
    close(f_d);                                          // Close the file
}