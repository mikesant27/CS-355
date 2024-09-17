#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main( void ){
    DIR* dirp;
    struct dirent* direntp;
    dirp = opendir( "C:/Users/Michael/Downloads/CCSU/Spring 2024/CS 355/C Files" ); // Current Directory and create a pointer to it
    if( dirp != NULL ) {                                                            // If the directory exists
        while(dirp) {
            direntp = readdir( dirp );                                              // Read the current directory
            if( direntp == NULL ) break;                                            // Check if directory is null
            printf( "%s\n", direntp->d_name );                                      // Print the file name
        }
closedir( dirp );                                                                   // Close the Directory
}
}