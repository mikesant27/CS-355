#include <stdio.h>
#include <dirent.h>
int main(){
    DIR *folder;                            // to work with a folder/directory
    struct dirent *entry;                   // to work with each file in the directory
    int files = 0;                          // to keep track of number of files
    folder = opendir("..");                 // Opens Parent Directory
    if(folder == NULL){                     // Check to make sure directory is valid and has stuff in it
        perror("Unable to read directory"); // Print error if the parent is null
    return(1);
    }

    while( (entry=readdir(folder)) ) {      // Iterate Through Files in parent directory
        files++;                            // Increment Files counter
        printf("File %3d: %s\n", files, entry->d_name); // Print File Name
    }
    closedir(folder);                       // Close Directory
    return(0);
}