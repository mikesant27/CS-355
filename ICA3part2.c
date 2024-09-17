#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void show_stat_info(char *, struct stat *);

int main(int ac, char *av[]){
    struct stat info; // Buffer for File Info

    if(ac > 1){ // Checks to see if enough arguments are given
        if(stat(av[1],&info) != -1){ // Check to see if directory given is valid
            show_stat_info(av[1], &info); // Print File Info
            return 0;
        }
        else
            perror(av[1]); // Report stat() errors
        return 1;
    }
}
void show_stat_info(char *fname, struct stat *buf){
    printf("   mode: %o\n",buf->st_mode);   // Type + Mode
    printf("  links: %d\n",buf->st_nlink);  // # Links
    printf("   user: %d\n",buf->st_uid);    // User ID
    printf("  group: %d\n",buf->st_gid);    // Group ID
    printf("   size: %d\n",buf->st_size);   // File Size
    printf("modtime: %d\n",buf->st_mtime);  // Modified
    printf("   name: %s\n",fname);          // File Name
}